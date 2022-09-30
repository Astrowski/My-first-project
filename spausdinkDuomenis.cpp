#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include "spausdinkDuomenis.h"
#include "mediana.h"
#include "duomenys.h"

void spausdinkDuomenis(std::vector<duomenys> A, int n) //atspausdina rezultatus
{
    std::ofstream isvesk;
    isvesk.open("rezultatai.txt");
    isvesk << std::setw(20) << std::left << "Vardas"
        << std::setw(20) << std::left << "Pavarde"
        << std::setw(18) << std::left << "Galutinis(vid.)/"
        << std::left << "Galutinis(med.)\n";
    for (int j = 0; j < 73; j++)
    {
        isvesk << "-";
    }
    isvesk << std::endl;
    for (int i = 0; i < A.size(); i++)
    {
        isvesk << std::setw(20) << std::left << A[i].vardas
            << std::setw(20) << std::left << A[i].pavarde
            << std::setw(18) << std::left << std::fixed << std::setprecision(2) << A[i].rez
            << mediana(A[i].paz, n) << std::fixed << std::setprecision(2) << std::endl;
    }
    isvesk << "\n\n";
}