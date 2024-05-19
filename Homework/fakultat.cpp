#include <iostream>
using namespace std;

int fakultaet (int n)
{
  return n>=0 ? (1<=n ? n*fakultaet(n-1) : 1) : 0;
}

int main()
{
  bool weiter{true};
  while(weiter) {   //Die Schleife wuerde verwendet, da beeinflusst die Loesung der eigentlichen Aufgabestellung nicht
     int n;
     cout << "Bitte geben Sie eine Zahl n ein: " << endl;
     cin >> n;
  
     fakultaet(n) != 0 ? cout << fakultaet(n) << endl : cout << "Falsche Eingabe!" << endl;
  
     char mehr_eingeben;
     cout<< "Wollen Sie weitere Werte eingeben? (j/n): ";
     cin>> mehr_eingeben;
     weiter = mehr_eingeben== 'j';
   } 

  return 0;
}