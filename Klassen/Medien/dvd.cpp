#include <iostream>
#include <iomanip>
using namespace std;
#include "../person.h"
#include "../date.h"
#include "medium.h"
#include "dvd.h"

DVD::DVD()
{
  Date ausleihDatum;
  Date rueckgabeDatum;

  setTitel("");
  setKennzeichen("dvd");
  setAusleihDatum(ausleihDatum);
  setRueckgabeDatum(rueckgabeDatum);
  setAusleihStatus(false);
  setAusleiher("");
  this->fsk=0;
  this->dauer=0;
  this->genre="";
}

DVD::DVD(string titel, Date ausleihDatum, Date rueckgabeDatum, bool ausleihStatus, string ausleiher, int fsk, int dauer, string genre)
{
  setTitel(titel);
  setKennzeichen("dvd");
  setAusleihDatum(ausleihDatum);
  setRueckgabeDatum(rueckgabeDatum);
  setAusleihStatus(ausleihStatus);
  setAusleiher(ausleiher);
  this->fsk=fsk;
  this->dauer=dauer;
  this->genre=genre;
}

// SETTER & GETTER
void DVD::setFSK(int fsk)
{
  this->fsk=fsk;
}

int DVD::getFSK()
{
  return fsk;
}

void DVD::setDauer(int dauer)
{
  this->dauer=dauer;
}

int DVD::getDauer()
{
  return dauer;
}

void DVD::setGenre(string genre)
{
  this->genre=genre;
}

string DVD::getGenre()
{
  return genre;
}
