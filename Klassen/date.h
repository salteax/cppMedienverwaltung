/************************************
*                                   *
*         Name: Paul Koreng         *
*       Matrikelnummer: 49224       *
*      Studiengruppe: 20/041/02     *
*                                   *
************************************/

#ifndef DATE_H
#define DATE_H
class Date {
public:
  // KONSTRUKTOREN
  Date();
  Date(int jahr, int monat, int tag);
  // SETTER & GETTER
  void setJahr(int jahr);
  int getJahr();
  void setMonat(int monat);
  int getMonat();
  void setTag(int tag);
  int getTag();
  friend ostream &operator<<(ostream &os, const Date &d);
private:
  int jahr, monat, tag;
};
#endif
