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

DVD::DVD()
{
    setID("");
    setTitel("");
    setKennzeichen("dvd");
    setAusleihStatus(false);
    setAusleiher("");
    this->dauer="";
    this->genre="";
}

DVD::DVD(string id, string titel, bool ausleihStatus, string ausleiher, string dauer, string genre)
{
    setID(id);
    setTitel(titel);
    setKennzeichen("dvd");
    setAusleihStatus(ausleihStatus);
    setAusleiher(ausleiher);
    this->dauer=dauer;
    this->genre=genre;
}

// SETTER & GETTER

void DVD::setDauer(string dauer)
{
    this->dauer=dauer;
}

string DVD::getDauer()
{
    return dauer;
}

void DVD::setGenre(string genre)
{
    this->genre=genre;
}

string DVD::getGenre()
{
    return genre;
}

// OPERATOR

ostream& operator<<(ostream& os, DVD& d)
{
    if (d.getAusleihStatus()) {
        os << d.getID() << ", " << d.getTitel() << ", " << d.getGenre() << ", " << d.getDauer() << ", " << "ausgeliehen von " << d.getAusleiher();
    } else {
        os << d.getID() << ", " << d.getTitel() << ", " << d.getGenre() << ", " << d.getDauer() << ", " << "nicht ausgeliehen";
    }
    return os;
}
