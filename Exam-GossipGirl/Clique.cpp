#include "clique.h"

Clique::Clique(string name, vector<Gossipgirl>liste): name{name}, liste{liste}
{
    if(name.empty() || liste.empty()) throw runtime_error("Error!");
}

bool Clique::check(const Gossipgirl& gg_objekt) const
{
    for(size_t i = 0; i<liste.size(); i++)
    {
        if(liste.at(i)==gg_objekt)
            return true;
    }
    return false;
}

double Clique::durchschnitt_bekanntheit() const
{
    double sum = 0;
    for(size_t i = 0; i<liste.size(); i++)
    {
        sum+=liste.at(i).bekanntheitsgrad();
    }
    sum/=liste.size();
    return sum;
}

bool Clique::hinzufuegen(const Gossipgirl& gg_objekt)
{
    for(size_t i = 0; i<liste.size(); i++)
    {
        if(liste.at(i)==gg_objekt) return false;
    }
    liste.push_back(gg_objekt);
    return true;
}

void Clique::entfernen()
{
    vector<Gossipgirl>entfertnt;
    for(size_t i = 0; i<liste.size(); i++)
    {
        double neu = durchschnitt_bekanntheit();
        if(liste.at(i).bekanntheitsgrad()>=neu)
        {
            entfertnt.push_back(liste.at(i));
        }
    }
    liste.clear();
    for(size_t i = 0; i<entfertnt.size(); i++)
    {
        liste.push_back(entfertnt.at(i));
    }
}

void Clique::aufnehmen(const vector<Gossipgirl>& v, bool fame)
{
    if(!fame)
    {
        for(size_t i = 0; i<v.size(); i++)
        {
            if(!check(v.at(i)))
            {
                liste.push_back(v.at(i));
            }
        }
    }
    if(fame)
    {
        vector<Gossipgirl>entfernt;
        double ccc = durchschnitt_bekanntheit();
        for(size_t i = 0; i<v.size(); i++)
        {
            if(!check(v.at(i)) && v.at(i).bekanntheitsgrad()>=ccc)
            {
                liste.push_back(v.at(i));
            }
        }
    }
}


/*[UpperEastSiders, f[Serena, van der Woodsen, Manhattan, 19], [Daniel, Humphrey, Brooklyn, 11]g].*/
ostream& operator<<(ostream& os, const Clique cl)
{
    os << "[" << cl.name << ", {";
    for(size_t i = 0; i<cl.liste.size(); i++)
    {
        os << cl.liste.at(i);
        if(i!=cl.liste.size()-1)
        {
            os << ", ";
        }
    }
    return os << "}]";
}
