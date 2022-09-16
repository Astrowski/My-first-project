#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

struct studentas
{
    string vardas;
    string pavarde;
    double pazymys;
    int paz[10];
    int egzas;
    double mediana;
};

int main()
{
    studentas A[10];
    int n , m, sum = 0, temp, z;
    char t, g;
    cout << "Ivesk studentu skaiciu: "; cin >> z;
    while (cin.fail())
    {
        cout << "\nIvesk skaiciu!: ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> z;
    }
    for (int i = 0; i < z; i++)
    {
        n = m = 0;
        cout << "\nIvesk " << i + 1 << " studento varda: "; cin >> A[i].vardas;

        cout << "\nIvesk " << i + 1 << " studento pavarde: "; cin >> A[i].pavarde;
        cout << "\nIvesk egzamino pazymi: ";
        cin >> A[i].egzas;
        while (cin.fail() ||  A[i].egzas < 1 || A[i].egzas > 10)
        {
            cout << "\nIvesk skaiciu is desimtbales sistemos!: ";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> A[i].egzas;
        }
        cout << "\nParasyk S, jei nori pats suvesti kiek nd pazymiu turejo studentas, jei nenori - N: ";
        cin >> t;
        while (t != 'S' && t != 'N' && t != 's' && t != 'n')
        {
            cout << "\nIvesk S arba N!: "; cin >> t;
        }
            
            if (t == 'S' || t == 's')
            {
                cout << "\nKiek turi pazymiu?: "; cin >> n;
                while (cin.fail())
                {
                    cout << "\nIvesk skaiciu!: ";
                    cin.clear();
                    cin.ignore(256, '\n');
                    cin >> n;
                }
                for (int k = 0; k < n; k++)
                {
                    cout << "\nIvesk " << k + 1 << "-aji pazymi ";
                    cin >> A[i].paz[k];
                    while (cin.fail() || A[i].paz[k] < 1 || A[i].paz[k] > 10)
                    {
                        cout << "\nIvesk skaiciu is desimtbales sistemos!: ";
                        cin.clear();
                        cin.ignore(256, '\n');
                        cin >> A[i].paz[k];
                    }
                    sum += A[i].paz[k];
                }
            }
            else if (t == 'N' || t == 'n')
            {
                for (int k = 0; k < 10; k++)
                {

                    cout << "\nIvesk nd pazymi, jeigu pazymiu nera, ivesk -1: ";
                    cin >> A[i].paz[k];
                    if (A[i].paz[k] == -1)
                    {
                        break;
                    }
                        while (cin.fail() || A[i].paz[k] < 1 || A[i].paz[k] > 10)
                        {
                            cout << "\nIvesk skaiciu is desimtbales sistemos!: ";
                            cin.clear();
                            cin.ignore(256, '\n');
                            cin >> A[i].paz[k];
                        }

                        sum += A[i].paz[k];
                        n++;
                }
            }
        

        m = n;
        
        for (int j = m; j > 0; j--)
        {
            A[i].paz[j] = A[i].paz[j - 1];
        }
        A[i].paz[0] = A[i].egzas;
        m++;
        for (int k = 0; k < m; k++)
        {
            for (int j = 0; j < m - k - 1; j++)
            {
                if (A[i].paz[j] < A[i].paz[j + 1])
                {
                    temp = A[i].paz[j];
                    A[i].paz[j] = A[i].paz[j + 1];
                    A[i].paz[j + 1] = temp;
                }
            }
        }
        if (m % 2 == 0)
        {
            A[i].mediana = (A[i].paz[m / 2] + A[i].paz[m / 2 - 1]) / 2.0;
        }
        else
        {
            A[i].mediana = A[i].paz[m / 2];
        }
        if (n == 0)
        {
            A[i].pazymys = A[i].egzas;
        }
        else
        {
            A[i].pazymys = double(sum) / double(n) * 0.40 + double(A[i].egzas) * 0.60;
        }
        cout << "\nParasyk V, jei nori suzinoti vidurki, M, jei nori suzinoti mediana: "; cin >> g;
        while (g != 'V' && g != 'M' && g != 'v' && g != 'm')
        {
            cout << "\nIvesk V arba N!: "; cin >> g;
        }
        if (g == 'V' || g == 'v')
        {
            A[i].mediana = 0;
        }
        else if (g == 'M' || g == 'm')
        {
            A[i].pazymys = 0;
        }
    }

        cout << "\n" << left << setw(12) << "Vardas" << left << setw(12) << "Pavarde" << setw(13) << "Galutinis (Vid.)" << " / " << setw(16) << "Galutinis (Med.)" << endl;
        for (int j = 0; j < 60; j++)
        {
            cout << "-";
        }
    for (int i = 0; i < z; i++)
    {
       
        cout << "\n" << left << setw(12) << A[i].vardas << left << setw(12) << A[i].pavarde;
        if (A[i].pazymys == 0)
        {
            cout << setw(19) << fixed << setprecision(2) << " ";
        }
        else
        {
            cout << setw(19) << fixed << setprecision(2) << A[i].pazymys;
        }
        if (A[i].mediana == 0)
        {
            cout << left << setw(16) << fixed << setprecision(2) << " ";
        }
        else
        {
            cout << left << setw(16) << fixed << setprecision(2) << A[i].mediana << endl;
        }
    }
    return 0;
}
