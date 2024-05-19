#include <iostream>
using namespace std;


int main() 
{
    double laenge{0}, breite{0};
    cout << "Bitte geben Sie die Laenge des Rechtecks ein: " << endl;
    cin >> laenge;
    cout << "Bitte geben Sie die Breite des Rechtecks ein: " << endl;
    cin >> breite;

    cout << "Der Umfang des Rechtecks mit Laenge " << laenge << " und Breite " << breite << " ist: " << 2*(laenge+breite) << endl;

    cout << "Die Flaeche des Rechtecks mit Laenge " << laenge << " und Breite " << breite << " ist: " << laenge*breite << endl;
    
    return 0;
}