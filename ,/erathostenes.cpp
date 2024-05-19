#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<bool> primzahl(int n)
{
  vector<bool>ret(n+1,true);
  ret.at(0)=false;
  ret.at(1)=false;

  int a{static_cast<int>(sqrt(n))};

  for(int i{2}; i<=a; i++) 
  {
     if(ret.at(i)) 
     {
        for(int j=i*i; j<=n; j+=i) 
          ret.at(j)= false;
      }
   } 

      
      for(int i{0}; i<=n; i++)
      {
         if (ret.at(i)) 
            cout << i << " ";
      }
      cout<<endl;
   
   return ret;
}

int main() 
{ 
    bool weiter{true};
    while(weiter) 
    {
       int n{1};
       cout << "Bitte geben Sie eine natuerliche Zahl ein: " << endl;
       cin >> n;
       if (n>0)
         primzahl(n);
       else
         throw runtime_error("Gilt nur fuer natuerliche Zahlen!");
      
       char mehr_eingeben;
       cout << "Wollen Sie weitere Werte eingeben? (j/n): " << endl;
       cin >> mehr_eingeben;
       weiter = mehr_eingeben == 'j';
    }   

    return 0; 
} 