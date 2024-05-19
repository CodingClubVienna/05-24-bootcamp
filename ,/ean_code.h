#ifndef EAN_CODE_H
#define EAN_CODE_H

#include <iostream>
#include <string>
using namespace std;

class EAN_code
{
  string ean;  
  
  public:
  EAN_code(string);
  bool check(string);
  const char& at(size_t) const;
  char& at(size_t);
  friend bool operator<(const EAN_code&, const EAN_code&);
  friend bool operator==(const EAN_code&, const EAN_code&);
  friend bool operator!=(const EAN_code&, const EAN_code&);
  friend bool operator<=(const EAN_code&, const EAN_code&);
  friend bool operator>(const EAN_code&, const EAN_code&);
  friend bool operator>=(const EAN_code&, const EAN_code&);
  ostream& print(ostream& o) const;
};
ostream& operator<<(ostream& o, const EAN_code e);

#endif