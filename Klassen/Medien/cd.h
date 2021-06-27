/************************************
*                                   *
*         Name: Paul Koreng         *
*       Matrikelnummer: 49224       *
*      Studiengruppe: 20/041/02     *
*                                   *
************************************/

#include "medium.h"

#ifndef _CD_H_
#define _CD_H_
class CD : public Medium {
public:
  // KONSTRUKTOREN
  CD();
  CD(string id, string titel, bool ausleihStatus, string ausleiher, string dauer);
  // SETTER & GETTER
  void setDauer(string dauer);
  string getDauer();
  // OPERATOR
  friend ostream& operator<<(ostream& os, CD& c);
private:
  string dauer;
};
#endif
