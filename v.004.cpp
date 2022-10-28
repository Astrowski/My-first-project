#include "funkcijos.h"

int main() {
	srand(time(NULL));
	char rc = '0';		// rt naudojamas vidurkio isvedimui pasirinkti (resultType)
	bool vid, timeOut;
	std::cout << "Ar norite atlikti programos veikimo (greicio) analize? (Y/N): ";
	if (tikrink())
	{
		tipas();
	}
	else 						// iprasta programos eiga
	{
		std::vector <Studentas> studentas;
		std::vector <Studentas> protingi;
		std::vector <Studentas> vargsai;
		if (FileExist())
		{
			std::cout << "Ar norite skaityti duomenis is failo ar duomenis ivesti rankiniu budu? (y - file / n - manually): ";
			if (tikrink()) 
			{
				ivesk(studentas, "kursiokai.txt", rc, false);
			}
			else 
			{
				do 
				{
					studentai(studentas);
					std::cout << std::endl << "Ar norite prideti dar viena studenta? (Y/N) ";
				} while (tikrink());
			}
		}
		else 			// only manual input
		{
			std::cout << "Failas nerastas. Duomenys privalo buti ivesti rankiniu budu." << std::endl << std::endl;
			do
			{
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