#include "mediana.h"
double mediana(std::vector<int> pazymys, int n) //funkcija medianos skaiciavimui
{
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        if (pazymys[i] != 0)
        {
            m++;
        }
        if (pazymys[i] == -1)
        {
            pazymys[i] = 0;
            m--;
            break;
        }
        for (int j = i; j < n; j++)
        {
            if (pazymys[i] > pazymys[j])
            {
                std::swap(pazymys[i], pazymys[j]);
            }
        }

    }

    if (m % 2 == 0)
    {
        return double(((pazymys[m / 2 - 1]) + (pazymys[(m / 2)])) / 2.0);
    }
    else
    {
        return double(pazymys[(m / 2)]);
    }
}