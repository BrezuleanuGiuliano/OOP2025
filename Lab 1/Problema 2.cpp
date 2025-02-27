#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;


struct cuvinte {
    int lungime;
    char s[100];
}cuv[100];


int numarCuvant = 0;

int main() 
{


    char propozitie[256];
    printf("Introdu propozitia: ");
    while (scanf_s("%255s", propozitie, (unsigned)_countof(propozitie)))
    {
        
        for (int i = 0; i < strlen(propozitie); i++)
            cuv[numarCuvant].s[i] = propozitie[i];
            cuv[numarCuvant].lungime = strlen(propozitie);
            numarCuvant++;
        
    }

    for (int i = 0; i <numarCuvant-1; i++)
        for (int j = i + 1; j < numarCuvant; j++)
        {
            if (cuv[i].lungime < cuv[j].lungime)
            {
                cuv[numarCuvant] = cuv[i];
                cuv[i] = cuv[j];
                cuv[j] = cuv[numarCuvant];
            }
            else if ((cuv[i].lungime == cuv[j].lungime))
            {
                int k = 0;
                while (cuv[i].s[k] < cuv[j].s[k] && k < cuv[i].lungime)
                {
                    k++;
                }
                if (k != cuv[i].lungime)
                {
                    cuv[numarCuvant] = cuv[i];
                    cuv[i] = cuv[j];
                    cuv[j] = cuv[numarCuvant];
                }
            }
        }
    
    
    
    for (int i = 0; i <  numarCuvant; i++) {
        printf("%s\n", cuv[i].s);
    }

    return 0;
}