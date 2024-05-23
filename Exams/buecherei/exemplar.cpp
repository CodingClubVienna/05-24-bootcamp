#include<iostream>

#include"exemplar.h"

using namespace std; 

const vector<string> Exemplar::zustand_namen = { "neuwertig", "gut", "abgegriffen", "unbrauchbar" };

Exemplar::Exemplar(int nr, Zustand z) : auflagennummer(nr), zustand(z), verliehen(false) {
    if(nr < 1 || nr > 1000 )
        throw runtime_error("Error: auflagennummer not within valid range >=1 und <=1000"); 
}

bool Exemplar::verfuegbar() const{
    return !verliehen && zustand != Zustand::Unbrauchbar;
}

bool Exemplar::entleihen(){
    if(this->verfuegbar()){
        verliehen = true; 
        return true; 
    } else
        return false; 
}

void Exemplar::retournieren(Zustand z) {
    if(!verliehen)
        throw runtime_error("Error: exemplar was not verliehen");
    
    if(z < zustand) {
        throw std::runtime_error("Error: Zustand can't improve");
    }

    zustand = z; 
    verliehen = false; 
}

int Exemplar::getAuflagennummer() const{
    return auflagennummer; 
}

Zustand Exemplar::getZustand() const{
    return zustand; 
}

ostream& Exemplar::print(ostream& o) const{
    o << "[Auflage: " << auflagennummer << ", Zustand: " << zustand_namen.at(static_cast<int>(zustand));  
    if(verliehen)
        o << ", verliehen"; 
    o << "]";   

    return o; 
}

ostream& operator<<(ostream& o, Exemplar e1){
    return e1.print(o); 
}