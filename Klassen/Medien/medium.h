#include "../date.h"

#ifndef _MEDIUM_H_
#define _MEDIUM_H_
class Medium
{
public:
    // SETTER & GETTER
    void setTitel(string titel);
    string getTitel();
    void setKennzeichen(string kennzeichen);
    string getKennzeichen();
    void setAusleihDatum(Date ausleihDatum);
    Date getAusleihDatum();
    void setRueckgabeDatum(Date rueckgabeDatum);
    Date getRueckgabeDatum();
    void setAusleihStatus(bool ausleihStatus);
    bool getAusleihStatus();
    void setAusleiher(string pid);
    string getAusleiher();
    // FUNKTIONEN
private:
    string pid, titel, kennzeichen;
    Date ausleihDatum, rueckgabeDatum;
    bool ausleihStatus;
};
#endif
