#include "../date.h"

#ifndef _MEDIUM_H_
#define _MEDIUM_H_
class Medium
{
public:
    // SETTER & GETTER
    void setID(string id);
    string getID();
    void setTitel(string titel);
    string getTitel();
    void setKennzeichen(string kennzeichen);
    string getKennzeichen();
    void setAusleihDatum(int jahr, int monat, int tag);
    Date getAusleihDatum();
    void setRueckgabeDatum(int jahr, int monat, int tag);
    Date getRueckgabeDatum();
    void setAusleihStatus(bool ausleihStatus);
    bool getAusleihStatus();
    void setAusleiher(string pid);
    string getAusleiher();

    // FUNKTIONEN
private:
    string id, pid, titel, kennzeichen;
    Date ausleihDatum, rueckgabeDatum;
    bool ausleihStatus;
};
#endif
