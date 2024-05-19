#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <vector>
#include <string>
#include "ean_code.h"
using namespace std;

enum class Category {Clothing, Electronics, Game};
extern vector<string>category_names;

class Item 
{
  EAN_code code;
  string name;
  string description;
  int price;
  Category category;
  
  public:
  Item(EAN_code, string, string, int, Category);
  void set_code(EAN_code);
  void set_name(string);
  void set_description(string);
  void set_price(int);
  void set_category(Category);
  bool g_code(const EAN_code&) const;
  bool same_code(const Item&) const;
  bool in_category(Category);
  ostream& print(ostream& o) const;
};
ostream& operator<<(ostream& o, const Item i);

#endif