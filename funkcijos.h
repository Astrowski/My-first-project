#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
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
char pasirink2(char&);
int tikrinkSk();
void paz(int&);
void studentai(std::vector <Studentas>&);
template <class T>
void ivesk(T&, std::string, char, bool);
void isvesk(std::vector <Studentas>, char);
template <class T>
void isvedimas(T, T, char, std::string);
bool FileExist();
bool rusiavimas(Studentas, Studentas);
void generavimas(int, std::string);
double skaiciuok(std::vector <int>, int, int, char);
template <class T>
void rusiuok(T, T&, int);
template <class T>
void mainFunc(T, T, T, bool, char);
void tipas();
#endif