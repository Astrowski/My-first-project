#ifndef functions_h
#define functions_h
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <cmath>
#include <chrono>
#include <numeric>
#include <sstream>
#include <istream>
#include <string>

using namespace std::chrono;

struct Studentas {
	std::string vardas;
	std::string pavarde;
	int n;
	std::vector <int> pazymiai;
	int egzas;
	double final;
};

bool tikrink();

char pasirink(char&);

int tikrinkSk();

void gradeCheck(int&);

void studentai(std::vector <Studentas>&);

void ivesk(std::vector <Studentas>&, std::string);

void isvesk(std::vector <Studentas>, char);

void isvestis(std::vector <Studentas>, std::vector<Studentas>, char, std::string);

bool FileExist();

bool rusiavimas(Studentas, Studentas);

void generateStud(int, std::string);

void calcFinal(std::vector <Studentas>&, char);

void group(std::vector <Studentas>, std::vector <Studentas>&, std::vector <Studentas>&);




#endif