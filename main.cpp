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

void fileToListe()
{
  ifstream file;
  string discard;

  // Personendaten einlesen
  file.open("./Daten/person.dat");

  if(file.fail())
  {
    cout << "Datei konnte nicht geoeffnet werden!" << endl;
  }

  /*string line;
  int index = 0, zeilen = 0;

  while (getline(file, line))
  {
    zeilen++;
  }

  cout << "Zeilen: " << zeilen << endl;*/

  int index = 0;
  string vorname, nachname, geschlecht;
  string jahr, monat, tag;

  //file.clear();
  //file.seekg(0);

  string line, c;

  //while (!file.eof() && file >> vorname >> nachname >> jahr >> monat >> tag)
  while (getline(file,line))
  {
      istringstream my_stream(line);
      my_stream >> vorname >> nachname >> geschlecht >> jahr >> monat >> tag /*>>c*/;
      cout << " a " << vorname << " b " << nachname << " c " << geschlecht << " d " << jahr << " e " << monat << " f " << tag << " g " << endl;

      index++;
  }
  cout << "Zeilen ausgelesen: " << index << endl;
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
