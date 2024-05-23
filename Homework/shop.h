#ifndef SHOP_H
#define SHOP_H

#include <iostream>
#include <string>
#include <vector>
#include "ean_code.h"
#include "item.h"
using namespace std;

class Shop 
{
  string url;
  string bezeichnung;
  string road;
  string street_number;
  string zip_code;
  string city;
  vector<Item> items;
  
  public:
  Shop(string, string, string, string, string , string, vector<Item>);
  Item& find_item(const EAN_code& c);
  void add_item(const Item& i);
  bool del_item(const EAN_code& c);
  ostream& print(ostream& o) const;
};
ostream& operator<<(ostream& o, const Shop s1);

#endif