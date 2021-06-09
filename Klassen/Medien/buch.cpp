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
  ausleihDatum.setJahr(0);
  ausleihDatum.setMonat(0);
  ausleihDatum.setTag(0);
  rueckgabeDatum.setJahr(0);
  rueckgabeDatum.setMonat(0);
  rueckgabeDatum.setTag(0);
  setAusleihStatus(false);
  setAusleiher("");
  this->autor="";
  this->verlag="";
  this->seitenanzahl=0;
}

Buch::Buch(string titel, int jahrA, int monatA, int tagA, int jahrR, int monatR, int tagR, bool ausleihStatus, string ausleiher, string autor, string verlag, int seitenanzahl)
{
  setTitel(titel);
  setKennzeichen("b");
  ausleihDatum.setJahr(jahrA);
  ausleihDatum.setMonat(monatA);
  ausleihDatum.setTag(tagA);
  rueckgabeDatum.setJahr(jahrR);
  rueckgabeDatum.setMonat(monatR);
  rueckgabeDatum.setTag(tagR);
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

void Buch::setAusleihDatum(int jahr, int monat, int tag)
{
  ausleihDatum.setJahr(jahr);
  ausleihDatum.setMonat(monat);
  ausleihDatum.setTag(tag);
}

Date Buch::getAusleihDatum()
{
  return ausleihDatum;
}

void Buch::setRueckgabeDatum(int jahr, int monat, int tag)
{
  rueckgabeDatum.setJahr(jahr);
  rueckgabeDatum.setMonat(monat);
  rueckgabeDatum.setTag(tag);
}

Date Buch::getRueckgabeDatum()
{
  return rueckgabeDatum;
}
