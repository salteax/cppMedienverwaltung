/************************************
*                                   *
*         Name: Paul Koreng         *
*       Matrikelnummer: 49224       *
*      Studiengruppe: 20/041/02     *
*                                   *
************************************/

#include <iostream>
#include <iomanip>
using namespace std;
#include "medium.h"
#include "buch.h"

// KONSTRUKTOREN

Buch::Buch() {
  setID("");
  setTitel("");
  setKennzeichen("b");
  setAusleihStatus(false);
  setAusleiher("");
  this->autor="";
  this->verlag="";
  this->seitenanzahl=0;
}

Buch::Buch(string id, string titel, bool ausleihStatus, string ausleiher, string autor, string verlag, int seitenanzahl) {
  setID(id);
  setTitel(titel);
  setKennzeichen("b");
  setAusleihStatus(ausleihStatus);
  setAusleiher(ausleiher);
  this->autor=autor;
  this->verlag=verlag;
  this->seitenanzahl=seitenanzahl;
}

// SETTER & GETTER

void Buch::setAutor(string autor) {
  this->autor=autor;
}

string Buch::getAutor() {
  return autor;
}

void Buch::setVerlag(string verlag) {
  this->verlag=verlag;
}

string Buch::getVerlag() {
  return verlag;
}

void Buch::setSeitenanzahl(int seitenanzahl) {
  this->seitenanzahl=seitenanzahl;
}

int Buch::getSeitenanzahl() {
  return seitenanzahl;
}

// OPERATOR

ostream& operator<<(ostream& os, Buch& b) {
  if (b.getAusleihStatus()) {
    os << b.getID() << ", " << b.getTitel() << ", " << b.getAutor() << ", " << b.getVerlag() << ", " << b.getSeitenanzahl() << ", " << "ausgeliehen von " << b.getAusleiher();
  } else {
    os << b.getID() << ", " << b.getTitel() << ", " << b.getAutor() << ", " << b.getVerlag() << ", " << b.getSeitenanzahl() << ", " << "nicht ausgeliehen";
  }
  return os;
}
