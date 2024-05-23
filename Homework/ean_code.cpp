#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>
#include "ean_code.h"
using namespace std;

EAN_code::EAN_code(string ean): ean{ean}
{
    if(!check(ean))
       throw runtime_error("Error: Code not valid");
}

bool EAN_code::check(string ean)
{
    if(ean.size()!=13)
       return false;
    for(const auto& i: ean)   
       if(i<'0' || i>'9')
         return false;
    return true;
}

const char& EAN_code::at(size_t t) const
{
    return ean.at(t);
}

char& EAN_code::at(size_t t)
{
    return ean.at(t);
}

bool operator<(const EAN_code& ean, const EAN_code& e)
{
    size_t i;
    for(i=0; i<ean.ean.size() && ean.at(i)==e.at(i); ++i);
    return (i<ean.ean.size() && ean.at(i)<e.at(i));
}

bool operator==(const EAN_code& ean, const EAN_code& e)
{
    return !(ean<e || e<ean);
}

bool operator!=(const EAN_code& ean, const EAN_code& e)
{
    return !(ean ==e);
}

bool operator<=(const EAN_code& ean, const EAN_code& e)
{
    return (ean<e || e==ean);
}

bool operator>(const EAN_code& ean, const EAN_code& e)
{
    return (ean >e);
}

bool operator>=(const EAN_code& ean, const EAN_code& e)
{
    return (ean>e || e==ean);
}

ostream& EAN_code::print(ostream& o) const
{
    o<<ean;
    
    return o;
}

ostream& operator<<(ostream& o, const EAN_code e)
{
    return e.print(o);
}