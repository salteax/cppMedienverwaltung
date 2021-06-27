/************************************
*                                   *
*         Name: Paul Koreng         *
*       Matrikelnummer: 49224       *
*      Studiengruppe: 20/041/02     *
*                                   *
************************************/

#include "../date.h"

#ifndef _MEDIUM_H_
#define _MEDIUM_H_
class Medium {
public:
  // SETTER & GETTER
  void setID(string id);
  string getID();
  void setTitel(string titel);
  string getTitel();
  void setKennzeichen(string kennzeichen);
  string getKennzeichen();
  void setAusleihStatus(bool ausleihStatus);
  bool getAusleihStatus();
  void setAusleiher(string pid);
  string getAusleiher();
private:
  string id, pid, titel, kennzeichen;
  bool ausleihStatus;
};
#endif
