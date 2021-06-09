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

Liste<Person> pListe;
Liste<Buch> bListe;

void fileToListe()
{
  // Allgemeine Variablen
  int index;
  // Objektbezogene Variablen
  string jahr1, monat1, tag1, jahr2, monat2, tag2;
  string pid, vorname, nachname, geschlecht;
  string titel, ausleiher, autor, verlag, seitenanzahl;
  bool ausleihStatus;
  // Dateiarbeit Variablen
  ifstream file;
  string line, c;

  // Personendaten einlesen
  file.open("./Daten/person.dat");

  if(file.fail())
  {
    cout << "Datei konnte nicht geoeffnet werden!" << endl;
  }

  index = 0;

  while (getline(file,line))
  {
      istringstream my_stream(line);
      my_stream >> pid >> vorname >> nachname >> geschlecht >> jahr1 >> monat1 >> tag1 >> c;
      Person tempPerson(pid, vorname, nachname, geschlecht, stoi(jahr1), stoi(monat1), stoi(tag1));
      pListe.addElement(tempPerson);
      index++;
  }

  file.close();

  // Buchdaten einlesen
  file.open("./Daten/buch.dat");

  if(file.fail())
  {
    cout << "Datei konnte nicht geoeffnet werden!" << endl;
  }

  index = 0;

  while (getline(file,line))
  {
      istringstream my_stream(line);
      my_stream >> titel >> jahr1 >> monat1 >> tag1 >> jahr2 >> monat2 >> tag2 >> ausleihStatus >> ausleiher >> autor >> verlag >> seitenanzahl;
      Buch tempBuch(titel, stoi(jahr1), stoi(monat1), stoi(tag1), stoi(jahr2), stoi(monat2), stoi(tag2), ausleihStatus, ausleiher, autor, verlag, stoi(seitenanzahl));
      bListe.addElement(tempBuch);
      index++;
  }


}

void listeToFile()
{

}

void open()
{
  cout << "Start" << endl;
  fileToListe();
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
