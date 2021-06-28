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

// SETTER & GETTER

void Medium::setID(string id)
{
    this->id=id;
}

string Medium::getID()
{
    return id;
}

void Medium::setTitel(string titel)
{
    this->titel=titel;
}

string Medium::getTitel()
{
    return titel;
}

void Medium::setKennzeichen(string kennzeichen)
{
    this->kennzeichen=kennzeichen;
}

string Medium::getKennzeichen()
{
    return kennzeichen;
}

void Medium::setAusleihStatus(bool ausleihStatus)
{
    this->ausleihStatus=ausleihStatus;
}

bool Medium::getAusleihStatus()
{
    return ausleihStatus;
}

void Medium::setAusleiher(string pid)
{
    this->pid=pid;
}

string Medium::getAusleiher()
{
    return pid;
}
