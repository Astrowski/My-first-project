#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using std::string;
using std::cout;
using std::cin;
using std::swap;

struct studentas
{
    string vardas; // vardas
    string pavarde; // pavarde
    int* paz; // namu darbu masyvas kai nezinom n
    int egzas; // egzaminas
    int n = 0; // nd skaicius
};

void duomenu_Ivedimas(studentas A[], int z);
void duomenu_Isvedimas(studentas A[], int z);

int main()
{
    studentas A[10];
    int z; // mokiniu skaicius
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
    for (int i = 0; i < z; i++) 
    { 
               
            delete[] A[i].paz;
        
    }
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
            paz2 = new int(A[i].n);
            if (A[i].n != 1)
            {
                for (int j = 0; j < A[i].n - 1; j++)
                {
                    paz2[j + 1] = A[i].paz[j];
                }
                delete[] A[i].paz;
            }

            paz2[0] = pazymys;
            A[i].paz = paz2;
        }
        if (A[i].n == 0)
        {
            cout << "Mokinys pazymiu neturi" << std::endl;
        }


    }
}
void rusiavimas(studentas A) // rusiavimo algoritmas
{ 
    for (int i = 0; i < A.n - 1; i++)
    {
        for (int j = i; j < A.n; j++)
        {
            if (A.paz[i] > A.paz[j])
            {
                std::swap(A.paz[i], A.paz[j]);
            }
        }
    }
}
int sum(int masyvas[], int n) // nd pazymiu suma
{
    int pazymys = 0;
    for (int i = 0; i < n; i++)
    {
        pazymys += masyvas[i];
    }
    return pazymys;
}
double vidurkis(double pazymys, int m) // vidurkio skaiciavimas
{
        double vid;
        vidurkis = pazymys / m;
        if (m == 0)
        {
            vidurkis = 0;
        }
        return vidurkis;
}
double mediana(studentas A, int m) //medianos skaiciavimas
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
        rusiavimas(A[i]);
        cout << "\n" << std::left << std::setw(12) << A[i].vardas << std::left << std::setw(12) << A[i].pavarde;
        cout << std::setw(19) << std::fixed << std::setprecision(2) << vidurkis(sum(A[i].paz, A[i].n), A[i].n);
        cout << std::left << std::setw(16) << std::fixed << std::setprecision(2) << mediana(A[i], A[i].n) << std::endl;
    }
}
