#include<iostream>
#include<vector>
#include<string>
#include "ean_code.h"
#include "item.h"
#include "shop.h"
using namespace std;

int main()
{
    
vector<string> EAN_code_strings{"1234567890123","1111","12345678901234","9999999999999","123456789012X\n",
                   "123123123123","1234567890128","abcdefghijklm","1234567890129",
		   "1234567890120","1234567890121","1234567890122"};
		   
for(const auto& code: EAN_code_strings)
   try {
       cout<< EAN_code{code} << "ist gueltig\n";
   }
   catch(runtime_error& e) {
       cerr<< e.what()<< ' '<<code<< '\n';
   }
   
   cout<<'\n';
   try {
      Item item1{EAN_code{"123123123123"},
		"Bonbonniere",
		"Dieser Artikel sollte nicht erzeugt werden (ungueltiger EAN_code)",
		2540, Category::Game}; 
   }
   catch(runtime_error& e) {
       cerr<< "Error1" <<e.what()<<'\n';
   }
   
   try {
      Item item2{EAN_code{"1234567890128"},
		"",
		"Dieser Artikel sollte nicht erzeugt werden (ungueltige Bezeichnung)",
		2540, Category::Game};
   }
   catch(runtime_error& e) {
       cerr<< "Error2" <<e.what()<<'\n';
   }
   
   try {
      Item item3{EAN_code{"1234567890128"},
		"Bonbonniere",
		"Dieser Artikel sollte nicht erzeugt werden (ungueltiger Preis)",
		1564, Category::Electronics};
	  item3.set_name("Bonbons");
      cout<< item3<<'\n';
      item3.set_name("");	
   }
   catch(runtime_error& e) {
       cerr<< "Error3" <<e.what()<<'\n';
   }
   
   /*try {
      Item item4{EAN_code{"1234567890128"},
		"Bonbonniere",
		"Dieser Artikel sollte nicht erzeugt werden (ungueltiger Preis, Compilerfehler)",
		11111111111111111111, Category::Clothing};
   }
   catch(runtime_error& e) {
       cerr<< "Error4" <<e.what()<<'\n';
   }*/
   cout<< '\n';


Shop shop{"https://buyhere.com","Der beste Shop","Rabattstrasse","80","4780","Billigsdorf",{
                Item{EAN_code{"1234567890128"},
		"Bonbonniere",
		"24 exquisite Schokoladestuecke + eine Ueberraschung",
		2540, Category::Game},
		Item{EAN_code{"1234567890129"},
		"Bonbonniere (einzeln)",
		"",
		99, Category::Clothing},
		Item{EAN_code{"1234567890120"},
		"Spezialmischung",
		"Limitierte Sonderauflage",
		4999, Category::Electronics},
		Item{EAN_code{"1234567890121"},
		"Spezialmischung (Doppelpackung)",
		"Unser Motto: Mehr essen und dabei gewaltig sparen!",
		9000, Category::Game},
		Item{EAN_code{"1234567890122"},
		"Spezialmischung (Familienpackung)",
		"Achtung: Fuer Haustiere ungeeignet!",
		11500, Category::Game},
		Item{EAN_code{"1234567890121"},
		"Unbekannter Artikel",
		"Dieser Artikel sollte nicht eingefuegt werden (EAN_code schon vorhanden)",
		10000, Category::Clothing}
             }};
             
    shop.add_item(Item{EAN_code{"1234567890122"},
		"Spezialmischung (Familienpackung)",
		"Achtung: Fuer Haustiere ungeeignet!",
		11500, Category::Game});      
	
	cout<< " deleted items: " <<shop.del_item(EAN_code{"1234567890122"})<<endl;	
    cout<<'\n'<< shop<<'\n';

    return 0;
}
