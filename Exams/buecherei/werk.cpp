#include<iostream>

#include"werk.h"

using namespace std; 

Werk::Werk(string autor, string name, int jahr): autor{autor}, name{name}, erscheinungsjahr{jahr} {
    if(autor.empty()) 
        throw runtime_error("Autor can't be empty");
    if(name.empty())
        throw runtime_error("Name can't be empty"); 
    if(erscheinungsjahr < 1700 || erscheinungsjahr > 2017)
        throw runtime_error("Erscheinungsjahr not in valid range >=1700 and <=2017"); 

    // The vector "exemplare" is automatically initialized as empty by the vector's default constructor
}

void Werk::erwerben(int nr, Zustand z){
    if(z == Zustand::Unbrauchbar)
        throw runtime_error("Not possible to obtain an exemplar unbrauchbar"); 

    Exemplar temp(nr, z); 
    exemplare.push_back(temp); 
}

bool Werk::entleihen(){
    for(auto& exemplar : exemplare){
        if (exemplar.entleihen()) 
            return true;
    }

    return false; 
}

void Werk::retournieren(int index, Zustand z){
    if (index < 0 || index >= exemplare.size()) {
        throw runtime_error("Invalid index");
    }

    exemplare.at(index).retournieren(z); 
}

vector<Werk> Werk::erstausgaben(const vector<Werk>& bestand){
    std::vector<Werk> result;
    for (const auto& werk : bestand) {        
        for (const auto& exemplar : werk.exemplare) {
            if (exemplar.getAuflagennummer() == 1) {
                result.push_back(werk);

                // once a first edition of the current work is found => terminate loop over werk.exemplare & move to next werk (outer loop)
                break;
            }
        }
    }
    return result;
}

void Werk::aussortieren(vector<Werk>& bestand){
    vector<Exemplar> temp_exemplar; 

    for(auto& werk: bestand) {
        for(auto& exemplar : werk.exemplare) {
            if(exemplar.getZustand() != Zustand::Unbrauchbar) 
            temp_exemplar.push_back(exemplar);
        }
        werk.exemplare = temp_exemplar;
        temp_exemplar.clear();
    }

}

ostream& Werk::print(ostream& o) const{

    o <<  "[" << autor << ", " << name << ", " << erscheinungsjahr << " {"; 
    
    for(size_t i{0}; i < exemplare.size(); ++i){

        o << exemplare.at(i); 

        // add a comma and space after each element except for the last one when outputting a list of elements
        if(i < exemplare.size()-1)
            o << ", "; 
    }
    o << "}]"; 

    return o; 
}

ostream& operator<<(ostream& o, Werk w){
    return w.print(o); 
}