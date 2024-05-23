#include "gossipgirl.h"


Gossipgirl::Gossipgirl(string vorname, string zuname, Ortsteil ortsteil): vorname{vorname}, zuname{zuname}, ortsteil{ortsteil}
{
    if(ortsteil==Ortsteil::Hudson || vorname.empty() || zuname.empty()) throw runtime_error("Error in gossip constructor!");
}

bool Gossipgirl::uebersiedeln (const Ortsteil& neu){
if(neu==ortsteil) return false;
else{
    ortsteil=neu;
    return true;
}
}

int Gossipgirl::bekanntheitsgrad() const{
int gesamt_summe=0;
int summe_zuname=zuname.size();
gesamt_summe=summe_zuname + (int)ortsteil;
return gesamt_summe;

}

bool Gossipgirl::operator==(const Gossipgirl& val) const{
if(val.vorname==vorname && val.zuname == zuname && val.ortsteil == ortsteil){
    return true;
}
return false;
}

/*z.B.: [Serena, van der Woodsen, Manhattan, 19].*/

ostream& operator<<(ostream& o, const Gossipgirl& val){
    o << "[" << val.vorname << ", " << val.zuname << "," << ortsteil_list.at(static_cast<int>(val.ortsteil));
    return o << ", " << val.bekanntheitsgrad() << "]";
}
