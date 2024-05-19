#include <iostream>
using namespace std;

int main ()
{
  int zahl{0};
  cout << "Bitte geben Sie eine dreistellige Zahl ein: " << endl;
  cin >> zahl;
  if (zahl>99 && zahl<1000)
     cout << zahl%10 << zahl/10%10 << zahl/100%10 << endl;
  else 
     cout << "Falsche Eingabe!" << endl;

  return 0;
}