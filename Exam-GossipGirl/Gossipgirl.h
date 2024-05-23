#ifndef GOSSIPGIRL_H
#define GOSSIPGIRL_H

#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
using namespace std;

enum class Ortsteil{Hudson, Queens, Bronx, Brooklyn, Manhattan};
const vector<string> ortsteil_list{"Hudson", "Queens", "Bronx", "Brooklyn", "Manhattan"};

class Gossipgirl
{
    private:
        string vorname;
        string zuname;
        Ortsteil ortsteil;

    public:
        Gossipgirl(string vorname, string zuname, Ortsteil ortsteil = Ortsteil::Manhattan);
        bool uebersiedeln (const Ortsteil&);
        int bekanntheitsgrad() const;
        bool operator==(const Gossipgirl&) const;
        friend ostream& operator<<(ostream&, const Gossipgirl&);
};

#endif // GOSSIPGIRL_H

