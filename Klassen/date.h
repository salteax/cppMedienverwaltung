#ifndef DATE_H
#define DATE_H
class Date
{
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
private:
    int jahr, monat, tag;
};
#endif
