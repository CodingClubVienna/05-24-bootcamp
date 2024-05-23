#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>

#include "exemplar.h"
#include "werk.h"

// Redefine the main function from the original code
int original_main();

int main() {
    // Redirect standard output to a stringstream
    std::stringstream buffer;
    std::streambuf* old_cout = std::cout.rdbuf(buffer.rdbuf());
    std::streambuf* old_cerr = std::cerr.rdbuf(buffer.rdbuf());

    // Call the original main function
    try {
        original_main();
    } catch (...) {
        std::cout.rdbuf(old_cout);
        std::cerr.rdbuf(old_cerr);
        std::cerr << "The original main function threw an exception." << std::endl;
        return 1;
    }

    // Restore the standard output
    std::cout.rdbuf(old_cout);
    std::cerr.rdbuf(old_cerr);

    // The expected output
    std::string expected_output =
        "Error1\n"
        "[Auflage: 1, Zustand: neuwertig]\n"
        "[Auflage: 1, Zustand: neuwertig]\n"
        "Error3\n"
        "[Auflage: 2, Zustand: gut]\n"
        "[Auflage: 2, Zustand: gut]\n"
        "verfuegbar\n"
        "entliehen\n"
        "[Auflage: 2, Zustand: gut, verliehen]\n"
        "Zustand kann nicht besser werden!\n"
        "[Auflage: 2, Zustand: abgegriffen]\n"
        "wieder entliehen\n"
        "[Auflage: 2, Zustand: abgegriffen, verliehen]\n"
        "[Auflage: 2, Zustand: abgegriffen]\n"
        "[Auflage: 1000, Zustand: gut]\n"
        "[Auflage: 1000, Zustand: gut]\n"
        "verfuegbar\n"
        "entliehen\n"
        "[Auflage: 1000, Zustand: unbrauchbar]\n"
        "Error8\n"
        "Error9\n"
        "Error10\n"
        "Error11\n"
        "Error12\n"
        "Error13\n"
        "Error14\n"
        "+++--\n"
        "Failed 2\n"
        "Failed 3\n"
        "\n"
        "[Adams, Hitchhiker, 1979 {[Auflage: 1, Zustand: gut], [Auflage: 1, Zustand: gut], [Auflage: 2, Zustand: abgegriffen, verliehen]}]\n"
        "[Adams, Hitchhiker, 1979 {[Auflage: 1, Zustand: gut], [Auflage: 1, Zustand: gut], [Auflage: 2, Zustand: abgegriffen, verliehen]}]\n"
        "[Stroustrup, C++, 2014 {[Auflage: 2, Zustand: neuwertig], [Auflage: 2, Zustand: neuwertig], [Auflage: 4, Zustand: neuwertig], [Auflage: 3, Zustand: neuwertig]}]\n"
        "[Stroustrup, C++, 2014 {[Auflage: 2, Zustand: neuwertig], [Auflage: 2, Zustand: neuwertig], [Auflage: 4, Zustand: neuwertig], [Auflage: 3, Zustand: neuwertig]}]\n"
        "[Meyers, Effective STL, 2001 {[Auflage: 2, Zustand: neuwertig], [Auflage: 1, Zustand: neuwertig], [Auflage: 1, Zustand: neuwertig], [Auflage: 3, Zustand: neuwertig]}]\n"
        "[Meyers, Effective STL, 2001 {[Auflage: 2, Zustand: neuwertig], [Auflage: 1, Zustand: neuwertig], [Auflage: 1, Zustand: neuwertig], [Auflage: 3, Zustand: neuwertig]}]\n"
        "[Eisenmenger, Entdecktes, 1700 {}]\n"
        "[Eisenmenger, Entdecktes, 1700 {}]\n"
        "[Kagawa, Talon, 2017 {}]\n"
        "[Kagawa, Talon, 2017 {}]\n"
        "[Kafka, Verwandlung, 1912 {[Auflage: 2, Zustand: neuwertig], [Auflage: 1, Zustand: neuwertig]}]\n"
        "[Kafka, Verwandlung, 1912 {[Auflage: 2, Zustand: neuwertig], [Auflage: 1, Zustand: neuwertig]}]\n"
        "\nZusatz erstausgaben\n"
        "[Adams, Hitchhiker, 1979 {[Auflage: 1, Zustand: gut], [Auflage: 1, Zustand: gut], [Auflage: 2, Zustand: abgegriffen, verliehen]}]\n"
        "[Meyers, Effective STL, 2001 {[Auflage: 2, Zustand: neuwertig], [Auflage: 1, Zustand: neuwertig], [Auflage: 1, Zustand: neuwertig], [Auflage: 3, Zustand: neuwertig]}]\n"
        "[Kafka, Verwandlung, 1912 {[Auflage: 2, Zustand: neuwertig], [Auflage: 1, Zustand: neuwertig]}]\n"
        "\nZusatz ausortieren\n"
        "[Adams, Hitchhiker, 1979 {[Auflage: 1, Zustand: gut], [Auflage: 1, Zustand: gut], [Auflage: 2, Zustand: unbrauchbar]}]\n"
        "[Stroustrup, C++, 2014 {[Auflage: 2, Zustand: neuwertig, verliehen], [Auflage: 2, Zustand: unbrauchbar], [Auflage: 4, Zustand: unbrauchbar], [Auflage: 3, Zustand: neuwertig, verliehen]}]\n"
        "[Meyers, Effective STL, 2001 {[Auflage: 2, Zustand: neuwertig], [Auflage: 1, Zustand: neuwertig], [Auflage: 1, Zustand: neuwertig], [Auflage: 3, Zustand: neuwertig]}]\n"
        "[Eisenmenger, Entdecktes, 1700 {}]\n"
        "[Kagawa, Talon, 2017 {[Auflage: 4, Zustand: unbrauchbar]}]\n"
        "[Kafka, Verwandlung, 1912 {[Auflage: 2, Zustand: unbrauchbar], [Auflage: 1, Zustand: neuwertig]}]\n"
        "[Adams, Hitchhiker, 1979 {[Auflage: 1, Zustand: gut], [Auflage: 1, Zustand: gut]}]\n"
        "[Stroustrup, C++, 2014 {[Auflage: 2, Zustand: neuwertig, verliehen], [Auflage: 3, Zustand: neuwertig, verliehen]}]\n"
        "[Meyers, Effective STL, 2001 {[Auflage: 2, Zustand: neuwertig], [Auflage: 1, Zustand: neuwertig], [Auflage: 1, Zustand: neuwertig], [Auflage: 3, Zustand: neuwertig]}]\n"
        "[Eisenmenger, Entdecktes, 1700 {}]\n"
        "[Kagawa, Talon, 2017 {}]\n"
        "[Kafka, Verwandlung, 1912 {[Auflage: 1, Zustand: neuwertig]}]\n";

    // Get the output from the buffer
    std::string actual_output = buffer.str();

    // Compare the actual output with the expected output
    if (actual_output == expected_output) {
        std::cout << "Test passed!" << std::endl;
    } else {
        std::cerr << "Test failed!" << std::endl;
        std::cerr << "Expected output:" << std::endl;
        std::cerr << expected_output << std::endl;
        std::cerr << "Actual output:" << std::endl;
        std::cerr << actual_output << std::endl;
    }
    return 0;
}

int original_main() {
    // Original main code goes here
    try {
        Exemplar e{0, Zustand::Unbrauchbar};
        cout << e << '\n';
    }
    catch (runtime_error&) {
        cout << "Error1\n";
    }

    try {
        Exemplar e{1};
        cout << e << '\n';
        cerr << e << '\n';
    }
    catch (runtime_error&) {
        cout << "Error2\n";
    }
    try {
        Exemplar e{1001};
        cout << e << '\n';
    }
    catch (runtime_error&) {
        cout<<"Error3\n";
    }


  try {
    Exemplar e{2, Zustand::Gut};
    cout << e << '\n';
    cerr << e << '\n';
    if (e.verfuegbar()) cout << "verfuegbar\n";
    if (e.entleihen()) cout << "entliehen\n";
    if (e.verfuegbar()) cout << "verfuegbar\n";
    if (e.entleihen()) cout << "entliehen\n";
    cout << e << '\n';
    try {
      e.retournieren(Zustand::Neuwertig);
    }
    catch (runtime_error&) {
      cout << "Zustand kann nicht besser werden!\n";
    }
    try {
      e.retournieren(Zustand::Abgegriffen);
    }
    catch (runtime_error&) {
      cout << "Error4\n";
    }
    cout << e << '\n';
    if (e.entleihen()) cout << "wieder entliehen\n";
    cout << e << '\n';
    try {
      e.retournieren(Zustand::Abgegriffen);
    }
    catch (runtime_error&) {
      cout << "Error5\n";
    }
    cout << e << '\n';
    }
    catch (runtime_error&) {
        cout << "Error6\n";
    }
    try {
        Exemplar e{1000, Zustand::Gut};
        cout << e << '\n';
        cerr << e << '\n';
        if (e.verfuegbar()) cout << "verfuegbar\n";
        if (e.entleihen()) cout << "entliehen\n";
        e.retournieren(Zustand::Unbrauchbar);
        if (e.verfuegbar()) cout << "verfuegbar\n";
        if (e.entleihen()) cout << "entliehen\n";
        cout << e << '\n';
    }
    catch (runtime_error&) {
        cout << "Error7\n";
    }



    vector<Werk> bestand;
    try {
        bestand.push_back(Werk{"Adams","Hitchhiker",1979});
        bestand.push_back(Werk{"Musil","",1915});
    }
    catch (runtime_error&) {
        cout << "Error8\n";
    }
    try {
        bestand.push_back(Werk{"Stroustrup","C++",2014});
        bestand.push_back(Werk{"Gutenberg","Bibel",1450});
    }
    catch (runtime_error&) {
        cout << "Error9\n";
    }
    try {
        bestand.push_back(Werk{"Meyers","Effective STL",2001});
        bestand.push_back(Werk{"","Mann ohne Eigenschaften",1915});
    }
    catch (runtime_error&) {
        cout << "Error10\n";
    }
    try {
        bestand.push_back(Werk{"Eisenmenger","Entdecktes",1700});
        bestand.push_back(Werk{"Kagawa","Talon",2017});
        bestand.push_back(Werk{"Martin","GoT 6/11",2018});
    }
    catch (runtime_error&) {
        cout << "Error11\n";
    }
    try {
        bestand.push_back(Werk{"Kafka","Verwandlung",1912});
        bestand.push_back(Werk{"Goldmann","Baukunst",1699});
    }
    catch (runtime_error&) {
        cout << "Error12\n";
    }

    try {
        bestand.at(0).erwerben(1,Zustand::Neuwertig);
        bestand.at(0).erwerben(1,Zustand::Gut);
        bestand.at(0).erwerben(2,Zustand::Abgegriffen);
        bestand.at(0).erwerben(3,Zustand::Unbrauchbar);
    }
    catch (runtime_error&) {
        cout << "Error13\n";
    }
    try {
        bestand.at(1).erwerben(-1,Zustand::Neuwertig);
    }
    catch (runtime_error&) {
        cout << "Error14\n";
    }
    for (int i{0}; i<4; ++i)
        cout << (bestand.at(0).entleihen()?'+':'-');
    cout << (bestand.at(2).entleihen()?'+':'-');
    cout << '\n';

    //change to i < 4 for error
    for (int i{0}; i<4; ++i)
        try {
        bestand.at(0).retournieren(i,Zustand::Gut);
        }
        catch (runtime_error&) {
        cout << "Failed " << i << '\n';
        }
    cout << '\n';
    
    bestand.at(1).erwerben(2,Zustand::Neuwertig);
    bestand.at(1).erwerben(2,Zustand::Neuwertig);
    bestand.at(1).erwerben(4,Zustand::Neuwertig);
    bestand.at(1).erwerben(3,Zustand::Neuwertig);
    bestand.at(2).erwerben(2,Zustand::Neuwertig);
    bestand.at(2).erwerben(1,Zustand::Neuwertig);
    bestand.at(2).erwerben(1,Zustand::Neuwertig);
    bestand.at(2).erwerben(3,Zustand::Neuwertig);
    bestand.at(5).erwerben(2,Zustand::Neuwertig);
    bestand.at(5).erwerben(1,Zustand::Neuwertig);
    for (const Werk& w : bestand) {
        cout << w << '\n';
        cerr << w << '\n';
    }


    // Dekommentieren fuer Zusatz erstausgaben
    cout << "\nZusatz erstausgaben\n";
    vector<Werk> result{Werk::erstausgaben(bestand)};
    for (const Werk& w : result)
        cout << w << '\n';


    // Dekommentieren fuer Zusatz aussortieren
    cout << "\nZusatz ausortieren\n";
    bestand.at(0).retournieren(2,Zustand::Unbrauchbar);
    for (int i{0}; i<4; ++i) bestand.at(1).entleihen();
    bestand.at(1).retournieren(1,Zustand::Unbrauchbar);
    bestand.at(1).retournieren(2,Zustand::Unbrauchbar);
    bestand.at(4).erwerben(4,Zustand::Gut);
    bestand.at(4).entleihen();
    bestand.at(4).retournieren(0,Zustand::Unbrauchbar);
    bestand.at(5).entleihen();
    bestand.at(5).retournieren(0,Zustand::Unbrauchbar);
    for (const Werk& w : bestand)
        cout << w << '\n';
    Werk::aussortieren(bestand);
    for (const Werk& w : bestand)
        cout << w << '\n';

  return 0;
}
