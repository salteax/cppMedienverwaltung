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
#include "dvd.h"

// KONSTRUKTOREN

DVD::DVD() {
  setID("");
  setTitel("");
  setKennzeichen("dvd");
  setAusleihStatus(false);
  setAusleiher("");
  this->fsk=0;
  this->dauer=0;
  this->genre="";
}

DVD::DVD(string id, string titel, bool ausleihStatus, string ausleiher, int fsk, int dauer, string genre) {
  setID(id);
  setTitel(titel);
  setKennzeichen("dvd");
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
    os << d.getID() << ", " << d.getTitel() << ", " << d.getGenre() << ", " << d.getFSK() << ", " << d.getDauer() << ", " << "ausgeliehen von " << d.getAusleiher();
  } else {
    os << d.getID() << ", " << d.getTitel() << ", " << d.getGenre() << ", " << d.getFSK() << ", " << d.getDauer() << ", " << "nicht ausgeliehen";
  }
  return os;
}
