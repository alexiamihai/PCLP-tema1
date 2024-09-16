#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structura in care sunt retinute datele fiecarei masini
typedef struct masina
{
    char *brand, *numar, *combustibil;
    double consum;
    int km;
} masina;

// functie pentru rezolvarea cerintei a
void statistica_combustibil(masina *m, int N, int *benz, int *mot,
                            int *hib, int *el)
{
    int i;
    // pentru fiecare masina se verifica ce tip de combustibil are
    // si se incrementeaza variabila corespunzatoare numarului de masini
    // cu acel tip de combustibil
    for (i = 0; i < N; i++)
    {
        if (strcmp(m[i].combustibil, "benzina") == 0)
        {
            (*benz)++;
        }
        if (strcmp(m[i].combustibil, "motorina") == 0)
        {
            (*mot)++;
        }
        if (strcmp(m[i].combustibil, "hibrid") == 0)
        {
            (*hib)++;
        }
        if (strcmp(m[i].combustibil, "electric") == 0)
        {
            (*el)++;
        }
    }
}
// functie pentru rezolvarea cerintei b
void consum_total_de_combustibil(masina *m, int N, int *v, int *k,
                                 double *ct, double *st)
{
    double consum[100], suma[100], c = 0, s = 0;
    int i, j, unic[100] = {0};
    (*k) = 0;
    // pentru fiecare masina se calculeaza in vectorii consum[] si suma[]
    // consumul total de combustibil si suma totala platita
    for (i = 0; i < N; i++)
    {
        consum[i] = (m[i].consum * m[i].km) / 100;
        consum[i] = (double)consum[i];
        // in functie de tipul de combustibil folosit, se calculeaza suma
        if (strcmp(m[i].combustibil, "benzina") == 0 ||
            strcmp(m[i].combustibil, "hibrid") == 0)
        {
            suma[i] = consum[i] * 8.02;
            suma[i] = (double)suma[i];
        }
        if (strcmp(m[i].combustibil, "motorina") == 0)
        {
            suma[i] = consum[i] * 9.29;
            suma[i] = (double)suma[i];
        }
        if (strcmp(m[i].combustibil, "electric") == 0)
        {
            suma[i] = 0;
        }
    }
    for (i = 0; i < N; i++)
    {
        // vectorul unic[] asigura faptul ca atunci cand calculam suma si
        // consumul pentru fiecare marca de masina, nu vom avea marci care
        // sa se repete
        // atunci cand se intalneste o masina x cu unic[x] == 0, consumul si
        // suma platita pentru ea sunt adaugate la consumul total al marcii si
        // la suma totala platita a marcii
        // se cauta apoi toate masinile cu aceeasi marca, iar consumul si suma
        // lor sunt si ele adaugate la consumul si suma totala
        // acestea primesc ca valoare in vectorul unic[] 1, pentru a se
        // asigura faptul ca nu se va calcula inca o data consumul
        //si suma pentru ele
        if (unic[i] == 0)
        {
            c = c + consum[i];
            s = s + suma[i];
            for (j = i + 1; j < N; j++)
            {
                if (strcmp(m[i].brand, m[j].brand) == 0)
                {
                    unic[j] = 1;
                    c = c + consum[j];
                    s = s + suma[j];
                }
            }
            // rezultatele sunt retinute in vectori parametri pentru a putea
            // fi accesate in main
            ct[(*k)] = c;
            st[(*k)] = s;
            v[(*k)] = i;
            (*k)++;
            c = 0;
            s = 0;
        }
    }
}
// functie pentru rezolvarea cerintei c
void numere_de_inmatriculare(masina *m, int N, int *ok, int *k, int *v)
{
    int j, i, bun, nrlit1, nrcif, nrlit2;
    (*ok) = 0;
    // ok- variabila care verifica daca toate numerele de inmatriculare ale
    // masinilor sunt corecte
    (*k) = 0;
    // k- variabila in care se retine numarul de masini cu numar de
    // inmatriculare gresit
    for (i = 0; i < N; i++)
    {
        // bun- variabila care verifica daca numarul de inmatriculare al
        // masinii este corespunzator
        bun = 0;
        // nrlit1- numarul de litere de la inceputul numarului
        nrlit1 = 0;
        // nrcif- numarul de cifre din numar
        nrcif = 0;
        // nrlit2- numarul de litere de la sfarsitul numarului
        nrlit2 = 0;
        j = 0;
        while (m[i].numar[j] >= 'A' && m[i].numar[j] <= 'Z')
        {
            nrlit1++;
            j++;
        }
        while (m[i].numar[j] >= '0' && m[i].numar[j] <= '9')
        {
            nrcif++;
            j++;
        }
        while (m[i].numar[j] >= 'A' && m[i].numar[j] <= 'Z')
        {
            nrlit2++;
            j++;
        }
        // daca numarul nu are litere la inceputul lui sau are mai mult
        // de doua litere, variabila bun devine 1
        if (nrlit1 < 1 || nrlit1 > 2)
        {
            bun = 1;
        }
        // daca numarul are mai putin de 2 cifre sau are mai mult de 3
        // variabila bun devine 1
        if (nrcif < 2 || nrcif > 3)
        {
            bun = 1;
        }
        // daca numarul nu are 3 litere la sfarsitul lui, variabila bun
        // devine 1
        if (nrlit2 != 3)
        {
            bun = 1;
        }
        // daca unul dintre numere are bun == 1, inseamna ca nu are un
        // numar de inmatriculare corespunzator si se retine numarul masinii
        // intr-un vector transmis ca parametru
        if (bun == 1)
        {
            (*ok) = 1;
            v[(*k)] = i;
            (*k)++;
        }
    }
}

int main()
{
    int N, i, benzina, motorina, hibrid, electric, ok, k, v[100];
    double sumatotala[100], consumtotal[100];
    char aux[20], op;
    scanf("%d", &N);
    getchar();
    masina *m = (masina *)malloc((N + 1) * sizeof(masina));
    // pentru fiecare masina i se citesc datele si se aloca exact cata memorie
    // este necesara pentru fiecare sir de caractere
    for (i = 0; i < N; i++)
    {
        scanf("%s", aux);
        getchar();
        m[i].brand = malloc(sizeof(char) * (strlen(aux) + 1));
        strcpy(m[i].brand, aux);
        scanf("%s", aux);
        getchar();
        m[i].numar = malloc(sizeof(char) * (strlen(aux) + 1));
        strcpy(m[i].numar, aux);
        scanf("%s", aux);
        getchar();
        m[i].combustibil = malloc(sizeof(char) * (strlen(aux) + 1));
        strcpy(m[i].combustibil, aux);
        scanf("%lf", &m[i].consum);
        scanf("%d", &m[i].km);
    }
    getchar();
    // se citeste litera corespunzatoare cerintei si in functie de
    // rezultat se apeleaza una dintre cele 3 functii
    scanf("%c", &op);
    if (op == 'a')
    {
        benzina = 0;
        motorina = 0;
        hibrid = 0;
        electric = 0;
        statistica_combustibil(m, N, &benzina, &motorina, &hibrid, &electric);
        printf("benzina - %d\n", benzina);
        printf("motorina - %d\n", motorina);
        printf("hibrid - %d\n", hibrid);
        printf("electric - %d\n", electric);
    }
    if (op == 'b')
    {
        consum_total_de_combustibil(m, N, v, &k, consumtotal, sumatotala);
        for (i = 0; i < k; i++)
        {
            printf("%s a consumat %.2lf - %.2lf lei\n", m[v[i]].brand,
                   consumtotal[i], sumatotala[i]);
        }
    }
    if (op == 'c')
    {
        numere_de_inmatriculare(m, N, &ok, &k, v);
        if (ok == 0)
        {
            printf("Numere corecte!\n");
        }
        else
        {
            for (i = 0; i < k; i++)
            {
                printf("%s cu numarul %s: numar invalid\n", m[v[i]].brand,
                       m[v[i]].numar);
            }
        }
    }
}
