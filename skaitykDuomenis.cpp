#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <iterator>
#include "skaitykDuomenis.h"
#include "skaiciuokZodzius.h"

void skaitykDuomenis(std::vector<duomenys>& A, int* n)
{
    int sk = 0; // studentu skaicius
    int temp;
    std::ifstream skaityk;
    std::string tarpas;
    try
    {
        skaityk.open("studentai10000.txt");
        if (!skaityk.is_open())
            throw 0;
        {
            getline(skaityk >> std::ws, tarpas); // nuskaitymo metu ismetami tarpai, kad butu galima nuskaityti tik reiksmes
            *n = skaiciuokZodzius(tarpas) - 3;
            while (true)
            {
                A.resize(A.size() + 1);
                skaityk >> A.at(sk).vardas;
                if (skaityk.eof()) // tikrinam ar nuskaitymas pasieke pabaiga
                {
                    A.pop_back();
                    break;
                }
                skaityk >> A.at(sk).pavarde;
                for (int i = 0; i < *n; i++)
                {
                    skaityk >> temp;
                    A.at(sk).rez += temp;
                    A.at(sk).paz.push_back(temp);
                }
                skaityk >> A.at(sk).egzas;
                A.at(sk).rez = A.at(sk).rez / *n;
                A.at(sk).rez = A.at(sk).rez * 0.40 + 0.60 * A.at(sk).egzas;
                sk++;
            }
        }
    }
    catch (int e)
    {
        std::cout << "Tokio failo nera! " << e << std::endl;
    }
}