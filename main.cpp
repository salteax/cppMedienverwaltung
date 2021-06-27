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
  TODO: Auf Fehler testen, zB mit leerer Datei etc.
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

void addMedium(string id, string titel, bool ausleihStatus, string ausleiher, string autor, string verlag, string seitenanzahl) {
  Buch tempBuch(id, titel, ausleihStatus, ausleiher, autor, verlag, seitenanzahl);
  bListe.addElement(tempBuch);
}

void addMedium(string id, string titel, bool ausleihStatus, string ausleiher, string dauer) {
  CD tempCD(id, titel, ausleihStatus, ausleiher, dauer);
  cListe.addElement(tempCD);
}

void addMedium(string id, string titel, bool ausleihStatus, string ausleiher, string dauer, string genre) {
  DVD tempDVD(id, titel, ausleihStatus, ausleiher, dauer, genre);
  dListe.addElement(tempDVD);
}

bool fileToListe() {
  // Objektbezogene Variablen
  string pid, vorname, nachname;
  string id, titel, ausleiher, autor, verlag, seitenanzahl, dauer, genre;
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
        addMedium(id, titel, ausleihStatus, ausleiher, autor, verlag, seitenanzahl);
        my_stream.clear();
      }
      break;
      case 'C':
      {
        my_stream.str(line);
        my_stream >> id >> titel >> ausleihStatus >> ausleiher >> dauer >> c;
        addMedium(id, titel, ausleihStatus, ausleiher, dauer);
        my_stream.clear();
      }
      break;
      case 'D':
      {
        my_stream.str(line);
        my_stream >> id >> titel >> ausleihStatus >> ausleiher >> dauer >> genre >> c;
        addMedium(id, titel, ausleihStatus, ausleiher, dauer, genre);
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
    file << dListe[i].getID() << " " << dListe[i].getTitel() << " " << dListe[i].getAusleihStatus() << " " << dListe[i].getAusleiher() << " " << dListe[i].getDauer() << " " << dListe[i].getGenre() << endl;
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

int id_exists(string id) {
  if (id.at(0) == 'P') {
    for(int i = 0; i < pListe.getSize(); i++) {
      if(pListe[i].getPID() == id) {
        return i;
      }
    }
    return -1;
  } else if(id.at(0) == 'B') {
    for(int i = 0; i < bListe.getSize(); i++) {
      if(bListe[i].getID() == id) {
        return i;
      }
    }
    return -1;
  } else if(id.at(0) == 'C') {
    for(int i = 0; i < cListe.getSize(); i++) {
      if(cListe[i].getID() == id) {
        return i;
      }
    }
    return -1;
  } else if(id.at(0) == 'D') {
    for(int i = 0; i < dListe.getSize(); i++) {
      if(dListe[i].getID() == id) {
        return i;
      }
    }
    return -1;
  } else {
    return -1;
  }
}

string new_id(char c) {
  string new_id, identifier;
  if (c == 'p') {
    identifier = "P";
    new_id = to_string(stoi(((pListe[pListe.getSize()-1].getPID()).substr(1,3)))+1);
  } else if (c == 'b') {
    identifier = "B";
    new_id = to_string(stoi(((bListe[bListe.getSize()-1].getID()).substr(1,3)))+1);
  } else if (c == 'c') {
    identifier = "C";
    new_id = to_string(stoi(((cListe[cListe.getSize()-1].getID()).substr(1,3)))+1);
  } else if (c == 'd') {
    identifier = "D";
    new_id = to_string(stoi(((dListe[dListe.getSize()-1].getID()).substr(1,3)))+1);
  }
  if (stoi(new_id) < 10) {
    new_id = identifier + "00" + new_id;
    return new_id;
  } if ((stoi(new_id) >= 10) && (stoi(new_id) < 100)) {
    new_id = identifier + "0" + new_id;
    return new_id;
  } else {
    new_id = identifier + new_id;
    return new_id;
  }
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
  if((answer == "p") || (answer == "person")) {
    string vorname, nachname;
    cout << "<?> Vorname: <?>" << endl;
    getline(cin, vorname);
    cout << "<?> Nachname: <?>" << endl;
    getline(cin, nachname);
    addPerson(new_id('p'), replaceAll(vorname, ' ', '_'), replaceAll(nachname, ' ', '_'));
    cout << "<I> Person wurde der Liste hinzugefügt. <I>" << endl;
  } else if(answer == "b" || answer == "buch" || answer == "c" || answer == "cd" || answer == "d" || answer == "dvd") {
    string titel;
    cout << "<?> Titel: <?>" << endl;
    getline(cin, titel);
    if(answer == "b" || answer == "buch") {
      string autor, verlag, seitenanzahl;
      cout << "<?> Autor: <?>" << endl;
      getline(cin, autor);
      cout << "<?> Verlag: <?>" << endl;
      getline(cin, verlag);
      cout << "<?> Seitenanzahl: <?>" << endl;
      getline(cin, seitenanzahl);
      addMedium(new_id('b'), replaceAll(titel, ' ', '_'), 0, "0", replaceAll(autor, ' ', '_'), replaceAll(verlag, ' ', '_'), replaceAll(seitenanzahl, ' ', '_'));
      cout << "<I> Buch wurde der Liste hinzugefügt. <I>" << endl;
    } else if(answer == "c" || answer == "cd") {
      string dauer;
      cout << "<?> Dauer: <?>" << endl;
      getline(cin, dauer);
      addMedium(new_id('c'), replaceAll(titel, ' ', '_'), 0, "0", replaceAll(dauer, ' ', '_'));
      cout << "<I> CD wurde der Liste hinzugefügt. <I>" << endl;
    } else if(answer == "d" || answer == "dvd") {
      string fsk, dauer, genre;
      cout << "<?> FSK: <?>" << endl;
      getline(cin, fsk);
      cout << "<?> Dauer: <?>" << endl;
      getline(cin, dauer);
      cout << "<?> Genre: <?>" << endl;
      getline(cin, genre);
      addMedium(new_id('d'), replaceAll(titel, ' ', '_'), 0, "0", replaceAll(fsk, ' ', '_'), replaceAll(dauer, ' ', '_'), replaceAll(genre, ' ', '_'));
      cout << "<I> DVD wurde der Liste hinzugefügt. <I>" << endl;
    }
  } else {
    cout << "<!> '" << answer << "' ist kein gültiger Parameter. Versuchen sie den Vorgang zu wiederholen. <!>" << endl;
  }
}

void del() {
  string answer;
  int occupiedItems = 0, index = 0;

  cout << "<?> Aus welcher Liste möchten sie einen Eintrag löschen? ([p]erson, [b]uch, [c]d, [d]vd) <?>" << endl;
  getline(cin, answer);
  if((answer == "p") || (answer == "person")) {
    string pid;
    cout << "<?> PID zum zu löschenden Eintrag: <?>" << endl;
    getline(cin, pid);
    index = id_exists(pid);
    if (index != -1) {
      for(int i = 0; i < bListe.getSize(); i++) {
        if ((bListe[i].getAusleiher() == pid)) {
          occupiedItems = occupiedItems+1;
        }
      }
      for(int i = 0; i < cListe.getSize(); i++) {
        if ((cListe[i].getAusleiher() == pid)) {
          occupiedItems = occupiedItems+1;
        }
      }
      for(int i = 0; i < dListe.getSize(); i++) {
        if ((dListe[i].getAusleiher() == pid)) {
          occupiedItems = occupiedItems+1;
        }
      }
      if (occupiedItems == 0) {
        pListe.removeElement(index);
        cout << "<I> Person wurde aus Liste entfernt. <I>" << endl;
      } else {
        cout << "<!> Person konnte nicht aus Liste entfernt werden, da sie " << occupiedItems << " Medien ausgeliehen hat. <!>" << endl;
      }
    } else {
      cout << "<!> Person mit PID '" << pid << "' existiert nicht. <!>" << endl;
    }
  } else if(answer == "b" || answer == "buch" || answer == "c" || answer == "cd" || answer == "d" || answer == "dvd") {
    string id;
    cout << "<?> ID zum zu löschenden Eintrag: <?>" << endl;
    getline(cin, id);
    index = id_exists(id);
    cout << "help0" << endl;
    if (index != -1) {
      cout << "help1" << endl;
      if(answer == "b" || answer == "buch") {
        if (bListe[index].getAusleiher() == "0") {
          bListe.removeElement(index);
          cout << "<I> Buch wurde aus Liste entfernt. <I>" << endl;
        } else {
          cout << "<!> Das Buch ist aktuell von '" << bListe[index].getAusleiher() << "' ausgeliehen und konnte somit nicht entfernt werden. <!>" << endl;
        }
      } else if(answer == "c" || answer == "cd") {
        cout << "help2" << endl;
        if (cListe[index].getAusleiher() == "0") {
          cout << "help3" << endl;
          cListe.removeElement(index);
          cout << "help4" << endl;
          cout << "<I> CD wurde aus Liste entfernt. <I>" << endl;
        } else {
          cout << "<!> Die CD ist aktuell von '" << cListe[index].getAusleiher() << "' ausgeliehen und konnte somit nicht entfernt werden. <!>" << endl;
        }
      } else if(answer == "d" || answer == "dvd") {
        if (dListe[index].getAusleiher() == "0") {
          dListe.removeElement(index);
          cout << "<I> DVD wurde aus Liste entfernt. <I>" << endl;
        } else {
          cout << "<!> Die DVD ist aktuell von '" << dListe[index].getAusleiher() << "' ausgeliehen und konnte somit nicht entfernt werden. <!>" << endl;
        }
      }
    } else {
      cout << "<!> Medium mit ID '" << id << "' existiert nicht. <!>" << endl;
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
      if ((bListe[i].getID() == searchArgument) ||  (bListe[i].getTitel() == searchArgument) || (bListe[i].getAusleiher() == searchArgument) || (bListe[i].getAutor() == searchArgument) || (bListe[i].getVerlag() == searchArgument) || (bListe[i].getSeitenanzahl() == searchArgument)) {
        cout << foundArguments+1 << ": " << bListe[i] << endl;
        foundArguments++;
      }
    }
  } else if ((answer == "c") || (answer == "cd" )) {
    for(int i = 0; i < cListe.getSize(); i++) {
      if ((cListe[i].getID() == searchArgument) ||  (cListe[i].getTitel() == searchArgument) || (cListe[i].getAusleiher() == searchArgument) || (cListe[i].getDauer() == searchArgument)) {
        cout << foundArguments+1 << ": " << cListe[i] << endl;
        foundArguments++;
      }
    }
  } else if ((answer == "d") || (answer == "dvd" )) {
    for(int i = 0; i < dListe.getSize(); i++) {
      if ((dListe[i].getID() == searchArgument) ||  (dListe[i].getTitel() == searchArgument) || (dListe[i].getAusleiher() == searchArgument) || (dListe[i].getDauer() == searchArgument) || (dListe[i].getGenre() == searchArgument)) {
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
  if (id_exists(pid) != -1) {
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
  if (id_exists(pid) != -1) {
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
        del();
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
