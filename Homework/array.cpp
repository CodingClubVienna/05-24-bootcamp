#include <iostream>
#include<string>
#include<array>
#include<vector>
using namespace std;


vector<vector<int>> frequent(char a[], int c){
    vector<vector<int>> v;
    vector<int> u;
    bool flag{false};
    
    for(int i{0}; i<c; i++)
   { 
           flag=false;
           for(int j{0}; j<c; j++) 
           { 
            if(a[i]==a[j]) 
            { 
                if(i>j) 
                {
                  flag=true;
                  break;
                }
                u.push_back(j);
            }
            
        }
        
        if(flag==false) 
        {
          v.push_back(u);
          u.clear(); 
        }        
          
    }    
  return v;   
}


int main()
{
  
   string s;
   cout << "Bitte geben Sie ein String ein: " << endl;
   cin>> s;
 
 
   
   char a[20]="";
   int c{0};
   for(int i{0}; i<s.length(); i++)
   {
      a[i]=s[i];
      c++;
   }
    
  vector<vector<int>> result = frequent(a, c);
  
  
  cout << "Laenge: " << c<< endl;
  
  cout << "{";
  for (int i{0}; i < result.size(); i++) { 
      
      if( result[i].size()!=1) 
      {
        bool first{true};
        cout << "{";
        for (auto k = result[i].begin(); k != result[i].end(); k++) 
        {
            if(first)
            {
               first=false;
               cout << *k; 
            }
            else
               cout<<", "<<*k;
        }
      cout << "}";     
      }
      
  } 
  cout << "}";

  return 0;
}