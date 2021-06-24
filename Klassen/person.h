#include "date.h"

#ifndef _PERSON_H_
#define _PERSON_H_
class Person {
public:
  // KONSTRUKTOREN
  Person();
  Person(string pid, string vorname, string nachname, string geschlecht, int jahr, int monat, int tag);
  // SETTER & GETTER
  void setPID(string pid);
  string getPID();
  void setVorname(string vorname);
  string getVorname();
  void setNachname(string nachname);
  string getNachname();
  void setGeschlecht(string geschlecht);
  string getGeschlecht();
  void setGeburtsdatum(int jahr, int monat, int tag);
  Date getGeburtsdatum();
  // FUNKTIONEN
  int getAlter(); // Funktion zum ueberpruefun des alter ob bei CDs zb Alter ok ist wegen vergabe
private:
  string pid, vorname, nachname, geschlecht;
  Date geburtsdatum;
};
#endif
