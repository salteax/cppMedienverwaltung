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
  setAusleihDatum(0,0,0);
  setRueckgabeDatum(0,0,0);
  setAusleihStatus(false);
  setAusleiher("");
  this->dauer=0;
}

CD::CD(string titel, int jahrA, int monatA, int tagA, int jahrR, int monatR, int tagR, bool ausleihStatus, string ausleiher, int dauer)
{
  setTitel(titel);
  setKennzeichen("cd");
  setAusleihDatum(jahrA, monatA, tagA);
  setRueckgabeDatum(jahrR, monatR, tagR);
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
