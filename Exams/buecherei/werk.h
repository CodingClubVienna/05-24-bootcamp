#ifndef WERK_H 
#define WERK_H

#include<iostream>
#include<string>
#include<vector> 

#include"exemplar.h"

using namespace std; 

class Werk{
private:
    string autor; 
    string name; 
    int erscheinungsjahr; 
    vector<Exemplar> exemplare; 

public: 
    Werk(string author, string name, int jahr); 
    void erwerben(int nr, Zustand z); 
    bool entleihen(); 
    void retournieren(int index, Zustand z); 
    static vector<Werk> erstausgaben(const vector<Werk>& bestand);
    static void aussortieren(vector<Werk>& bestand); 
    ostream& print(ostream& o) const; 
}; 

ostream& operator<<(ostream& o, const Werk w); 

#endif