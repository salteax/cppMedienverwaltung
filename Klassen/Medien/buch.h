/************************************
*                                   *
*         Name: Paul Koreng         *
*       Matrikelnummer: 49224       *
*      Studiengruppe: 20/041/02     *
*                                   *
************************************/

#include "medium.h"

#ifndef _BUCH_H_
#define _BUCH_H_
class Buch : public Medium
{
public:
    // KONSTRUKTOREN
    Buch();
    Buch(string id, string titel, bool ausleihStatus, string ausleiher, string autor, string verlag, string seitenanzahl);
    // SETTER & GETTER
    void setAutor(string autor);
    string getAutor();
    void setVerlag(string verlag);
    string getVerlag();
    void setSeitenanzahl(string seitenanzahl);
    string getSeitenanzahl();
    // OPERATOR
    friend ostream& operator<<(ostream& os, Buch& b);
private:
    string autor, verlag, seitenanzahl;
};
#endif
