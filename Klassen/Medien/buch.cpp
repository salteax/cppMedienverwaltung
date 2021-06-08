#include <iostream>
#include <iomanip>
using namespace std;
#include "../person.h"
#include "../date.h"
#include "medium.h"
#include "buch.h"

Buch::Buch()
{
  Date ausleihDatum;
  Date rueckgabeDatum;

  setTitel("");
  setKennzeichen("b");
  setAusleihDatum(ausleihDatum);
  setRueckgabeDatum(rueckgabeDatum);
  setAusleihStatus(false);
  setAusleiher("");
  this->autor="";
  this->verlag="";
  this->seitenanzahl=0;
}

Buch::Buch(string titel, Date ausleihDatum, Date rueckgabeDatum, bool ausleihStatus, string ausleiher, string autor, string verlag, int seitenanzahl)
{
  setTitel(titel);
  setKennzeichen("b");
  setAusleihDatum(ausleihDatum);
  setRueckgabeDatum(rueckgabeDatum);
  setAusleihStatus(ausleihStatus);
  setAusleiher(ausleiher);
  this->autor=autor;
  this->verlag=verlag;
  this->seitenanzahl=seitenanzahl;
}

void Buch::setAutor(string autor)
{
  this->autor=autor;
}

string Buch::getAutor()
{
  return autor;
}

void Buch::setVerlag(string verlag)
{
  this->verlag=verlag;
}

string Buch::getVerlag()
{
  return verlag;
}

void Buch::setSeitenanzahl(int seitenanzahl)
{
  this->seitenanzahl=seitenanzahl;
}

int Buch::getSeitenanzahl()
{
  return seitenanzahl;
}
