/************************************
*                                   *
*         Name: Paul Koreng         *
*       Matrikelnummer: 49224       *
*      Studiengruppe: 20/041/02     *
*                                   *
************************************/

#ifndef _PERSON_H_
#define _PERSON_H_
class Person
{
public:
    // KONSTRUKTOREN
    Person();
    Person(string pid, string vorname, string nachname);
    // SETTER & GETTER
    void setPID(string pid);
    string getPID();
    void setVorname(string vorname);
    string getVorname();
    void setNachname(string nachname);
    string getNachname();
    // OPERATOR
    friend ostream& operator<<(ostream& os, Person& p);
private:
    string pid, vorname, nachname, geschlecht;
};
#endif
