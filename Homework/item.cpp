#include <iostream>
#include <vector>
#include <string>
#include "ean_code.h"
#include "item.h"
using namespace std;

vector<string>category_names{"Clothing", "Electronics", "Game"};

Item::Item (EAN_code code, string name, string description, int price, Category category):
  code{code}, name{name}, description{description}, price{price}, category{category}
{
  if (name.empty ())
    throw runtime_error ("Error: Name can't be empty");
  if (price <= 0)
    throw runtime_error ("Error: Price must be positive");
}

void Item::set_code(EAN_code code)
{
   this->code=code;
}

void Item::set_name(string name)
{
    if (name.empty ())
       throw runtime_error ("Error: Name can't be empty");
    this->name=name;
}

void Item::set_description(string description)
{
    this->description=description;
}

void Item::set_price(int price)
{
    if (price <= 0)
       throw runtime_error ("Error: Price must be positive");
    this->price=price;
}

void Item::set_category(Category category)
{
    this->category=category;
}

bool Item::g_code(const EAN_code& code) const
{
    return this->code==code;
}

bool Item::same_code(const Item& i) const
{
    return code==i.code;
}

bool Item::in_category(Category category)
{
    return this->category==category;
}

ostream & Item::print (ostream & o) const
{
  o << code << ": " << name << " " << price / 100 << ",";
  if (price % 100 < 10)
    o << "0";
  else
    o << "";

  o << price % 100 << " Euro" << endl << description<<endl<< category_names.at(static_cast<size_t>(category));

  return o;
}

ostream & operator<< (ostream & o, const Item i)
{
  return i.print (o);
}
