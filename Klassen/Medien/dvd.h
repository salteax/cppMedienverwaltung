#include "../person.h"
#include "../date.h"
#include "medium.h"

#ifndef _DVD_H_
#define _DVD_H_
class DVD : public Medium
{
public:
    // KONSTRUKTOREN
    DVD();
    DVD(string titel, Date ausleihDatum, Date rueckgabeDatum, bool ausleihStatus, string ausleiher, int fsk, int dauer, string genre);
    // SETTER & GETTER
    void setFSK(int fsk);
    int getFSK();
    void setDauer(int dauer);
    int getDauer();
    void setGenre(string genre);
    string getGenre();
    // FUNKTIONEN
private:
  int fsk, dauer;
  string genre;
};
#endif
