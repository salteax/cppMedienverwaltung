#include "../person.h"
#include "../date.h"
#include "medium.h"

#ifndef _BUCH_H_
#define _BUCH_H_
class Buch : public Medium
{
public:
    // KONSTRUKTOREN
    Buch();
    Buch(string id, string titel, int jahrA, int monatA, int tagA, int jahrR, int monatR, int tagR, bool ausleihStatus, string ausleiher, string autor, string verlag, int seitenanzahl);
    // SETTER & GETTER
    void setAutor(string autor);
    string getAutor();
    void setVerlag(string verlag);
    string getVerlag();
    void setSeitenanzahl(int seitenanzahl);
    int getSeitenanzahl();
    // FUNKTIONEN
private:
  string autor, verlag;
  int seitenanzahl;
};
#endif
