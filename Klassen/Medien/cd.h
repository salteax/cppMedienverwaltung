#include "../person.h"
#include "../date.h"
#include "medium.h"

#ifndef _CD_H_
#define _CD_H_
class CD : public Medium
{
public:
    // KONSTRUKTOREN
    CD();
    CD(string titel, Date ausleihDatum, Date rueckgabeDatum, bool ausleihStatus, string ausleiher, int dauer);
    // SETTER & GETTER
    void setDauer(int dauer);
    int getDauer();
    // FUNKTIONEN
private:
  int dauer;
};
#endif
