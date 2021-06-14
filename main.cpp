#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <chrono>
using namespace std;
#include "./Klassen/person.h"
#include "./Klassen/date.h"
#include "./Klassen/liste.h"
#include "./Klassen/Medien/medium.h"
#include "./Klassen/Medien/buch.h"
#include "./Klassen/Medien/cd.h"
#include "./Klassen/Medien/dvd.h"

// Globale Variablen
Liste<Person> pListe;
Liste<Buch> bListe;
Liste<CD> cListe;
Liste<DVD> dListe;

void fileToListe()
{
  // Objektbezogene Variablen
  string jahr1, monat1, tag1, jahr2, monat2, tag2;
  string pid, vorname, nachname, geschlecht;
  string titel, ausleiher, autor, verlag, seitenanzahl, dauer, fsk, genre;
  bool ausleihStatus;
  // Dateiarbeit Variablen
  ifstream file;
  string line, id, c;

  // Personen-Daten einlesen
  file.open("./Daten/person.dat");

  if(file.fail())
  {
    cout << "Datei konnte nicht geoeffnet werden!" << endl;
  }

  istringstream my_stream;

  while (getline(file,line))
  {
    my_stream.str(line);
    my_stream >> pid >> vorname >> nachname >> geschlecht >> jahr1 >> monat1 >> tag1 >> c;
    Person tempPerson(pid, vorname, nachname, geschlecht, stoi(jahr1), stoi(monat1), stoi(tag1));
    pListe.addElement(tempPerson);
    my_stream.clear();
  }

  file.close();

  // Medien-Daten einlesen
  file.open("./Daten/medien.dat");

  if(file.fail())
  {
    cout << "Datei konnte nicht geoeffnet werden!" << endl;
  }

  while (getline(file,line))
  {
    my_stream.str(line);
    my_stream >> id >> c;
    my_stream.clear();

    switch (stoi(id)) {
      case 1:
      {
        my_stream.str(line);
        my_stream >> c >> titel >> jahr1 >> monat1 >> tag1 >> jahr2 >> monat2 >> tag2 >> ausleihStatus >> ausleiher >> autor >> verlag >> seitenanzahl >> c;
        Buch tempBuch(titel, stoi(jahr1), stoi(monat1), stoi(tag1), stoi(jahr2), stoi(monat2), stoi(tag2), ausleihStatus, ausleiher, autor, verlag, stoi(seitenanzahl));
        bListe.addElement(tempBuch);
        my_stream.clear();
      }
      break;
      case 2:
      {
        my_stream.str(line);
        my_stream >> c >> titel >> jahr1 >> monat1 >> tag1 >> jahr2 >> monat2 >> tag2 >> ausleihStatus >> ausleiher >> dauer >> c;
        CD tempCD(titel, stoi(jahr1), stoi(monat1), stoi(tag1), stoi(jahr2), stoi(monat2), stoi(tag2), ausleihStatus, ausleiher, stoi(dauer));
        cListe.addElement(tempCD);
        my_stream.clear();
      }
      break;
      case 3:
      {
        my_stream.str(line);
        my_stream >> c >> titel >> jahr1 >> monat1 >> tag1 >> jahr2 >> monat2 >> tag2 >> ausleihStatus >> ausleiher >> fsk >> dauer >> genre >> c;
        DVD tempDVD(titel, stoi(jahr1), stoi(monat1), stoi(tag1), stoi(jahr2), stoi(monat2), stoi(tag2), ausleihStatus, ausleiher, stoi(fsk), stoi(dauer), genre);
        dListe.addElement(tempDVD);
        my_stream.clear();
      }
      break;
      default:
        cout << "Kein gueltiger Typ." << endl;
    }
  }
}

void listeToFile()
{
  ofstream file;
  file.open("./Daten/person.dat");
  if(file.fail())
  {
    cout << "Datei konnte nicht geoeffnet werden!" << endl;
  }

  file.seekp(0);

  for (int i = 0; i < pListe.getSize(); i++) {
    file << pListe[i].getPID() << " " << pListe[i].getVorname() << " " << pListe[i].getNachname() << " " << pListe[i].getGeschlecht() << " " << pListe[i].getGeburtsdatum().getJahr() << " " << pListe[i].getGeburtsdatum().getMonat() << " " << pListe[i].getGeburtsdatum().getTag() << endl;
  }
  file.close();

  file.open("./Daten/medien.dat");
  if(file.fail())
  {
    cout << "Datei konnte nicht geoeffnet werden!" << endl;
  }

  file.seekp(0);

  for (int i = 0; i < bListe.getSize(); i++) {
    file << "1" << " " << bListe[i].getTitel() << " " << bListe[i].getAusleihDatum().getJahr() << " " << bListe[i].getAusleihDatum().getMonat() << " " << bListe[i].getAusleihDatum().getTag() << " " << bListe[i].getRueckgabeDatum().getJahr() << " " << bListe[i].getRueckgabeDatum().getMonat() << " " << bListe[i].getRueckgabeDatum().getTag() << " " << bListe[i].getAusleihStatus() << " " << bListe[i].getAusleiher() << " " << bListe[i].getAutor() << " " << bListe[i].getVerlag() << " " << bListe[i].getSeitenanzahl() << endl;
  }

  for (int i = 0; i < cListe.getSize(); i++) {
    file << "2" << " " << cListe[i].getTitel() << " " << cListe[i].getAusleihDatum().getJahr() << " " << cListe[i].getAusleihDatum().getMonat() << " " << cListe[i].getAusleihDatum().getTag() << " " << cListe[i].getRueckgabeDatum().getJahr() << " " << cListe[i].getRueckgabeDatum().getMonat() << " " << cListe[i].getRueckgabeDatum().getTag() << " " << cListe[i].getAusleihStatus() << " " << cListe[i].getAusleiher() << " " << cListe[i].getDauer() << endl;
  }

  for (int i = 0; i < dListe.getSize(); i++) {
    file << "3" << " " << dListe[i].getTitel() << " " << dListe[i].getAusleihDatum().getJahr() << " " << dListe[i].getAusleihDatum().getMonat() << " " << dListe[i].getAusleihDatum().getTag() << " " << dListe[i].getRueckgabeDatum().getJahr() << " " << dListe[i].getRueckgabeDatum().getMonat() << " " << dListe[i].getRueckgabeDatum().getTag() << " " << dListe[i].getAusleihStatus() << " " << dListe[i].getAusleiher() << " " << dListe[i].getFSK() << " " << dListe[i].getDauer() << " " << dListe[i].getGenre() << endl;
  }

  file.close();
}

void open()
{

  cout << "Start" << endl;

  cout << "Einlesen der Datei - ANFANG" << endl;
  fileToListe();
  cout << "Einlesen der Datei - ENDE" << endl;
  listeToFile();
}

void close()
{

}

int main(int argc, char*argv[])
{
  //g++ main.cpp Klassen/person.cpp Klassen/date.cpp Klassen/Medien/medium.cpp Klassen/Medien/buch.cpp Klassen/Medien/cd.cpp Klassen/Medien/dvd.cpp
  open();

  return 0;
}
