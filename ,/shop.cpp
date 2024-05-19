#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include "ean_code.h"
#include "item.h"
#include "shop.h"
using namespace std;

Shop::Shop(string url, string bezeichnung, string road, string street_number, string zip_code, string city, vector<Item> items):
           url{url}, bezeichnung{bezeichnung}, road{road}, street_number{street_number}, zip_code{zip_code}, city{city}, items{items}
{
    if(url.empty() || bezeichnung.empty() || road.empty() || street_number.empty() || zip_code.empty() || city.empty() || items.empty())
       throw runtime_error("Error: Incorrect parameter");
    for(const auto& i: items)
       add_item(i);
}

Item& Shop::find_item(const EAN_code& c)
{
    for(auto& i: items)
    {
        if(i.g_code(c))
          return i;
    }
    throw runtime_error("Error: Not found");
}

void Shop::add_item(const Item& i)
{
    for(const auto& i: items)
    {
        bool help{false};
        for(const auto& j: items)
        {
            if(i.same_code(j))
            {
              help=true;
              break;
            }
        }
        if(!help)
          items.push_back(i);
    }
}

bool Shop::del_item(const EAN_code& c)
{
    vector<Item> help;
    bool help1{false};
    for(const auto& j: items)
    {
        if(j.g_code(c))
          return true;
        else
        {
          help.push_back(j);
          return false;
        }
    }
    items=help;
}

ostream& Shop::print(ostream& o) const
{
    bool first{true};
    o<<url<<endl<<bezeichnung<<endl<<road<<" "<<street_number<<endl<<zip_code<<" "<<city<<endl<<"..."<<endl;
    for(const auto& i: items)
    {
        if(first)
        {
          o<<i<<endl;
          first=false;
        }
        else
          o<<endl<<i<<endl;
    }
    o<<"---";
    
    return o;
}

ostream& operator<<(ostream& o, const Shop s1)
{
    return s1.print(o);
}