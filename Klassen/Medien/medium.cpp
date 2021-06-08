#include <iostream>
#include <iomanip>
using namespace std;
#include "../person.h"
#include "../date.h"
#include "medium.h"

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

void Medium::setAusleihDatum(Date ausleihDatum)
{
  this->ausleihDatum=ausleihDatum;
}

Date Medium::getAusleihDatum()
{
  return ausleihDatum;
}

void Medium::setRueckgabeDatum(Date rueckgabeDatum)
{
  this->rueckgabeDatum=rueckgabeDatum;
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
