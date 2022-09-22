#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <cstdlib>

using std::cout;
using std::string;
using std::cin;
using std::vector;

struct studentas
{
    string vardas; // vardas
    string pavarde; // pavarde
    vector<int> paz; // namu darbu vektorius
    int egzas; // egzaminas
    int n = 0; // nd skaicius
};

void duomenu_Ivedimas(studentas A[], int z);
void duomenu_Isvedimas(studentas A[], int z);

int main()
{
    studentas A[10];
    int z; // studentu skaicius
    cout << "Ivesk studentu skaiciu: "; cin >> z;
    while (cin.fail())
    {
        cout << "\nIvesk skaiciu!: ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> z;
    }
    duomenu_Ivedimas(A, z);
    duomenu_Isvedimas(A, z);

    return 0;
}
void duomenu_Ivedimas(studentas A[], int z)
{
    int pazymys;
    int* paz2;
    int temp = 0;
    for (int i = 0; i < z; i++)
    {
        cout << "\nIvesk " << i + 1 << " studento varda: "; cin >> A[i].vardas;
        cout << "\nIvesk " << i + 1 << " studento pavarde: "; cin >> A[i].pavarde;
        cout << "\nIvesk egzamino pazymi: "; cin >> A[i].egzas;
        while (cin.fail() || A[i].egzas < 1 || A[i].egzas > 10)
        {
            cout << "\nIvesk skaiciu is desimtbales sistemos!: ";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> A[i].egzas;
        }
        char t;
        cout << "\nParasyk N, jei nori pats suvesti nd pazymius, bet ka kita - jei ne: ";
        cin >> t;
        if (t == 'N' || t == 'n')
        {
            while (true)
            {
                cout << "\nIvesk nd pazymi, jeigu pazymiu nera, ivesk -1: ";
                cin >> pazymys;

                if (pazymys == -1)
                {
                    break;
                }
                while (cin.fail() || pazymys < 1 || pazymys > 10)
                {
                    cout << "\nIvesk skaiciu is desimtbales sistemos!: ";
                    cin.clear();
                    cin.ignore(256, '\n');
                    cin >> pazymys;
                }
                A[i].n++;
                A[i].paz.push_back(pazymys);
            }
            if (A[i].n == 0)
            {
                cout << "Studentas pazymiu neturi" << std::endl;
            }
        }
        else
        {
            for (int j = 0; j < (rand() % 10 + 1); j++) 
            {
                A[i].n++;
                A[i].paz.push_back(rand() % 10 + 1);
            }
        }
    }


}

int sum(vector<int> masyvas, int n)
{
    int pazymys = 0;
    for (int i = 0; i < n; i++)
    {
        pazymys += masyvas[i];
    }
    return pazymys;
}
double vidurkis(double pazymys, int m)
{
        double vid;
        vid = pazymys / m;
        if (m == 0)
        {
            vid = 0;
        }
        return vid;
}
double mediana(studentas A, int m)
{
        double mediana;
        if (A.n == 0)
        {
            mediana = 0;
        }
        else
        {
            if (A.n % 2 == 0)
            {
                mediana = (A.paz[m / 2] + A.paz[m / 2 - 1]) / 2.0;
            }
            else
            {
                mediana = A.paz[A.n / 2];
            }
        }
        return mediana;
}

void duomenu_Isvedimas(studentas A[], int z)
{

    cout << "\n" << std::left << std::setw(12) << "Vardas" << std::left << std::setw(12) << "Pavarde" << std::setw(13) << "Galutinis (Vid.)" << " / " << std::setw(16) << "Galutinis (Med.)" << std::endl;

    for (int j = 0; j < 60; j++)
    {
        cout << "-";
    }
    cout << std::endl;

    for (int i = 0; i < z; i++) {
        cout << "\n" << std::left << std::setw(12) << A[i].vardas << std::left << std::setw(12) << A[i].pavarde;
        cout << std::setw(19) << std::fixed << std::setprecision(2) << vidurkis(sum(A[i].paz, A[i].n), A[i].n);
        cout << std::left << std::setw(16) << std::fixed << std::setprecision(2) << mediana(A[i], A[i].n) << std::endl;
    }
}