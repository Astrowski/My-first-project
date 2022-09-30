#ifndef DUOMENYS_H
#define DUOMENYS_H

#include <string>
#include <vector>

struct duomenys {
    std::string vardas;
    std::string pavarde;
    std::vector<int> paz = { 0 }; // pazymiu vektorius
    int egzas; // egzamino pazymys
    double rez = 0; // galutinis pazymys
};

#endif