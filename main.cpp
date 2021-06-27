/************************************
*                                   *
*         Name: Paul Koreng         *
*       Matrikelnummer: 49224       *
*      Studiengruppe: 20/041/02     *
*                                   *
************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstring>
#include <algorithm>
using namespace std;
#include "./Klassen/person.h"
#include "./Klassen/date.h"
#include "./Klassen/liste.h"
#include "./Klassen/Medien/medium.h"
#include "./Klassen/Medien/buch.h"
#include "./Klassen/Medien/cd.h"
#include "./Klassen/Medien/dvd.h"

/*
TODO:
Alles Leerzeichen bei Strings durch '_' umtauschen + reverse
Funktionen verleih, rueckgabe


Verwaltung der Personen (erfassen, anzeigen, auflisten, löschen ...)
Verwaltung der Medien(s.o.)

überschriebene couts für Klassen schreiben

*/

// Globale Variablen
Liste<Person> pListe;
Liste<Buch> bListe;
Liste<CD> cListe;
Liste<DVD> dListe;

string pD, mD;
bool fileLoaded = false, fileSaved = false;

void addPerson(string pid, string vorname, string nachname, string geschlecht, int jahr, int monat, int tag) {
  Person tempPerson(pid, vorname, nachname, geschlecht, jahr, monat, tag);
  pListe.addElement(tempPerson);
}

void addMedium(string id, string titel, int jahrA, int monatA, int tagA, int jahrR, int monatR, int tagR, bool ausleihStatus, string ausleiher, string autor, string verlag, int seitenanzahl) {
  Buch tempBuch(id, titel, jahrA, monatA, tagA, jahrR, monatR, tagR, ausleihStatus, ausleiher, autor, verlag, seitenanzahl);
  bListe.addElement(tempBuch);
}

void addMedium(string id, string titel, int jahrA, int monatA, int tagA, int jahrR, int monatR, int tagR, bool ausleihStatus, string ausleiher, int dauer) {
  CD tempCD(id, titel, jahrA, monatA, tagA, jahrR, monatR, tagR, ausleihStatus, ausleiher, dauer);
  cListe.addElement(tempCD);
}

void addMedium(string id, string titel, int jahrA, int monatA, int tagA, int jahrR, int monatR, int tagR, bool ausleihStatus, string ausleiher, int fsk, int dauer, string genre) {
  DVD tempDVD(id, titel, jahrA, monatA, tagA, jahrR, monatR, tagR, ausleihStatus, ausleiher, fsk, dauer, genre);
  dListe.addElement(tempDVD);
}

bool fileToListe() {
  // Objektbezogene Variablen
  string jahr1, monat1, tag1, jahr2, monat2, tag2;
  string pid, vorname, nachname, geschlecht;
  string id, titel, ausleiher, autor, verlag, seitenanzahl, dauer, fsk, genre;
  bool ausleihStatus;
  // Dateiarbeit Variablen
  ifstream file;
  string line, c;

  // Personen-Daten einlesen
  file.open(pD);

  if(file.fail()) {
    cout << "<!> Datei '" << pD << "' konnte nicht geoeffnet werden. Abbruch. <!>" << endl;
    return false;
  }

  istringstream my_stream;

  while (getline(file,line)) {
    my_stream.str(line);
    my_stream >> pid >> vorname >> nachname >> geschlecht >> jahr1 >> monat1 >> tag1 >> c;
    addPerson(pid, vorname, nachname, geschlecht, stoi(jahr1), stoi(monat1), stoi(tag1));
    my_stream.clear();
  }

  file.close();

  // Medien-Daten einlesen
  file.open(mD);

  if(file.fail()) {
    cout << "<!> Datei '" << mD << "' konnte nicht geoeffnet werden. Abbruch. <!>" << endl;
    return false;
  }

  while (getline(file,line)) {
    my_stream.str(line);
    my_stream >> id >> c;
    my_stream.clear();

    switch (id.at(0)) {
      case 'B':
      {
        my_stream.str(line);
        my_stream >> id >> titel >> jahr1 >> monat1 >> tag1 >> jahr2 >> monat2 >> tag2 >> ausleihStatus >> ausleiher >> autor >> verlag >> seitenanzahl >> c;
        addMedium(id, titel, stoi(jahr1), stoi(monat1), stoi(tag1), stoi(jahr2), stoi(monat2), stoi(tag2), ausleihStatus, ausleiher, autor, verlag, stoi(seitenanzahl));
        my_stream.clear();
      }
      break;
      case 'C':
      {
        my_stream.str(line);
        my_stream >> id >> titel >> jahr1 >> monat1 >> tag1 >> jahr2 >> monat2 >> tag2 >> ausleihStatus >> ausleiher >> dauer >> c;
        addMedium(id, titel, stoi(jahr1), stoi(monat1), stoi(tag1), stoi(jahr2), stoi(monat2), stoi(tag2), ausleihStatus, ausleiher, stoi(dauer));
        my_stream.clear();
      }
      break;
      case 'D':
      {
        my_stream.str(line);
        my_stream >> id >> titel >> jahr1 >> monat1 >> tag1 >> jahr2 >> monat2 >> tag2 >> ausleihStatus >> ausleiher >> fsk >> dauer >> genre >> c;
        addMedium(id, titel, stoi(jahr1), stoi(monat1), stoi(tag1), stoi(jahr2), stoi(monat2), stoi(tag2), ausleihStatus, ausleiher, stoi(fsk), stoi(dauer), genre);
        my_stream.clear();
      }
      break;
      default:
        cout << "Kein gueltiger Typ." << endl;
    }
  }
  return true;
}

bool listeToFile() {
  ofstream file;
  file.open(pD);

  if(file.fail()) {
    cout << "<!> Datei '" << pD << "' konnte nicht geoeffnet werden. Abbruch. <!>" << endl;
    return false;
  }

  file.seekp(0);

  for (int i = 0; i < pListe.getSize(); i++) {
    file << pListe[i].getPID() << " " << pListe[i].getVorname() << " " << pListe[i].getNachname() << " " << pListe[i].getGeschlecht() << " " << pListe[i].getGeburtsdatum().getJahr() << " " << pListe[i].getGeburtsdatum().getMonat() << " " << pListe[i].getGeburtsdatum().getTag() << endl;
  }
  file.close();

  file.open(mD);

  if(file.fail()) {
    cout << "<!> Datei '" << mD << "' konnte nicht geoeffnet werden. Abbruch. <!>" << endl;
    return false;
  }

  file.seekp(0);

  for (int i = 0; i < bListe.getSize(); i++) {
    file << bListe[i].getID() << " " << bListe[i].getTitel() << " " << bListe[i].getAusleihDatum().getJahr() << " " << bListe[i].getAusleihDatum().getMonat() << " " << bListe[i].getAusleihDatum().getTag() << " " << bListe[i].getRueckgabeDatum().getJahr() << " " << bListe[i].getRueckgabeDatum().getMonat() << " " << bListe[i].getRueckgabeDatum().getTag() << " " << bListe[i].getAusleihStatus() << " " << bListe[i].getAusleiher() << " " << bListe[i].getAutor() << " " << bListe[i].getVerlag() << " " << bListe[i].getSeitenanzahl() << endl;
  }

  for (int i = 0; i < cListe.getSize(); i++) {
    file << cListe[i].getID() << " " << cListe[i].getTitel() << " " << cListe[i].getAusleihDatum().getJahr() << " " << cListe[i].getAusleihDatum().getMonat() << " " << cListe[i].getAusleihDatum().getTag() << " " << cListe[i].getRueckgabeDatum().getJahr() << " " << cListe[i].getRueckgabeDatum().getMonat() << " " << cListe[i].getRueckgabeDatum().getTag() << " " << cListe[i].getAusleihStatus() << " " << cListe[i].getAusleiher() << " " << cListe[i].getDauer() << endl;
  }

  for (int i = 0; i < dListe.getSize(); i++) {
    file << dListe[i].getID() << " " << dListe[i].getTitel() << " " << dListe[i].getAusleihDatum().getJahr() << " " << dListe[i].getAusleihDatum().getMonat() << " " << dListe[i].getAusleihDatum().getTag() << " " << dListe[i].getRueckgabeDatum().getJahr() << " " << dListe[i].getRueckgabeDatum().getMonat() << " " << dListe[i].getRueckgabeDatum().getTag() << " " << dListe[i].getAusleihStatus() << " " << dListe[i].getAusleiher() << " " << dListe[i].getFSK() << " " << dListe[i].getDauer() << " " << dListe[i].getGenre() << endl;
  }

  file.close();
  return true;
}

bool aus_rueckgabe(char c, string id, string pid) {
  int val;
  bool test_val;
  if(c == 'a') {
    test_val = 1;
  }
  if(c == 'r') {
    test_val = 0;
  }
  switch (id.at(0)) {
    case 'B':
      for (int i = 0; i < bListe.getSize(); i++) {
        if(bListe[i].getID() == id) {
          val = i;
          break;
        }
      }
      if (bListe[val].getAusleihStatus() == test_val) {
        return false;
      } else {
        if (c == 'r') {
          bListe[val].setAusleiher("0");
        }
        else {
          bListe[val].setAusleiher(pid);
        }
        bListe[val].setAusleihStatus(test_val);
        return true;
      }
    break;
    case 'C':
      for (int i = 0; i < cListe.getSize(); i++) {
        if(cListe[i].getID() == id) {
          val = i;
          break;
        }
      }
      if (cListe[val].getAusleihStatus() == test_val) {
        return false;
      } else {
        if (c == 'r') {
          cListe[val].setAusleiher("0");
        } else {
          cListe[val].setAusleiher(pid);
        }
        cListe[val].setAusleihStatus(test_val);
        return true;
      }
    break;
    case 'D':
      for (int i = 0; i < dListe.getSize(); i++) {
        if(dListe[i].getID() == id) {
          val = i;
          break;
        }
      }
      if (dListe[val].getAusleihStatus() == test_val) {
        return false;
      } else {
        if (c == 'r') {
          dListe[val].setAusleiher("0");
        } else {
          dListe[val].setAusleiher(pid);
        }
        dListe[val].setAusleihStatus(test_val);
        return true;
      }
    break;
    default:
      return false;
  }
}

string setFile() {
  string filename;
  fstream file;

  getline(cin, filename);
  file.open(filename);

  if(file.fail()) {
    file.close();
    file.open(filename, ios::out);
    if(!file) {
      cout << "<!> Datei '" << filename << "' konnte nicht erstellt werden. Abbruch. <!>" << endl;
      return "";
    } else {
      cout << "<I> Datei '" << filename << "' wurde erstellt. <I>" << endl;
    }
  } else {
    file.close();
  }

  return filename;
}

string replaceAll(string s, char a, char b) {
  replace(s.begin(),s.end(), a, b);
  return s;
}

bool loadFile() {
  cout << "<?> Datei(pfad) zur Verwaltung der Personen: <?>" << endl;
  pD = setFile();
  cout << "<?> Datei(pfad) zur Verwaltung der Medien: <?>" << endl;
  mD = setFile();

  if (fileLoaded) {
    pListe.clear();
    bListe.clear();
    cListe.clear();
    dListe.clear();
  }
  if(pD == mD) {
    cout << "<!> Dateien dürfen nicht den selben Dateinamen haben. Abbruch. <!>" << endl;
    return false;
  } else if((pD != "") && (mD != "")) {
    fileToListe();
    cout << "<I> Dateien wurden in Liste geladen. <I>" << endl;
    return true;
  } else {
    cout << "<!> Fehler beim erstellen der Dateien. Versuchen sie den Vorgang zu wiederholen. <!>" << endl;
    return false;
  }
}

bool saveFile() {
  string answer;

  cout << "<?> Wollen sie die Daten aus den Listen in die gleichen Dateien schreiben aus den gelesen wurde? (j/n) <?>" << endl;
  getline(cin, answer);
  if (answer == "j") {
    listeToFile();
    cout << "<I> Listen wurden in Dateien gespeichert. <I>" << endl;
    return true;
  } else if (answer == "n") {
    return true;
  } else {
    cout << "<!> Keine gültige Antwort. Versuchen sie den Vorgang zu wiederholen. <!>" << endl;
    return false;
  }
}

void list() {
  string answer;

  cout << "<?> Welche Liste möchten sie ausgeben? ([p]erson, [b]uch, [c]d, [d]vd) <?>" << endl;
  getline(cin, answer);

  if ((answer == "p") || (answer == "person" )) {
    for(int i = 0; i < pListe.getSize(); i++) {
      cout << i+1 << ": " << pListe[i] << endl;
    }
  } else if ((answer == "b") || (answer == "buch" )) {
    for(int i = 0; i < bListe.getSize(); i++) {
      cout << i+1 << ": " << bListe[i] << endl;
    }
  } else if ((answer == "c") || (answer == "cd" )) {
    for(int i = 0; i < cListe.getSize(); i++) {
      cout << i+1 << ": " << cListe[i] << endl;
    }
  } else if ((answer == "d") || (answer == "dvd" )) {
    for(int i = 0; i < dListe.getSize(); i++) {
      cout << i+1 << ": " << dListe[i] << endl;
    }
  } else {
    cout << "<!> '" << answer << "' ist kein gültiger Parameter. Versuchen sie den Vorgang zu wiederholen. <!>" << endl;
  }
}

void search() {
  string answer, searchArgument;
  int foundArguments = 0;

  cout << "<?> In welcher Liste möchten sie suchen? ([p]erson, [b]uch, [c]d, [d]vd) <?>" << endl;
  getline(cin, answer);
  cout << "<?> Geben sie den Begriff ein nach dem sie suchen möchten. <?>" << endl;
  getline(cin, searchArgument);

  searchArgument = replaceAll(searchArgument, ' ', '_');

  if ((answer == "p") || (answer == "person" )) {
    for(int i = 0; i < pListe.getSize(); i++) {
      if ((pListe[i].getPID() == searchArgument) ||  (pListe[i].getVorname() == searchArgument) || (pListe[i].getNachname() == searchArgument)) {
        cout << foundArguments+1 << ": " << pListe[i] << endl;
        foundArguments++;
      }
    }
  } else if ((answer == "b") || (answer == "buch" )) {
    for(int i = 0; i < bListe.getSize(); i++) {
      if ((bListe[i].getID() == searchArgument) ||  (bListe[i].getTitel() == searchArgument) || (bListe[i].getAusleiher() == searchArgument) || (bListe[i].getAutor() == searchArgument) || (bListe[i].getVerlag() == searchArgument) || (to_string(bListe[i].getSeitenanzahl()) == searchArgument) || (bListe[i].getAusleihDatum().dateToString() == searchArgument) || (bListe[i].getRueckgabeDatum().dateToString() == searchArgument)) {
        cout << foundArguments+1 << ": " << bListe[i] << endl;
        foundArguments++;
      }
    }
  } else if ((answer == "c") || (answer == "cd" )) {
    for(int i = 0; i < cListe.getSize(); i++) {
      if ((cListe[i].getID() == searchArgument) ||  (cListe[i].getTitel() == searchArgument) || (cListe[i].getAusleiher() == searchArgument) || (to_string(cListe[i].getDauer()) == searchArgument) || (cListe[i].getAusleihDatum().dateToString() == searchArgument) || (cListe[i].getRueckgabeDatum().dateToString() == searchArgument)) {
        cout << foundArguments+1 << ": " << cListe[i] << endl;
        foundArguments++;
      }
    }
  } else if ((answer == "d") || (answer == "dvd" )) {
    for(int i = 0; i < dListe.getSize(); i++) {
      if ((dListe[i].getID() == searchArgument) ||  (dListe[i].getTitel() == searchArgument) || (dListe[i].getAusleiher() == searchArgument) || (to_string(dListe[i].getFSK()) == searchArgument) || (to_string(dListe[i].getDauer()) == searchArgument) || (dListe[i].getGenre() == searchArgument) || (dListe[i].getAusleihDatum().dateToString() == searchArgument) || (dListe[i].getRueckgabeDatum().dateToString() == searchArgument)) {
        cout << foundArguments+1 << ": " << dListe[i] << endl;
        foundArguments++;
      }
    }
  } else {
    cout << "<!> '" << answer << "' ist kein gültiger Parameter. Versuchen sie den Vorgang zu wiederholen. <!>" << endl;
  }
  if (foundArguments == 0) {
    cout << "<!> '" << searchArgument << "' wurde nicht gefunden. <!>" << endl;
  }

}

void help() {
  cout << "'h'\t- Auflistung aller Argumente und den zugehörigen Funktionen." << endl;
  cout << "'q'\t- Beendet das Programm." << endl;
  cout << "'of'\t- Öffnet Dateien und lädt die Daten in die entsprechenden Listen." << endl;
  cout << "'sf'\t- Speichert die Daten aus den Listen in die entsprechenden Dateien." << endl;
  cout << "'l'\t- Listet alle Elemente aus der entsprechenden Liste auf." << endl;
  cout << "'n'\t- Erstellt ein neues Element und fügt es der entsprechenden Liste hinzu." << endl;
  cout << "'d'\t- Löscht ein Element aus entsprechenden Liste." << endl;
  cout << "'s'\t- Sucht ein Element in entsprechenden Liste und gibt es aus falls es gefunden wurde." << endl;
  cout << "'a'\t- Zum Verleih von Medien." << endl;
  cout << "'r'\t- Zur Rückgabe von Medien." << endl;
  cout << "<I>\t- Kennzeichnet Informationen. Gibt ihnen ggf. auch bestätigung, dass etwas funktioniert hat." << endl;
  cout << "<?>\t- Kennzeichnet eine Abfrage. Wartet auf ihre Eingabe." << endl;
  cout << "<!>\t- Kennzeichnet ein Problem. Gibt ihnen Information darüber, dass etwas nicht funktioniert hat." << endl;
}

bool quit() {
  string answer;

  if (fileLoaded && (fileSaved == false)) {
    cout << "<?> Wollen sie ihre Änderungen speichern? (j/n) <?>" << endl;
    getline(cin, answer);
    if (answer == "j") {
      fileSaved = saveFile();
    }
  }
  cout << "<I> Das Programm wird nun beendet. <I>" << endl;
  return false;
}

int main() {
  // Compiler-Command
  //g++ main.cpp Klassen/person.cpp Klassen/date.cpp Klassen/Medien/medium.cpp Klassen/Medien/buch.cpp Klassen/Medien/cd.cpp Klassen/Medien/dvd.cpp

  bool running = true;
  string argument;

  cout << R"(.________________________________.
|                                |
|          C++ Programm          |
|        Medienverwaltung        |
|             V1.0.0             |
|________________________________|
)" << endl;

  cout << "<I> Geben sie 'h' ein für eine Liste aller Funktionen, ihrer funktionsweise und den dazugehörigen Parametern. <I>" << endl;

  while (running) {
    getline(cin, argument);

    if(argument == "h") {
      help();
    } else if(argument == "q") {
      running = quit();
    } else if(argument == "of") {
      fileLoaded = loadFile();
    } else if(argument == "sf") {
      if (fileLoaded) {
        fileSaved = saveFile();
      } else {
        cout << "<!> Dateien sind nicht in die Listen geladen. Bitte nutzen sie 'of' dazu. <!>" << endl;
      }
    } else if(argument == "l") {
      if (fileLoaded) {
        list();
      } else {
        cout << "<!> Dateien sind nicht in die Listen geladen. Bitte nutzen sie 'of' dazu. <!>" << endl;
      }
    } else if(argument == "n") {
      if (fileLoaded) {

      } else {
        cout << "<!> Dateien sind nicht in die Listen geladen. Bitte nutzen sie 'of' dazu. <!>" << endl;
      }
    } else if(argument == "d") {
      if (fileLoaded) {

      } else {
        cout << "<!> Dateien sind nicht in die Listen geladen. Bitte nutzen sie 'of' dazu. <!>" << endl;
      }
    } else if(argument == "s") {
      if (fileLoaded) {
        search();
      } else {
        cout << "<!> Dateien sind nicht in die Listen geladen. Bitte nutzen sie 'of' dazu. <!>" << endl;
      }
    } else if(argument == "a") {
      if (fileLoaded) {

      } else {
        cout << "<!> Dateien sind nicht in die Listen geladen. Bitte nutzen sie 'of' dazu. <!>" << endl;
      }
    } else if(argument == "r") {
      if (fileLoaded) {

      } else {
        cout << "<!> Dateien sind nicht in die Listen geladen. Bitte nutzen sie 'of' dazu. <!>" << endl;
      }
    } else {
      cout << "<!> Das Argument '" << argument << "' ist kein gültiges Argument, für eine Liste aller Argumente und der zugehörigen Parameter nutzen sie 'h'. <!>" << endl;
    }
  }
  return 0;
}
