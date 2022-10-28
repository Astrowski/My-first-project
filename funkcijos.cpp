#include "funkcijos.h"



bool tikrink() 							// Y/N tikrinimas
{	
	while (true) {
		char ats;
		std::cin >> ats;
		if (ats == 'y' || ats == 'Y')
		{
			return true;
		}
		else if (ats == 'n' || ats == 'N')
		{
			return false;
		}
		else
		{
			std::cout << "Blogai ivedete, badykite dar kart." << std::endl;
		}
	}
}

char pasirink(char& rc) 				//rt-resultType naudojamas vidurkio isvedimui pasirinkti 1/2/3
{	
	while (true) 
	{
		std::cin >> rc;
		if (rc == '1' || rc == '2' || rc == '3')
		{
			return rc;
		}
		else 
		{
			std::cout << "Blogai ivedete, badykite dar kart. " << std::endl;
		}
	}
}

char pasirink2(char& rc)
{
	while (true)
	{
		std::cin >> rc;
		if (rc == '1' || rc == '2')
		{
			return rc;
		}
		else 
		{
			std::cout << "Blogai ivedete, badykite dar kart. " << std::endl;
		}
	}
}

int tikrinkSk() 							//Skaiciu inputo tikrinimas
{	int num = 0;
	while (true)
	{
		std::cin >> num;
		if (num == -1) return -1;
		else if (num <= 0 or std::cin.fail())
		{
			std::cin.clear(); std::cin.ignore(999, '\n');
			std::cout << "Blogai ivedete, badykite dar kart." << std::endl;
		}
		else return num;
	}
}

void paz(int& grade)			// pazymio tikrinimas
{
	while (true)
	{
		if (grade <= 10 and grade > 0)
		{
			break;
		}
		else
		{
			std::cout << "Blogai ivedete, badykite dar kart.";
			grade = tikrinkSk();
		}
	}
}

void studentai(std::vector <Studentas>& studentas) {			//Studento duomenu ivedimas (manualinis)
	bool pazym, sk;
	int z;
	Studentas stud;
	std::cout << "Iveskite studento varda: "; std::cin >> stud.vardas; std::cout << std::endl;
	std::cout << "Iveskite studento pavarde: "; std::cin >> stud.pavarde; std::cout << std::endl;
	std::cout << "Ar zinote atliktu namu darbu kieki? (Y/N): ";
	pazym = tikrink();
	if (pazym)
	{
		std::cout << std::endl << "Iveskite atliktu namu darbu kieki: ";
		stud.n = tikrinkSk();
		stud.pazymiai.resize(stud.n);

		std::cout << std::endl << "Ar norite, kad studento pazymiai butu sugeneruojami automatiskai? (Y/N): ";
		pazym = tikrink();
		if (pazym) 							// random skaiciu generavimas
		{
			z = stud.n;
			stud.pazymiai.resize(z);
			std::cout << std::endl << "Sugeneruoti studento pazymiai: ";
			for (int i = 0; i < stud.n; i++)
			{
				stud.pazymiai[i] = rand() % 10 + 1;
				std::cout << stud.pazymiai[i] << " ";
			}
			stud.egzas = rand() % 10 + 1;
			std::cout << std::endl << "Egzamino rezultatas: " << stud.egzas;
		}
		else
		{
			std::cout << std::endl << "Iveskite atliktu namu darbu pazymius: " << std::endl;
			for (int i = 0; i < stud.n; i++)
			{
				stud.pazymiai[i] = tikrinkSk();
				paz(stud.pazymiai[i]);
			}
			std::cout << std::endl << "Iveskite egzamino pazymi: ";
			stud.egzas = tikrinkSk();
			paz(stud.egzas);
		}
	}

	else 
	{
		stud.n = rand() % 25 + 1;				// homework number range: 1-25
		std::cout << std::endl << "Sugeneruotas atliktu namu darbu kiekis: " << stud.n << std::endl;
		std::cout << std::endl << "Ar norite, kad studento pazymiai butu sugeneruojami automatiskai? (Y/N): ";
		sk = tikrink();
		if (sk) 								// random skaiciu generavimas
		{
			z = stud.n;
			stud.pazymiai.resize(z);
			std::cout << std::endl << "Sugeneruoti studento pazymiai: ";
			for (int i = 0; i < stud.n; i++)
			{
				stud.pazymiai[i] = rand() % 10 + 1;
				std::cout << stud.pazymiai[i] << " ";
			}
			stud.egzas = rand() % 10 + 1;
			std::cout << std::endl << "Egzamino rezultatas: " << stud.egzas;
		}
		else
		{
			std::cout << std::endl << "Iveskite atliktu namu darbu pazymius: " << std::endl;
			stud.pazymiai.resize(stud.n);
			for (int i = 0; i < stud.n; i++)
			{
				stud.pazymiai[i] = tikrinkSk();
				paz(stud.pazymiai[i]);
			}

			std::cout << std::endl << "Iveskite egzamino pazymi: ";
			stud.egzas = tikrinkSk();
			paz(stud.egzas);
		}
	}
	studentas.push_back(stud);
	stud.pazymiai.clear();
}

template <class T>
void ivesk(T& studentas, std::string fileName, char rc, bool timeOut) 			// ivestis
{
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	std::ifstream file;
	try 
	{
		file.open(fileName);
		if (!file)
		{
			throw 1;
		}
		std::string line;
		getline(file, line);
		while (getline(file , line))
		{
			Studentas stud;
			std::istringstream iss(line);
			iss >> stud.vardas >> stud.pavarde;
			int g;
			while (iss >> g)
			{
				stud.pazymiai.push_back(g);
			}
			if (stud.pazymiai.size() == 0)
			{
				throw 2;
			}

			stud.pazymiai.pop_back();
			stud.egzas = g;
			stud.n = stud.pazymiai.size();
			stud.final = skaiciuok(stud.pazymiai, stud.egzas, stud.n, rc);
			studentas.push_back(stud);
		}
	}
	catch (int e)
	{
		switch (e)
		{
		case 1:
			std::cout << "Failas nerastas." << std::endl << std::endl << "Baigiamas programos veikimas." << std::endl;
			break;
		case 2:
			std::cout << "Failas nuskaitytas netinkamai." << std::endl;
			break;
		}
		exit(1);
	}
	file.close();
	if (timeOut == true)
	{
		std::cout << "Duomenu nuskaitymas is failo uztruko: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - t1).count() / 1000. << "s." << std::endl;
	}
}


void isvesk(std::vector <Studentas> studentas, char rc) {						// isvestis i konsole		
	std::cout << "\n\n\n\n\n";
	std::cout << std::left << std::setw(15) << "Vardas" << std::setw(15) << "Pavarde" << std::setw(18);
	if (rc == '2')
	{
		std::cout << "Galutinis (vid.)" << std::endl;
	}
	else if (rc == '1')
	{
		std::cout << "Galutinis (med.)" << std::endl;
	}
	else
	{
		std::cout << "Galutinis (vid.)" << std::setw(18) << "Galutinis (med.)" << std::endl;
	}
	if (rc == '3')
	{
		std::cout << "----------------------------------------------------------------" << std::endl;
	}
	else
	{
		std::cout << "-----------------------------------------------" << std::endl;
	}
	for (int i = 0; i < studentas.size(); i++)
	{
		double galutinisVid = 0;
		double galutinisMed = 0;
		double sum = 0;		//calc vid
		int size = studentas[i].pazymiai.size();
		for (int j = 0; j < size; j++)
		{
			sum = sum + studentas[i].pazymiai[j];
		}
		double average = sum / size;
		galutinisVid = studentas[i].egzas * 0.6 + average * 0.4;			
		sort(studentas[i].pazymiai.begin(), studentas[i].pazymiai.end()); //calc med
		if (size % 2 == 0)
		{
			galutinisMed = (studentas[i].pazymiai[size / 2] / 2);
		}
		else
		{
			galutinisMed = ((studentas[i].pazymiai[size / 2] + studentas[i].pazymiai[size / 2 - 1]) / 2);
		}	
		std::cout << std::left << std::setw(15) << studentas[i].vardas << std::setw(15) << studentas[i].pavarde << std::setw(18);
		if (rc == '1')
		{
			std::cout << std::fixed << std::setprecision(2) << galutinisMed << std::endl;
		}
		else if (rc == '2')
		{
			std::cout << std::fixed << std::setprecision(2) << galutinisVid << std::endl;
		}
		else
		{
			std::cout << std::fixed << std::setprecision(2) << galutinisVid << std::setw(18) << std::setprecision(2) << galutinisMed << std::endl;
		}
	}
}

template <class T>
void isvedimas(T protingi, T vargsai, char rc, std::string failas) {
	std::string pfile = "Protingi_" + failas;
	std::string vfile = "Vargsai_" + failas;
	std::ofstream pout(pfile);
	std::ofstream vout(vfile);
	pout << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(18);
	if (rc == '2')
	{
		pout << "Galutinis (vid.)" << std::endl;
	}
	else if (rc == '1')
	{
		pout << "Galutinis (med.)" << std::endl;
	}
	else
	{
		pout << "Galutinis (vid.)" << std::setw(18) << "Galutinis (med.)" << std::endl;
	}
	if (rc == '3')
	{
		pout << "-----------------------------------------------------------------------------------------------------" << std::endl;
	}
	else
	{
		pout << "-------------------------------------------------------------------" << std::endl;
	}
	vout << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(18);
	if (rc == '2')
	{
		vout << "Galutinis (vid.)" << std::endl;
	}
	else if (rc == '1')
	{
		vout << "Galutinis (med.)" << std::endl;
	}
	else
	{
		vout << "Galutinis (vid.)" << std::setw(18) << "Galutinis (med.)" << std::endl;
	}
	if (rc == '3')
	{
		vout << "-----------------------------------------------------------------------------------------------------" << std::endl;
	}
	else
	{
		vout << "-------------------------------------------------------------------" << std::endl;
	}
	for (auto& a : vargsai)
	{
		vout << std::left << std::setw(20) << a.vardas << std::setw(20) << a.pavarde << std::setw(18);
		vout << std::fixed << std::setprecision(2) << a.final << std::endl;
	}
	vout.close();
	for (auto& a : protingi)
	{
		vout << std::left << std::setw(20) << a.vardas << std::setw(20) << a.pavarde << std::setw(18);
		vout << std::fixed << std::setprecision(2) << a.final << std::endl;
	}
	pout.close();
}

bool FileExist() 		// Failo patikrinimas
{
	std::ifstream file;
	file.open("Studentai.txt");
	if (!file)
	{
		return 0;
	}
	else
	{
		std::cout << "File 'Studentai.txt' detected." << std::endl;
		return 1;
	}
}

bool rusiavimas(Studentas a, Studentas b) {				// rusiavimas
	if (a.vardas < b.vardas)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void generavimas(int m, std::string fileName) {					// failo kurimas
	int a = 10;
	std::ofstream out(fileName);
	out << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde";
	for (int i = 0; i < a; i++)
	{
		out << std::setw(8) << "ND" + std::to_string(i + 1);
	}
	out << std::setw(8) << "Egz." << std::endl;

	for (int i = 0; i < m; i++)
	{
		out << std::left << std::setw(20) << "Vardenis" + std::to_string(i + 1) << std::setw(20) << "Pavardenis" + std::to_string(i + 1);
		for (int j = 0; j <= a; j++)
		{
			out << std::setw(8) << rand() % 10 + 1;
		}
		out << std::endl;
	}
	out.close();
}

double skaiciuok(std::vector <int> pazymiai, int egzas, int n, char rc) {		//galutiniai skaiciavimai
	double final;
	if (rc == '2')
	{					//calc vid
		int sum;
		sum = accumulate(pazymiai.begin(), pazymiai.end(), 0);
		final = (sum * 1.0 / n) * 0.4 + egzas * 0.6;
	}
	else if (rc == '1')
	{
						//calc med
		sort(pazymiai.begin(), pazymiai.end());
		if (n % 2 == 0)
		{
			final = ((pazymiai[n / 2] + pazymiai[n / 2 - 1]) / 2.0);
		}
		else
		{
			final = (pazymiai[n / 2]);
		}
	}
	return final;
}

template <class T>
void rusiuok(T studentas, T& protingi, T& vargsai, int n)
{
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	for (int i = 0; i < n; i++) 
	{
		if (studentas.front().final < 5) 
		{
			vargsai.push_back(studentas.front());
			studentas.erase(studentas.begin());
		}
		else
		{
			protingi.push_back(studentas.front());
			studentas.erase(studentas.begin());
		}
	}
	studentas.clear();
	std::cout << "Studentu rusiavimas i dvi grupes uztruko: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - t1).count() / 1000. << "s." << std::endl;
}
template <class T>
void mainFunc(T studentas, T protingi, T vargsai, bool generuok, char rc, char conType) {																								// GREICIO ANALIZE 
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	std::cout << std::endl << "Failas Studentai_1000.txt" << std::endl;
	if (generuok == 1)
		generavimas(1000, "Studentai_1000.txt");
	ivesk(studentas, "Studentai_1000.txt", rc, true);
	rusiuok(studentas, protingi, vargsai, 1000);
	isvedimas(protingi, vargsai, rc, "Studentai_1000.txt");
	std::cout << "Bendras failo Studentai_1000.txt testavimo laikas: " <<
		std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - t1).count() / 1000. << "s." << std::endl;
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	std::cout << std::endl << "Failas Studentai_10000.txt" << std::endl;
	if (generuok == 1)
		generavimas(10000, "Studentai_10000.txt");
	ivesk(studentas, "Studentai_10000.txt", rc, true);
	rusiuok(studentas, protingi, vargsai, 10000);
	isvedimas(protingi, vargsai, rc, "Studentai_10000.txt");
	std::cout << "Bendras failo Studentai_10000.txt testavimo laikas: " <<
		std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - t2).count() / 1000. << "s." << std::endl;
	high_resolution_clock::time_point t3 = high_resolution_clock::now();
	std::cout << std::endl << "Failas Studentai_100000.txt" << std::endl;
	if (generuok == 1)
		generavimas(100000, "Studentai_100000.txt");
	ivesk(studentas, "Studentai_100000.txt", rc, true);
	rusiuok(studentas, protingi, vargsai, 100000);
	isvedimas(protingi, vargsai, rc, "Studentai_100000.txt");
	std::cout << "Bendras failo Studentai_100000.txt testavimo laikas: " <<
		std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - t3).count() / 1000. << "s." << std::endl;
	high_resolution_clock::time_point t4 = high_resolution_clock::now();
	std::cout << std::endl << "Failas Studentai_1000000.txt" << std::endl;
	if (generuok == 1)
		generavimas(1000000, "Studentai_1000000.txt");
	ivesk(studentas, "Studentai_1000000.txt", rc, true);
	rusiuok(studentas, protingi, vargsai, 1000000);
	isvedimas(protingi, vargsai, rc, "Studentai_1000000.txt");
	std::cout << "Bendras failo Studentai_1000000.txt testavimo laikas: " <<
		std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - t4).count() / 1000. << "s." << std::endl;
	high_resolution_clock::time_point t5 = high_resolution_clock::now();
	if (generuok == 1)
		generavimas(10000000, "Studentai_10000000.txt");
	ivesk(studentas, "Studentai_10000000.txt", rc, true);
	rusiuok(studentas, protingi, vargsai, 10000000);
	isvedimas(protingi, vargsai, rc, "Studentai_10000000.txt");
	std::cout << "Bendras failo Studentai_10000000.txt testavimo laikas: " <<
		std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - t5).count() / 1000. << "s." << std::endl;
}

void tipas()
{
	bool generuok;
	char conType = '0', rc = '0';
	std::cout << "Pasirinkite konteinerio tipa" << std::endl
		<< "(1) Vector / (2) Deque / (3) List : ";
	pasirink(conType);
	std::cout << std::endl << "Ar norite sugeneruoti studentu failus? (Y/N): ";
	if (tikrink())
	{
		generuok = 1;
	}
	else
	{
		generuok = 0;
	}
	std::cout << std::endl << "Ar norite apskaiciuoti mediana(1), vidurki(2)? ";
	pasirink2(rc);
	if (conType == '1')
	{
		std::vector <Studentas> studentas;
		std::vector <Studentas> protingi;
		std::vector <Studentas> vargsai;
		std::cout << std::endl << "Pradedamas testavimas naudojant vector: " << std::endl;
		mainFunc(studentas, protingi, vargsai, generuok, rc, conType);
	}
	else if (conType == '2')
	{
		std::deque <Studentas> studentas;
		std::deque <Studentas> protingi;
		std::deque <Studentas> vargsai;
		std::cout << std::endl << "Pradedamas testavimas naudojant deque: " << std::endl;
		mainFunc(studentas, protingi, vargsai, generuok, rc, conType);
	}
	else if (conType == '3') {
		std::list <Studentas> studentas;
		std::list <Studentas> protingi;
		std::list <Studentas> vargsai;
		std::cout << std::endl << "Pradedamas testavimas naudojant list: " << std::endl;
		mainFunc(studentas, protingi, vargsai, generuok, rc, conType);
	}
}