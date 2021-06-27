/************************************
*                                   *
*         Name: Paul Koreng         *
*       Matrikelnummer: 49224       *
*      Studiengruppe: 20/041/02     *
*                                   *
************************************/

#include "../person.h"
#include "../date.h"
#include "medium.h"

#ifndef _DVD_H_
#define _DVD_H_
class DVD : public Medium {
public:
  // KONSTRUKTOREN
  DVD();
  DVD(string id, string titel, bool ausleihStatus, string ausleiher, int fsk, int dauer, string genre);
  // SETTER & GETTER
  void setFSK(int fsk);
  int getFSK();
  void setDauer(int dauer);
  int getDauer();
  void setGenre(string genre);
  string getGenre();
  // OPERATOR
  friend ostream& operator<<(ostream& os, DVD& d);
private:
  int fsk, dauer;
  string genre;
};
#endif
