#include <stdio.h>
#include <stdlib.h>

void prizonierulcastiga(int x, int n, int v[], int *ok, int lista[],
                        int *k, int cicluri[])
{
    // functia verifica daca prizonierul x reuseste sa-si gaseasca
    // numarul si creeaza o lista cu toate cutiile deschise de acesta
    int nrcd = 0, t;
    t = x;
    *(ok) = 0;
    lista[0] = x;
    while (v[t - 1] != x)
    {
        // instructiunile se repeta cat timp valoarea din cutia t-1
        //(pentru ca numerotarea incepe de la 0) nu este egala
        // cu numarul prizonierului
        nrcd++;
        t = v[t - 1];
        // numarul cutiei urmatoare devine numarul din
        // interiorul cutiei precedente
        lista[nrcd] = t;
        // numarul cutiei deschise este adaugat la lista
        cicluri[t] = 1;
        // vectorul cicluri este folosit pentru a diferentia elementele care
        // pot fi inceputul unui ciclu de celelalte, astfel incat
        // ciclurile sa nu se repete
        // astfel numarul de la inceputul unui ciclu ia valoarea 0, in timp
        // ce celelalte numere din ciclu iau valoarea 1 in vectorul cicluri
    }
    nrcd = nrcd + 1;
    if (nrcd <= n / 2)
    {
        *(ok) = 1;
        // prin variabila ok se verifica daca prizonierul a reusit sa-si
        // gaseasca numele
        // aceasta a fost initializata cu 0 si devine 1 daca numarul de cutii
        // deschise pana la gasirea numarului prizonierului
        // este mai mic decat jumatatea numarului total de prizonieri
    }
    *(k) = nrcd;
    // k reprezinta numarul total de cutii deschise ce alcatuiesc un ciclu
}
void adaugaciclu(int v[], int n, int a[][500], int m)
{
    int j;
    for (j = 0; j < n; j++)
    {
        a[m][j] = v[j];
    }
    // ciclul transmis este adaugat pe o linie a matricei
}
void afisarecicluri(int a[][500], int n, int m)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        printf("%d", a[i][0]);
        for (j = 1; j < n; j++)
        {
            if (a[i][j] != 0)
            {
                printf(" %d", a[i][j]);
            }
        }
        printf("\n");
    }
    // se afiseaza ciclurile stocate in matrice
}
int main()
{
    int P, cutii[500], i, ok = 0, nrcd, lista[500], cicluri[501] = {0};
    int a[500][500], eliberare = 1, nrcicluri = 0, maxc = 0;
    scanf("%d", &P);
    for (i = 0; i < P; i++)
    {
        scanf("%d", &cutii[i]);
    }
    for (i = 0; i < P; i++)
    {
        prizonierulcastiga(i + 1, P, cutii, &ok, lista, &nrcd, cicluri);
        if (ok == 0)
        {
            eliberare = 0;
            // daca in urma apelului functiei prizonierulcastiga ok a primit
            // valoarea 0, inseamna ca unul dintre prizonieri nu a reusit
            // sa-si gaseasca numarul, motiv pentru care variabila eliberare
            // i a valoarea 0 si niciun prizonier nu va fi eliberat
        }
        if (cicluri[i + 1] == 0)
        {
            // daca numarul cu care a inceput ciclul, adica numarul
            // prizonierului si al primei cutii deschise, nu face parte din alt
            // ciclu, atunci ciclul salvat in vectorul lista poate fi
            // adaugat in matrice
            adaugaciclu(lista, nrcd, a, nrcicluri);
            nrcicluri++;
            if (nrcd > maxc)
            {
                maxc = nrcd;
                // se calculeaza numarul maxim de elemente dintr-un ciclu,
                // pentru afisarea de la final
            }
        }
    }
    if (eliberare == 0)
    {
        printf("Nu\n");
    }
    else
    {
        printf("Da\n");
    }
    afisarecicluri(a, maxc, nrcicluri);
}
