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
#include "cd.h"

// KONSTRUKTOREN

CD::CD() {
  setID("");
  setTitel("");
  setKennzeichen("cd");
  setAusleihStatus(false);
  setAusleiher("");
  this->dauer=0;
}

CD::CD(string id, string titel, bool ausleihStatus, string ausleiher, int dauer) {
  setID(id);
  setTitel(titel);
  setKennzeichen("cd");
  setAusleihStatus(ausleihStatus);
  setAusleiher(ausleiher);
  this->dauer=dauer;
}

// SETTER & GETTER

void CD::setDauer(int dauer) {
  this->dauer=dauer;
}

int CD::getDauer() {
  return dauer;
}

// OPERATOR

ostream& operator<<(ostream& os, CD& c) {
  if (c.getAusleihStatus()) {
    os << c.getID() << ", " << c.getTitel() << ", " << c.getDauer() << ", " << "ausgeliehen von " << c.getAusleiher();
  } else {
    os << c.getID() << ", " << c.getTitel() << ", " << c.getDauer() << ", " << "nicht ausgeliehen";
  }
  return os;
}
