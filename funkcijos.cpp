#include "funkcijos.h"


using namespace std::chrono;

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

char pasirink(char& rc)
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


int tikrinkSk() 							//Skaiciu inputo tikrinimas
{
	int num = 0;
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

void gradeCheck(int& grade) {
	while (true) {
		if (grade <= 10 and grade > 0) break;
		else std::cout << "Blogai ivedete, badykite dar kart.";
		grade = tikrinkSk();
	}
}

void studentai(std::vector <Studentas>& studentas) {			//Studento duomenu ivedimas (manualinis)
	bool pazym, generateGrades;
	int gradeNum;
	Studentas stud;
	std::cout << "Iveskite varda: "; std::cin >> stud.vardas; std::cout << std::endl;
	std::cout << "Iveskite pavarde: "; std::cin >> stud.pavarde; std::cout << std::endl;
	std::cout << "Ar zinot namu darbu kieki? (Y/N): ";
	pazym = tikrink();
	if (pazym) {
		std::cout << std::endl << "Iveskite namu darbu kieki: ";
		stud.n = tikrinkSk();
		stud.pazymiai.resize(stud.n);
		std::cout << std::endl << "Ar norite, kad pazymiai butu generuojami automatiskai? (Y/N): ";
		generateGrades = tikrink();
		if (generateGrades) {							// random skaiciu generavimas
			gradeNum = stud.n;
			stud.pazymiai.resize(gradeNum);
			std::cout << std::endl << "Sugeneruoti studento pazymiai: ";
			for (int i = 0; i < stud.n; i++) {
				stud.pazymiai[i] = rand() % 10 + 1;
				std::cout << stud.pazymiai[i] << " ";
			}
			stud.egzas = rand() % 10 + 1;
			std::cout << std::endl << "Egzamino rezultatas: " << stud.egzas;
		}
		else {
			std::cout << std::endl << "Iveskite namu darbu pazymius: " << std::endl;
			for (int i = 0; i < stud.n; i++) {
				stud.pazymiai[i] = tikrinkSk();
				gradeCheck(stud.pazymiai[i]);
			}
			std::cout << std::endl << "Iveskite egzamino pazymi: ";
			stud.egzas = tikrinkSk();
			gradeCheck(stud.egzas);
		}
	}
	else {
		stud.n = rand() % 25 + 1;				// homework number range: 1-25
		std::cout << std::endl << "Sugeneruotas atliktu namu darbu kiekis: " << stud.n << std::endl;
		std::cout << std::endl << "Ar norite, kad studento pazymiai butu sugeneruojami automatiskai? (Y/N): ";
		generateGrades = tikrink();
		if (generateGrades) {								// random skaiciu generavimas
			gradeNum = stud.n;
			stud.pazymiai.resize(gradeNum);
			std::cout << std::endl << "Sugeneruoti pazymiai: ";
			for (int i = 0; i < stud.n; i++) {
				stud.pazymiai[i] = rand() % 10 + 1;
				std::cout << stud.pazymiai[i] << " ";
			}
			stud.egzas = rand() % 10 + 1;
			std::cout << std::endl << "Egzamino rezultatas: " << stud.egzas;
		}
		else {
			std::cout << std::endl << "Iveskite namu darbu pazymius: " << std::endl;
			stud.pazymiai.resize(stud.n);
			for (int i = 0; i < stud.n; i++) {
				stud.pazymiai[i] = tikrinkSk();
				gradeCheck(stud.pazymiai[i]);
			}
			std::cout << std::endl << "Iveskite egzamino pazymi: ";
			stud.egzas = tikrinkSk();
			gradeCheck(stud.egzas);
		}
	}
	studentas.push_back(stud);
	stud.pazymiai.clear();
}

void ivesk(std::vector <Studentas>&studentas, std::string fileName) {			// ivestis is failo
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	Studentas stud;
	std::ifstream file;
	try {
		file.open(fileName);
		if (!file) throw 1;
		std::string line;
		std::getline(file, line);
		while (getline(file, line))
		{
			Studentas stud;
			std::istringstream iss(line);
			iss >> stud.vardas >> stud.pavarde;
			int g;
			while (iss >> g)
			{
				stud.pazymiai.push_back(g);
			}
			if (stud.pazymiai.size() == 0) throw 2;
			stud.pazymiai.pop_back();
			stud.egzas = g;
			studentas.push_back(stud);
		}
	}
	catch (int e) {
		switch (e) {
		case 1:
			std::cout << "Failas neatidarytas." << std::endl;
			break;
		case 2:
			std::cout << "Failas nuskaitytas netinkamai." << std::endl;
			break;
		}
		exit(1);
	}
	file.close();
	std::cout << "Duomenu nuskaitymas is failo uztruko: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - t1).count() / 1000. << " s." << std::endl;
}

void isvesk(std::vector <Studentas> studentas, char rc) {						// isvestis i konsole
	std::cout << "\n\n\n\n\n";
	std::cout << std::left << std::setw(15) << "Vardas" << std::setw(15) << "Pavarde" << std::setw(18);
	if (rc == '2') std::cout << "Galutinis (vid.)" << std::endl;
	else if (rc == '1') std::cout << "Galutinis (med.)" << std::endl;
	else std::cout << "Galutinis (vid.)" << std::setw(18) << "Galutinis (med.)" << std::endl;
	if (rc == '3') std::cout << "----------------------------------------------------------------" << std::endl;
	else std::cout << "-----------------------------------------------" << std::endl;
	for (int i = 0; i < studentas.size(); i++) {
		double galutinisVid = 0;
		double galutinisMed = 0;
		double sum = 0;		//calc vid
		int size = studentas[i].pazymiai.size();
		for (int j = 0; j < size; j++) {
			sum = sum + studentas[i].pazymiai[j];
		}
		double average = sum / size;
		galutinisVid = studentas[i].egzas * 0.6 + average * 0.4;
		int vidI = (size / 2) - 1;			//calc med
		sort(studentas[i].pazymiai.begin(), studentas[i].pazymiai.end());
		if (size != 0) galutinisMed = studentas[i].pazymiai[vidI] * 0.4 + studentas[i].egzas * 0.6;
		else galutinisMed = ((studentas[i].pazymiai[vidI] + studentas[i].pazymiai[vidI + 1]) / 2) * 0.4 + studentas[i].egzas * 0.6;
		//galutinis outputui \/
		std::cout << std::left << std::setw(15) << studentas[i].vardas << std::setw(15) << studentas[i].pavarde << std::setw(18);
		if (rc == '1')	std::cout << std::fixed << std::setprecision(2) << galutinisMed << std::endl;
		else if (rc == '2')	std::cout << std::fixed << std::setprecision(2) << galutinisVid << std::endl;
		else std::cout << std::fixed << std::setprecision(2) << galutinisVid << std::setw(18) << std::setprecision(2) << galutinisMed << std::endl;
	}
}

void isvestis(std::vector <Studentas> protingi, std::vector <Studentas> vargsai, char rc, std::string outFileName) {								//Isvedimas i failus
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	std::string wfile = "Protingi_" + outFileName;
	std::string lfile = "Vargsai_" + outFileName;
	std::ofstream wout(wfile);
	std::ofstream lout(lfile);
	wout << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(18);
	if (rc == '2') wout << "Galutinis (vid.)" << std::endl;
	else if (rc == '1') wout << "Galutinis (med.)" << std::endl;
	else wout << "Galutinis (vid.)" << std::setw(18) << "Galutinis (med.)" << std::endl;
	if (rc == '3') wout << "-----------------------------------------------------------------------------------------------------" << std::endl;
	else wout << "-------------------------------------------------------------------" << std::endl;
	lout << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(18);
	if (rc == '2') lout << "Galutinis (vid.)" << std::endl;
	else if (rc == '1') lout << "Galutinis (med.)" << std::endl;
	else lout << "Galutinis (vid.)" << std::setw(18) << "Galutinis (med.)" << std::endl;
	if (rc == '3') lout << "-----------------------------------------------------------------------------------------------------" << std::endl;
	else lout << "-------------------------------------------------------------------" << std::endl;
	for (int i = 0; i < vargsai.size(); i++) {
		lout << std::left << std::setw(20) << vargsai[i].vardas << std::setw(20) << vargsai[i].pavarde << std::setw(18);
		lout << std::fixed << std::setprecision(2) << vargsai[i].final << std::endl;
	}
	lout.close();
	for (int i = 0; i < protingi.size(); i++) {
		wout << std::left << std::setw(20) << protingi[i].vardas << std::setw(20) << protingi[i].pavarde << std::setw(18);
		wout << std::fixed << std::setprecision(2) << protingi[i].final << std::endl;
	}
	wout.close();
	std::cout << "Surusiuotu studentu isvedimas i du naujus failus uztruko: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - t1).count() / 1000. << " s." << std::endl;

}

bool FileExist() {		// Failo patikrinimas
	std::ifstream file;
	file.open("kursiokai.txt");
	if (!file) return 0;
	else {
		std::cout << "File detected." << std::endl << std::endl;
		return 1;
	}
}

bool rusiavimas(Studentas a, Studentas b) {			// rusiavimas
	if (a.vardas < b.vardas) return true;
	else return false;
}

void generateStud(int m, std::string fileName) {						// failo kurimas
	int a = 10;
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	std::ofstream out(fileName);
	out << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde";
	for (int i = 0; i < a; i++) out << std::setw(8) << "ND" + std::to_string(i + 1);
	out << std::setw(8) << "Egz." << std::endl;
	for (int i = 0; i < m; i++) 
	{
		out << std::left << std::setw(20) << "Vardenis" + std::to_string(i + 1) << std::setw(20) << "Pavardenis" + std::to_string(i + 1);
		for (int j = 0; j <= a; j++) {
			out << std::setw(8) << rand() % 10 + 1;
		}
		out << std::endl;
	}
	out.close();
	std::cout << "Failo kurimas uztruko: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - t1).count() / 1000. << " s." << std::endl;
}

void calcFinal(std::vector <Studentas>& studentas, char rc) {			//galutiniai skaiciavimai
	for (int i = 0; i < studentas.size(); i++) {
		int size = studentas[i].pazymiai.size();
		if (rc == '2') {
			double sum = 0;		//calc vid
			for (int j = 0; j < size; j++) {
				sum = sum + studentas[i].pazymiai[j];
			}
			double average = sum / size;
			studentas[i].final = (studentas[i].egzas * 0.6 + average * 0.4);
		}
		else if (rc == '1') {
			int vidI = (size / 2) - 1;			//calc med
			sort(studentas[i].pazymiai.begin(), studentas[i].pazymiai.end());
			if (size != 0) studentas[i].final = round(studentas[i].pazymiai[vidI] * 0.4 + studentas[i].egzas * 0.6);
			else studentas[i].final = round(((studentas[i].pazymiai[vidI] + studentas[i].pazymiai[vidI + 1]) / 2) * 0.4 + studentas[i].egzas * 0.6);
		}
	}
}

void group(std::vector <Studentas> studentas, std::vector <Studentas>& winner, std::vector <Studentas>& loser) {
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	for (int i = 0; i < studentas.size(); i++) {
		if (studentas[i].final < 5) loser.push_back(studentas[i]);
		else winner.push_back(studentas[i]);
	}
	studentas.clear();
	std::cout << "Studentu rusiavimas i dvi grupes uztruko: "
		<< std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - t1).count() / 1000. << " s." << std::endl;
}