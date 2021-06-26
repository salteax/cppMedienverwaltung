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
#include "../person.h"
#include "../date.h"
#include "medium.h"
#include "dvd.h"

// KONSTRUKTOREN

DVD::DVD() {
  Date ausleihDatum;
  Date rueckgabeDatum;
  setID("");
  setTitel("");
  setKennzeichen("dvd");
  setAusleihDatum(0,0,0);
  setRueckgabeDatum(0,0,0);
  setAusleihStatus(false);
  setAusleiher("");
  this->fsk=0;
  this->dauer=0;
  this->genre="";
}

DVD::DVD(string id, string titel, int jahrA, int monatA, int tagA, int jahrR, int monatR, int tagR, bool ausleihStatus, string ausleiher, int fsk, int dauer, string genre) {
  setID(id);
  setTitel(titel);
  setKennzeichen("dvd");
  setAusleihDatum(jahrA, monatA, tagA);
  setRueckgabeDatum(jahrR, monatR, tagR);
  setAusleihStatus(ausleihStatus);
  setAusleiher(ausleiher);
  this->fsk=fsk;
  this->dauer=dauer;
  this->genre=genre;
}

// SETTER & GETTER

void DVD::setFSK(int fsk) {
  this->fsk=fsk;
}

int DVD::getFSK() {
  return fsk;
}

void DVD::setDauer(int dauer) {
  this->dauer=dauer;
}

int DVD::getDauer() {
  return dauer;
}

void DVD::setGenre(string genre) {
  this->genre=genre;
}

string DVD::getGenre() {
  return genre;
}

// OPERATOR

ostream& operator<<(ostream& os, DVD& d) {
  if (d.getAusleihStatus()) {
    os << d.getID() << ", " << d.getTitel() << ", " << d.getGenre() << ", " << d.getFSK() << ", " << d.getDauer() << ", " << "ausgeliehen" << ", " << d.getAusleiher() << ", " << d.getAusleihDatum() << ", " << d.getRueckgabeDatum();
  } else {
    os << d.getID() << ", " << d.getTitel() << ", " << d.getGenre() << ", " << d.getFSK() << ", " << d.getDauer() << ", " << "nicht ausgeliehen";
  }
  return os;
}
