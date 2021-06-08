#include <iostream>
#include <iomanip>
using namespace std;
#include "../person.h"
#include "../date.h"
#include "medium.h"
#include "cd.h"

CD::CD()
{
  Date ausleihDatum;
  Date rueckgabeDatum;

  setTitel("");
  setKennzeichen("cd");
  setAusleihDatum(ausleihDatum);
  setRueckgabeDatum(rueckgabeDatum);
  setAusleihStatus(false);
  setAusleiher("");
  this->dauer=0;
}

CD::CD(string titel, Date ausleihDatum, Date rueckgabeDatum, bool ausleihStatus, string ausleiher, int dauer)
{
  setTitel(titel);
  setKennzeichen("cd");
  setAusleihDatum(ausleihDatum);
  setRueckgabeDatum(rueckgabeDatum);
  setAusleihStatus(ausleihStatus);
  setAusleiher(ausleiher);
  this->dauer=dauer;
}

void CD::setDauer(int dauer)
{
  this->dauer=dauer;
}

int CD::getDauer()
{
  return dauer;
}
