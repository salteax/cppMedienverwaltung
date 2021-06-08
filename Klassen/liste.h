#ifndef LISTE_H
#define LISTE_H

#include <vector>
using namespace std;

template <class T>
class Liste
{
public:
  // KONSTRUKTOREN
  Liste();
  Liste(int size);
  // SETTER & GETTER
  void setSize(int i);
  int getSize();
  // FUNKTIONEN
  void addElement(T value);
  void removeElement(int i);
  T& operator[](int i);
private:
  vector<T> buffer;
  int size;
};
#endif

template <class T>
Liste<T>::Liste()
{
  size=0;
}

template <class T>
Liste<T>::Liste(int size)
{
  this->size=size;
  buffer.reserve(size);
}

template <class T>
void Liste<T>::setSize(int i)
{
  this->size=size;
}

template <class T>
int Liste<T>::getSize()
{
  return size;
}

template <class T>
void Liste<T>::addElement(T value)
{
  buffer.push_back(value);
}

template <class T>
void Liste<T>::removeElement(int i)
{
  buffer.erase(i);
}

template <class T>
T& Liste<T>::operator[](int i)
{
    return (buffer.at(i+1));
}
