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

// KONSTRUKTOREN

Person::Person()
{
    pid=vorname=nachname="";
}

Person::Person(string pid, string vorname, string nachname)
{
    this->pid = pid;
    this->vorname = vorname;
    this->nachname = nachname;
}

// SETTER & GETTER

void Person::setPID(string pid)
{
    this->pid=pid;
}

string Person::getPID()
{
    return pid;
}

void Person::setVorname(string vorname)
{
    this->vorname=vorname;
}

string Person::getVorname()
{
    return vorname;
}

void Person::setNachname(string nachname)
{
    this->nachname=nachname;
}

string Person::getNachname()
{
    return nachname;
}

// OPERATOR

ostream& operator<<(ostream& os, Person& p)
{
    os << p.getPID() << ", " << p.getVorname() << " " << p.getNachname();
    return os;
}
