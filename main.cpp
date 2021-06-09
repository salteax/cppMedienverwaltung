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
  }
  my_stream.clear();

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

}

void open()
{
  // TODO: GENERELL FUNKTION DIE AUSFUEHRZEIT VON FUNKTIONEN BERECHNET VLLT NUR WENN ZEIT

  cout << "Start" << endl;

  cout << "Einlesen der Datei - ANFANG" << endl;
  fileToListe();
  cout << "Einlesen der Datei - ENDE" << endl;

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
