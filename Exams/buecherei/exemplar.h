#ifndef EXEMPLAR_H
#define EXEMPLAR_H

#include<iostream>
#include<string> 
#include<vector>

using namespace std; 

enum class Zustand {Neuwertig, Gut, Abgegriffen, Unbrauchbar}; 

class Exemplar{
private:
    int auflagennummer; 
    Zustand zustand; 
    bool verliehen; 

    static const vector<string> zustand_namen;

public:
        Exemplar(int nr, Zustand z = Zustand::Neuwertig); 

        bool verfuegbar() const; 
        bool entleihen(); 
        void retournieren(Zustand z); 
        ostream& print(ostream& o) const; 

        int getAuflagennummer() const; 
        Zustand getZustand() const; 
}; 

ostream& operator<<(ostream& o, const Exemplar e1); 

#endif