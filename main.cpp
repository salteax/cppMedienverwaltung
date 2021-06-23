#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
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

*/

// Globale Variablen
Liste<Person> pListe;
Liste<Buch> bListe;
Liste<CD> cListe;
Liste<DVD> dListe;

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

void addPerson(string pid, string vorname, string nachname, string geschlecht, int jahr, int monat, int tag) {
  Person tempPerson(pid, vorname, nachname, geschlecht, jahr, monat, tag);
  pListe.addElement(tempPerson);
}

void fileToListe() {
  // Objektbezogene Variablen
  string jahr1, monat1, tag1, jahr2, monat2, tag2;
  string pid, vorname, nachname, geschlecht;
  string id, titel, ausleiher, autor, verlag, seitenanzahl, dauer, fsk, genre;
  bool ausleihStatus;
  // Dateiarbeit Variablen
  ifstream file;
  string line, c;

  // Personen-Daten einlesen
  file.open("./Daten/person.dat");

  if(file.fail()) {
    cout << "Datei konnte nicht geoeffnet werden!" << endl;
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
  file.open("./Daten/medien.dat");

  if(file.fail()) {
    cout << "Datei konnte nicht geoeffnet werden!" << endl;
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
}

void listeToFile() {
  ofstream file;
  file.open("./Daten/person.dat");
  if(file.fail()) {
    cout << "Datei konnte nicht geoeffnet werden!" << endl;
  }

  file.seekp(0);

  for (int i = 0; i < pListe.getSize(); i++) {
    file << pListe[i].getPID() << " " << pListe[i].getVorname() << " " << pListe[i].getNachname() << " " << pListe[i].getGeschlecht() << " " << pListe[i].getGeburtsdatum().getJahr() << " " << pListe[i].getGeburtsdatum().getMonat() << " " << pListe[i].getGeburtsdatum().getTag() << endl;
  }
  file.close();

  file.open("./Daten/medien.dat");
  if(file.fail()) {
    cout << "Datei konnte nicht geoeffnet werden!" << endl;
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

void open() {
  cout << "Start" << endl;

  cout << "Einlesen der Datei - ANFANG" << endl;
  fileToListe();
  cout << "Einlesen der Datei - ENDE" << endl;
}

void close() {
  cout << "Auslesen der Listen - ANFANG" << endl;
  listeToFile();
  cout << "Auslesen der Listen - ENDE" << endl;

  cout << "Ende" << endl;
}

int main(int argc, char*argv[]) {
  // Compiler-Command
  //g++ main.cpp Klassen/person.cpp Klassen/date.cpp Klassen/Medien/medium.cpp Klassen/Medien/buch.cpp Klassen/Medien/cd.cpp Klassen/Medien/dvd.cpp

  open();
  close();
  return 0;
}
