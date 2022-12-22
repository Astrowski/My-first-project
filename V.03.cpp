#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include "funkcijos.h"


int main() {
	srand(time(NULL));
	char rc = '0';		// rt naudojamas vidurkio isvedimui pasirinkti (resultType)
	bool vid;

	std::vector <Studentas> studentas;
	std::vector <Studentas> protingi;
	std::vector <Studentas> vargsai;

	std::cout << "Ar norite atlikti programos veikimo (greicio) analize? (Y/N): ";
	if (tikrink()) {
		std::cout << std::endl << "Ar norite apskaiciuoti mediana(1), vidurki(2)? ";
		pasirink(rc);																		// 		GREICIO ANALIZE \/
		std::cout << std::endl << "Failas Studentai_1000.txt" << std::endl;
		generateStud(1000, "Studentai_1000.txt");
		ivesk(studentas, "Studentai_1000.txt");
		calcFinal(studentas, rc);
		group(studentas, protingi, vargsai);
		sort(studentas.begin(), studentas.end(), rusiavimas);
		isvestis(protingi, vargsai, rc, "Studentai_1000.txt");

		std::cout << std::endl << "Failas Studentai_10000.txt" << std::endl;
		generateStud(10000, "Studentai_10000.txt");
		ivesk(studentas, "Studentai_10000.txt");
		calcFinal(studentas, rc);
		group(studentas, protingi, vargsai);
		sort(studentas.begin(), studentas.end(), rusiavimas);
		isvestis(protingi, vargsai, rc, "Studentai_100000.txt");

		std::cout << std::endl << "Failas Studentai_100000.txt" << std::endl;
		generateStud(100000, "Studentai_100000.txt");
		ivesk(studentas, "Studentai_100000.txt");
		calcFinal(studentas, rc);
		group(studentas, protingi, vargsai);
		sort(studentas.begin(), studentas.end(), rusiavimas);
		isvestis(protingi, vargsai, rc, "Studentai_100000.txt");

		std::cout << std::endl << "Failas Studentai_1000000.txt" << std::endl;
		generateStud(1000000, "Studentai_1000000.txt");
		ivesk(studentas, "Studentai_1000000.txt");
		calcFinal(studentas, rc);
		group(studentas, protingi, vargsai);
		sort(studentas.begin(), studentas.end(), rusiavimas);
		isvestis(protingi, vargsai, rc, "Studentai_1000000.txt");

	}
	else {						// iprasta programos eiga \/
		if (FileExist()) {
			std::cout << "Ar norite skaityti duomenis is failo ar duomenis ivesti rankiniu budu? (y - file / n - manually): ";
			if (tikrink()) {
				ivesk(studentas, "Studentai.txt");
			}
			else {
				do {
					studentai(studentas);
					std::cout << std::endl << "Ar norite prideti dar viena studenta? (Y/N) ";
				} while (tikrink());
			}
		}
		else {			// only manual input
			std::cout << "Failas nerastas. Duomenys privalo buti ivesti rankiniu budu." << std::endl << std::endl;
			do {
				studentai(studentas);
				std::cout << std::endl << "Ar norite prideti dar viena studenta? (Y/N) ";
			} while (tikrink());
		}
		sort(studentas.begin(), studentas.end(), rusiavimas);
		std::cout << std::endl << "Ar norite apskaiciuoti mediana(1), vidurki(2), ar abu(3)? ";
		pasirink(rc);
		isvesk(studentas, rc);
	}
	system("PAUSE");
}