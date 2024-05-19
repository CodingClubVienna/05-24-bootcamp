#include <iostream>
using namespace std;
 
int ackermann(int m, int n)
{
    if (m==0) 
       return n+1;
    else if((m>0) && (n==0)) 
       return ackermann(m-1,1);
    else if((m>0) && (n>0))
       return ackermann(m-1, ackermann(m, n-1));
    else
       throw runtime_error("Ackermann fuer negative Zahlen nicht definiert!");
}
 
int main()
{
  bool weiter{true};
  while(weiter) 
  {
     int m{0}, n{0};
     cout << "Geben Sie m ein: ";
     cin >> m;
     cout << "Geben Sie n ein: ";
     cin >> n;
     cout << ackermann(m,n) << endl;

     char mehr_eingeben;
     cout << "Wollen Sie weitere Werte eingeben? (j/n): " << endl;
     cin >> mehr_eingeben;
     weiter = mehr_eingeben == 'j';
  } 
  return 0;
}