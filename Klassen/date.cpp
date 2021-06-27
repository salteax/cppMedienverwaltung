/************************************
*                                   *
*         Name: Paul Koreng         *
*       Matrikelnummer: 49224       *
*      Studiengruppe: 20/041/02     *
*                                   *
************************************/

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "date.h"

Date::Date() {
  jahr=monat=tag=0;
}

Date::Date(int jahr, int monat, int tag) {
  this->jahr=jahr;
  this->monat=monat;
  this->tag=tag;
}

void Date::setJahr(int jahr) {
  this->jahr=jahr;
}

int Date::getJahr() {
  return jahr;
}

void Date::setMonat(int monat) {
  this->monat=monat;
}

int Date::getMonat() {
  return monat;
}

void Date::setTag(int tag) {
  this->tag=tag;
}

int Date::getTag() {
  return tag;
}

string Date::dateToString() {
  string date = to_string(getTag()) + "." + to_string(getMonat()) + "." + to_string(getJahr());
  return date;
}

ostream& operator<<(ostream& os, const Date& d) {
  os << d.tag << "." << d.monat << "." << d.jahr;
  return os;
}
