/************************************
*                                   *
*         Name: Paul Koreng         *
*       Matrikelnummer: 49224       *
*      Studiengruppe: 20/041/02     *
*                                   *
************************************/

#include "medium.h"

#ifndef _DVD_H_
#define _DVD_H_
class DVD : public Medium {
public:
  // KONSTRUKTOREN
  DVD();
  DVD(string id, string titel, bool ausleihStatus, string ausleiher, string dauer, string genre);
  // SETTER & GETTER
  void setDauer(string dauer);
  string getDauer();
  void setGenre(string genre);
  string getGenre();
  // OPERATOR
  friend ostream& operator<<(ostream& os, DVD& d);
private:
  string fsk, dauer, genre;
};
#endif
