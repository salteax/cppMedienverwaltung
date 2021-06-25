/************************************
*                                   *
*         Name: Paul Koreng         *
*       Matrikelnummer: 49224       *
*      Studiengruppe: 20/041/02     *
*                                   *
************************************/

#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;
#include "person.h"
#include "date.h"

// KONSTRUKTOREN

Person::Person() {
  pid=vorname=nachname=geschlecht="";
  geburtsdatum.setJahr(0);
  geburtsdatum.setMonat(0);
  geburtsdatum.setTag(0);
}

Person::Person(string pid, string vorname, string nachname, string geschlecht, int jahr, int monat, int tag) {
  this->pid = pid;
  this->vorname = vorname;
  this->nachname = nachname;
  this->geschlecht = geschlecht;
  geburtsdatum.setJahr(jahr);
  geburtsdatum.setMonat(monat);
  geburtsdatum.setTag(tag);
}

// SETTER & GETTER

void Person::setPID(string pid) {
  this->pid=pid;
}

string Person::getPID() {
  return pid;
}

void Person::setVorname(string vorname) {
  this->vorname=vorname;
}

string Person::getVorname() {
  return vorname;
}

void Person::setNachname(string nachname) {
  this->nachname=nachname;
}

string Person::getNachname() {
  return nachname;
}

void Person::setGeschlecht(string geschlecht) {
  this->geschlecht=geschlecht;
}

string Person::getGeschlecht() {
  return geschlecht;
}

void Person::setGeburtsdatum(int jahr, int monat, int tag) {
  geburtsdatum.setJahr(jahr);
  geburtsdatum.setMonat(monat);
  geburtsdatum.setTag(tag);
}

Date Person::getGeburtsdatum() {
  return geburtsdatum;
}

// FUNKTIONEN

int Person::getAlter() {
  int dd, dm, dy;

  time_t ttime = time(0);
  tm *local_time = localtime(&ttime);

  int cur_year = 1900 + local_time->tm_year;
  int cur_month = 1 + local_time->tm_mon;
  int cur_day = local_time->tm_mday;

  int prev_year = geburtsdatum.getJahr();
  int prev_month = geburtsdatum.getMonat();
  int prev_day = geburtsdatum.getTag();

  int mm[12]={31,prev_year%4==0&&prev_year%100!=0||prev_year%400==0?29:28,31,30,31,30,31,31,30,31,30,31};

  if(prev_day>cur_day)   // Berechnung Tage
  {
    cur_day=cur_day+mm[cur_month-2];
    dd=cur_day-prev_day;
    cur_month=cur_month-1;
  }
  else
    dd=cur_day-prev_day;
  if(prev_month>cur_month)   // Berechnung Monate
  {
    cur_month=cur_month+12;
    cur_year=cur_year-1;
    dm=cur_month-prev_month;
  }
  else
    dm=cur_month-prev_month;
    dy=cur_year-prev_year;    // Berechnung Jahre

  return dy;
}
