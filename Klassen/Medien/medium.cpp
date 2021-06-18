#include <iostream>
#include <iomanip>
using namespace std;
#include "../person.h"
#include "../date.h"
#include "medium.h"

void Medium::setID(string id)
{
  this->id=id;
}

string Medium::getID()
{
  return id;
}

void Medium::setTitel(string titel)
{
  this->titel=titel;
}

string Medium::getTitel()
{
  return titel;
}

void Medium::setKennzeichen(string kennzeichen)
{
  this->kennzeichen=kennzeichen;
}

string Medium::getKennzeichen()
{
  return kennzeichen;
}

void Medium::setAusleihDatum(int jahr, int monat, int tag)
{
  ausleihDatum.setJahr(jahr);
  ausleihDatum.setMonat(monat);
  ausleihDatum.setTag(tag);
}

Date Medium::getAusleihDatum()
{
  return ausleihDatum;
}

void Medium::setRueckgabeDatum(int jahr, int monat, int tag)
{
  rueckgabeDatum.setJahr(jahr);
  rueckgabeDatum.setMonat(monat);
  rueckgabeDatum.setTag(tag);
}

Date Medium::getRueckgabeDatum()
{
  return rueckgabeDatum;
}

void Medium::setAusleihStatus(bool ausleihStatus)
{
  this->ausleihStatus=ausleihStatus;
}

bool Medium::getAusleihStatus()
{
  return ausleihStatus;
}

void Medium::setAusleiher(string pid)
{
  this->pid=pid;
}

string Medium::getAusleiher()
{
  return pid;
}
