#include <iostream>
#include<string>
#include<array>
using namespace std;



char* containsCharArray(char arr1[], char arr2[])
{
 int count{0};
 char *p{nullptr};
 bool first{true};
 int length{0};
 
 for(int i{0}; arr2[i] != '\0'; i++)
 {
   length++; 
 }
 
   for(int i{0}; arr1[i] != '\0'; i++)
   { 
      int k{i};
      int cnt{0};
      for(int j{0}; arr2[j] != '\0'; j++)
      {
          if(arr1[k] == arr2[j])
          {
             k++;
             cnt++; 
          }  
          
      } 
      if(cnt == length) 
      {
        count++;
        if(first)
        {
                 p=&arr1[i];
                 first=false;
         }
      }
   
   } 
 cout<<"Die zweite Zeichenkette ist "<<count<< " mal in der ersten enthalten "<<endl;
 return p;
}

int main()
{
  
   string s1, s2;
   cout << "Bitte geben Sie zwei Strings ein: " << endl;
   cin>> s1>>s2;
   
   char arr1[20]="", arr2[20]="";
   
   for(int i=0; i<s1.length(); i++)
   {
      arr1[i]=s1[i];
   }
   
   for(int i=0; i<s2.length(); i++)
   {
      arr2[i]=s2[i];
   }
   
   char* n = containsCharArray(arr1, arr2);
   
   if(n==nullptr)
     cout << "Die zweite Zeichenkette ist nicht enthalten" <<endl;
   else
     cout << "Erste Auftritt: "<<n<<endl;
   
   return 0;
}