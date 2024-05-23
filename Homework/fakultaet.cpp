#include <iostream>
using namespace std;

int main () 
{
   //Dieses Programm berechnet die Fakultaet von n(n!)
   bool weiter{true};
   while(weiter) 
   {
      int n, fakultaet{1};
   
      cout << "Bitte geben Sie eine Zahl n ein: " << endl;
      cin >> n;
   
      if (n>=0) 
      {
         for (int i{1}; i<=n ;++i) 
            fakultaet*=i;
         
         cout << "Die Fakultaet von " << n << " ist: " << fakultaet << endl;
       }

      else 
         cout << "Falsche Eingabe!" << endl;
   
      char mehr_eingeben;
      cout<< "Wollen Sie weitere Werte eingeben? (j/n): ";
      cin>> mehr_eingeben;
      weiter = mehr_eingeben== 'j';
   }
   return 0;
}