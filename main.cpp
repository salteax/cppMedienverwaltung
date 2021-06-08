#include <iostream>
#include <iomanip>
using namespace std;
#include "./Klassen/person.h"
#include "./Klassen/date.h"
#include "./Klassen/Medien/medium.h"
#include "./Klassen/Medien/cd.h"

int main(int argc, char*argv[])
{
  //g++ .\main.cpp .\Klassen\person.cpp .\Klassen\date.cpp
  Person p1;
  Date aD;
  Date rD;

  CD cd1("Titel",aD,rD,true,"p001",30);

  cout << cd1.getTitel();

  return 0;
}
