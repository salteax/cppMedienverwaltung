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

void addPerson(string pid, string vorname, string nachname) {
  Person tempPerson(pid, vorname, nachname);
  pListe.addElement(tempPerson);
}

void addMedium(string id, string titel, bool ausleihStatus, string ausleiher, string autor, string verlag, int seitenanzahl) {
  Buch tempBuch(id, titel, ausleihStatus, ausleiher, autor, verlag, seitenanzahl);
  bListe.addElement(tempBuch);
}

void addMedium(string id, string titel, bool ausleihStatus, string ausleiher, int dauer) {
  CD tempCD(id, titel, ausleihStatus, ausleiher, dauer);
  cListe.addElement(tempCD);
}

void addMedium(string id, string titel, bool ausleihStatus, string ausleiher, int fsk, int dauer, string genre) {
  DVD tempDVD(id, titel, ausleihStatus, ausleiher, fsk, dauer, genre);
  dListe.addElement(tempDVD);
}

bool fileToListe() {
  // Objektbezogene Variablen
  string pid, vorname, nachname;
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
    my_stream >> pid >> vorname >> nachname >> c;
    addPerson(pid, vorname, nachname);
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
        my_stream >> id >> titel >> ausleihStatus >> ausleiher >> autor >> verlag >> seitenanzahl >> c;
        addMedium(id, titel, ausleihStatus, ausleiher, autor, verlag, stoi(seitenanzahl));
        my_stream.clear();
      }
      break;
      case 'C':
      {
        my_stream.str(line);
        my_stream >> id >> titel >> ausleihStatus >> ausleiher >> dauer >> c;
        addMedium(id, titel, ausleihStatus, ausleiher, stoi(dauer));
        my_stream.clear();
      }
      break;
      case 'D':
      {
        my_stream.str(line);
        my_stream >> id >> titel >> ausleihStatus >> ausleiher >> fsk >> dauer >> genre >> c;
        addMedium(id, titel, ausleihStatus, ausleiher, stoi(fsk), stoi(dauer), genre);
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
    file << pListe[i].getPID() << " " << pListe[i].getVorname() << " " << pListe[i].getNachname() << endl;
  }
  file.close();

  file.open(mD);

  if(file.fail()) {
    cout << "<!> Datei '" << mD << "' konnte nicht geoeffnet werden. Abbruch. <!>" << endl;
    return false;
  }

  file.seekp(0);

  for (int i = 0; i < bListe.getSize(); i++) {
    file << bListe[i].getID() << " " << bListe[i].getTitel() << " " << bListe[i].getAusleihStatus() << " " << bListe[i].getAusleiher() << " " << bListe[i].getAutor() << " " << bListe[i].getVerlag() << " " << bListe[i].getSeitenanzahl() << endl;
  }

  for (int i = 0; i < cListe.getSize(); i++) {
    file << cListe[i].getID() << " " << cListe[i].getTitel() << " " << cListe[i].getAusleihStatus() << " " << cListe[i].getAusleiher() << " " << cListe[i].getDauer() << endl;
  }

  for (int i = 0; i < dListe.getSize(); i++) {
    file << dListe[i].getID() << " " << dListe[i].getTitel() << " " << dListe[i].getAusleihStatus() << " " << dListe[i].getAusleiher() << " " << dListe[i].getFSK() << " " << dListe[i].getDauer() << " " << dListe[i].getGenre() << endl;
  }

  file.close();
  return true;
}

bool verleih(char c, string id, string pid) {
  int index = -1;
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
          index = i;
          break;
        }
      }
      if ((bListe[index].getAusleihStatus() == test_val) || (index == -1)) {
        return false;
      } else {
        if (c == 'r') {
          bListe[index].setAusleiher("0");
        }
        else {
          bListe[index].setAusleiher(pid);
        }
        bListe[index].setAusleihStatus(test_val);
        return true;
      }
    break;
    case 'C':
      for (int i = 0; i < cListe.getSize(); i++) {
        if(cListe[i].getID() == id) {
          index = i;
          break;
        }
      }
      if ((cListe[index].getAusleihStatus()) == test_val || (index == -1)) {
        return false;
      } else {
        if (c == 'r') {
          cListe[index].setAusleiher("0");
        } else {
          cListe[index].setAusleiher(pid);
        }
        cListe[index].setAusleihStatus(test_val);
        return true;
      }
    break;
    case 'D':
      for (int i = 0; i < dListe.getSize(); i++) {
        if(dListe[i].getID() == id) {
          index = i;
          break;
        }
      }
      if ((dListe[index].getAusleihStatus()) == test_val || (index == -1)) {
        return false;
      } else {
        if (c == 'r') {
          dListe[index].setAusleiher("0");
        } else {
          dListe[index].setAusleiher(pid);
        }
        dListe[index].setAusleihStatus(test_val);
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

bool pid_exists(string pid) {
  for(int i = 0; i < pListe.getSize(); i++) {
    if (pListe[i].getPID() == pid) {
      return true;
    }
  }
  return false;
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
    cout << "<I> Liste aller Personen. <I>" << endl;
  } else if ((answer == "b") || (answer == "buch" )) {
    for(int i = 0; i < bListe.getSize(); i++) {
      cout << i+1 << ": " << bListe[i] << endl;
    }
    cout << "<I> Liste aller Bücher. <I>" << endl;
  } else if ((answer == "c") || (answer == "cd" )) {
    for(int i = 0; i < cListe.getSize(); i++) {
      cout << i+1 << ": " << cListe[i] << endl;
    }
    cout << "<I> Liste aller CDs. <I>" << endl;
  } else if ((answer == "d") || (answer == "dvd" )) {
    for(int i = 0; i < dListe.getSize(); i++) {
      cout << i+1 << ": " << dListe[i] << endl;
    }
    cout << "<I> Liste aller DVDs. <I>" << endl;
  } else {
    cout << "<!> '" << answer << "' ist kein gültiger Parameter. Versuchen sie den Vorgang zu wiederholen. <!>" << endl;
  }
}

void newEntry() {
  string answer;

  cout << "<?> In welcher Liste möchten sie ein Eintrag hinzufügen? ([p]erson, [b]uch, [c]d, [d]vd) <?>" << endl;
  getline(cin, answer);

  if ((answer == "p") || (answer == "person")) {
    string pid, vorname, nachname;
    cout << "<?> Vorname: <?>" << endl;
    getline(cin, pid);
    cout << "<?> Nachname: <?>" << endl;
    getline(cin, pid);
    cout << "<?> Nachname: <?>" << endl;
    getline(cin, pid);
  } else if (answer == "b" || answer == "buch" || answer == "c" || answer == "cd" || answer == "d" || answer == "dvd") {
    /* code */
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
      if ((bListe[i].getID() == searchArgument) ||  (bListe[i].getTitel() == searchArgument) || (bListe[i].getAusleiher() == searchArgument) || (bListe[i].getAutor() == searchArgument) || (bListe[i].getVerlag() == searchArgument) || (to_string(bListe[i].getSeitenanzahl()) == searchArgument)) {
        cout << foundArguments+1 << ": " << bListe[i] << endl;
        foundArguments++;
      }
    }
  } else if ((answer == "c") || (answer == "cd" )) {
    for(int i = 0; i < cListe.getSize(); i++) {
      if ((cListe[i].getID() == searchArgument) ||  (cListe[i].getTitel() == searchArgument) || (cListe[i].getAusleiher() == searchArgument) || (to_string(cListe[i].getDauer()) == searchArgument)) {
        cout << foundArguments+1 << ": " << cListe[i] << endl;
        foundArguments++;
      }
    }
  } else if ((answer == "d") || (answer == "dvd" )) {
    for(int i = 0; i < dListe.getSize(); i++) {
      if ((dListe[i].getID() == searchArgument) ||  (dListe[i].getTitel() == searchArgument) || (dListe[i].getAusleiher() == searchArgument) || (to_string(dListe[i].getFSK()) == searchArgument) || (to_string(dListe[i].getDauer()) == searchArgument) || (dListe[i].getGenre() == searchArgument)) {
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

void ausleih() {
  string pid, mid;

  cout << "<?> PID der Person welche das Medium ausleihen möchte: <?>" << endl;
  getline(cin, pid);
  if (pid_exists(pid)) {
    cout << "<?> ID des Mediums welches ausgeliehen werden möchte: <?>" << endl;
    getline(cin, mid);
    if (verleih('a', mid, pid)) {
      cout << "<I> Medium mit der ID '" << mid << "' wurde an die Person mit der PID '" << pid << "' verliehen. <I>" << endl;
    } else {
      cout << "<!> Medium mit der ID '" << mid << "' ist bereits ausgeliehen oder existiert nicht. <!>" << endl;
    }
  } else {
    cout << "<!> Person mit der ID '" << pid << "' existiert nicht. <!>" << endl;
  }
}

void rueckgabe() {
  string pid, mid;

  cout << "<?> PID der Person welche das Medium zurückgeben möchte: <?>" << endl;
  getline(cin, pid);
  if (pid_exists(pid)) {
    cout << "<?> ID des Mediums welches zurückgegeben werden möchte: <?>" << endl;
    getline(cin, mid);
    if (verleih('r', mid, pid)) {
      cout << "<I> Medium mit der ID '" << mid << "' wurde von der Person mit der PID '" << pid << "' zurückgegeben. <I>" << endl;
    } else {
      cout << "<!> Medium mit der ID '" << mid << "' ist nicht ausgeliehen oder existiert nicht. <!>" << endl;
    }
  } else {
    cout << "<!> Person mit der ID '" << pid << "' existiert nicht. <!>" << endl;
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
  //prog2_beleg] $ g++ main.cpp Klassen/person.cpp Klassen/Medien/medium.cpp Klassen/Medien/buch.cpp Klassen/Medien/cd.cpp Klassen/Medien/dvd.cpp

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
        newEntry();
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
        ausleih();
      } else {
        cout << "<!> Dateien sind nicht in die Listen geladen. Bitte nutzen sie 'of' dazu. <!>" << endl;
      }
    } else if(argument == "r") {
      if (fileLoaded) {
        rueckgabe();
      } else {
        cout << "<!> Dateien sind nicht in die Listen geladen. Bitte nutzen sie 'of' dazu. <!>" << endl;
      }
    } else {
      cout << "<!> Das Argument '" << argument << "' ist kein gültiges Argument, für eine Liste aller Argumente und der zugehörigen Parameter nutzen sie 'h'. <!>" << endl;
    }
  }
  return 0;
}
