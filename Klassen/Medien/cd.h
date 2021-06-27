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
  CD(string id, string titel, bool ausleihStatus, string ausleiher, int dauer);
  // SETTER & GETTER
  void setDauer(int dauer);
  int getDauer();
  // OPERATOR
  friend ostream& operator<<(ostream& os, CD& c);
private:
  int dauer;
};
#endif
