#include <iostream>
using namespace std;
 
 
 int binomial(int n, int k) 
 { 
    int erg{1}; 
    if(n< k)
       return 0;
    if(k> n - k) 
        k = n - k; 
    for (int i{0}; i < k; ++i) 
    { 
        erg *= (n - i); 
        erg /= (i + 1); 
    } 
 
    return erg;   
 } 
 
 int main()
 {
     bool weiter{true};
     while(weiter) 
     {
       int n{0}, k{0};
       cout << "Bitte geben Sie n und k ein: ";
       cin >> n >> k;
       
       if (n>0 && k >0)
          cout << "Binomialkoeffizient " << n << " ueber " << k << " ist: " << binomial(n,k) << endl;
       else 
          cout << "Falsche Eingabe!" << endl; 
 
       char mehr_eingeben;
       cout << "Wollen Sie weitere Werte eingeben? (j/n): " << endl;
       cin >> mehr_eingeben;
       weiter = mehr_eingeben == 'j';
     }
     return 0;  
 }