#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CodificareA(char *s, char *cheie)
{
    char a[50][500], t[500];
    int i = 0, j = 0, k = 0, n, aux, m, v[50] = {0}, v2[50] = {0};
    n = strlen(cheie) - 1;
    // n retine lungimea cheii, fara terminatorul de la final
    // in cazul in care sirul are un terminator la final, numarul de linii
    // al matricei se calculeaza in functie de strlen(s)-1, fara a lua in
    // calcul terminatorul
    if (s[strlen(s) - 1] == '\n')
    {
        m = (strlen(s) - 1) / n;
        if ((n * m) != (strlen(s) - 1))
        {
            m++;
        }
        // daca lungimea sirului nu se poate imparti exact la numarul de 
        // coloane atunci m creste pentru a se asigura faptul ca toate
        // caracterele din sir vor incapea in matrice
        m++;
        // linia cheii
    }
    // similar, cazul in care sirul nu are la final un terminator
    else
    {
        m = (strlen(s)) / n;
        if ((n * m) != (strlen(s)))
        {
            m++;
        }
        m++;
    }
    // in prima linie din matrice se salveaza caracterele sirului cheie
    for (i = 0; i < n; i++)
    {
        a[0][i] = cheie[i];
    }
    // matricea se umple cu elementele sirului, pe linii
    i = 1;
    for (k = 0; k < strlen(s); k++)
    {
        if (s[k] != '\n')
        {
            a[i][j] = s[k];
            j++;
            if (j == n)
            {
                i++;
                j = 0;
            }
        }
    }
    // daca ultima linie nu este completa, dupa ce matricea a fost completata
    // cu elementele sirului, atunci caracterele ramase devin spatii
    if (j != 0)
    {
        for (k = j; k < n; k++)
            a[i][k] = ' ';
    }
    // primul vector v este folosit pentru sortarea cheii
    // cel de-al doilea vector retine numarul coloanei corespunzatoare
    // unui anumit caracter din cheie
    for (i = 0; i < n; i++)
    {
        v[i] = a[0][i];
        v2[i] = i;
    }
    // vectorii sunt sortati, prin metoda selection sort
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (v[i] > v[j])
            {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
                aux = v2[i];
                v2[i] = v2[j];
                v2[j] = aux;
            }
        }
    }
    k = 0;
    // daca elementele din matrice sunt litere sau spatii, atunci
    // ele sunt adaugate in sirul t
    // elementele matricei sunt luate pe linii, in ordinea dictata de sortarea
    // precedenta
    for (j = 0; j < n; j++)
    {
        for (i = 1; i < m; i++)
        {
            if ((a[i][v2[j]] >= 'a' && a[i][v2[j]] <= 'z') ||
                (a[i][v2[j]] >= 'A' && a[i][v2[j]] <= 'Z')
                || a[i][v2[j]] == ' ')
            {
                t[k] = a[i][v2[j]];
            }
            // conditie care asigura faptul ca sirul va fi format doar din
            // spatii si caractere
            else
                t[k] = ' ';
            k++;
        }
    }
    t[k] = '\0';
    strcpy(s, t);
}
void DecodificareA(char *s, char *cheie)
{
    char a[50][500], t[500];
    int i = 0, q, tmp, j = 0, k = 0, n, aux, m, v[50] = {0},
    v2[50] = {0}, v3[50] = {0};
    n = strlen(cheie) - 1;
    // n retine lungimea cheii, fara terminatorul de la final
    // in cazul in care sirul are un terminator la final, numarul de linii
    // al matricei se calculeaza in functie de strlen(s)-1, fara a lua in
    // calcul terminatorul
    if (s[strlen(s) - 1] == '\n')
    {
        m = (strlen(s) - 1) / n;
        if ((n * m) != (strlen(s) - 1))
            m++;
        // daca lungimea sirului nu se poate imparti exact la numarul
        // de coloane atunci m creste pentru a se asigura faptul ca
        // toate caracterele din sir vor incapea in matrice
        m++;
        // linia cheii
    }
    // similar, cazul in care sirul nu are la final un terminator
    else
    {
        m = (strlen(s)) / n;
        if ((n * m) != (strlen(s)))
            m++;
        m++;
    }
    // primul vector v este folosit pentru sortarea cheii
    // cel de-al doilea vector retine numarul coloanei corespunzatoare
    // unui anumit caracter din cheie
    for (i = 0; i < n; i++)
    {
        v[i] = cheie[i];
        v2[i] = i;
    }
    // vectorii sunt sortati, prin metoda selection sort
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (v[i] > v[j])
            {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
                tmp = v2[i];
                v2[i] = v2[j];
                v2[j] = tmp;
            }
        }
    }
    // in prima linie din matrice se salveaza caracterele sirului cheie
    for (i = 0; i < n; i++)
    {
        a[0][i] = (char)v[i];
    }
    // matricea se umple cu elementele sirului, pe coloane
    i = 1;
    j = 0;
    for (k = 0; k < strlen(s); k++)
    {
        a[i][j] = s[k];
        i++;
        if (i == m)
        {
            j++;
            i = 1;
        }
    }
    // daca in matricea nu se poate completa doar cu elementele sirului
    // restul elementelor devin spatii
    if (i != 1)
    {
        for (k = i; k < m; k++)
            a[k][j] = ' ';
    }
    if (i == 1 && j < n)
    {
        for (k = 1; k < m; k++)
            a[k][j] = ' ';
    }
    if (j != n)
    {
        for (k = j + 1; k < n; k++)
        {
            for (q = 0; q < m; q++)
                a[q][k] = ' ';
        }
    }
    // ordinea in care trebuie preluate elementele de pe linie, in functie
    // de sortarea precedenta a cheii
    // v3 retine aceasta ordine
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (v2[j] == i)
            {
                break;
            }
        }
        v3[i] = j;
    }
    // daca elementele din matrice sunt litere sau spatii, atunci
    // ele sunt adaugate in sirul t
    // elementele matricei sunt luate pe linii, in ordinea dictata de sortarea
    // precedenta
    k = 0;
    for (i = 1; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if ((a[i][v3[j]] >= 'a' && a[i][v3[j]] <= 'z')
            ||(a[i][v3[j]] >= 'A' && a[i][v3[j]] <= 'Z')
            || a[i][v3[j]] == ' ')
            {
                t[k] = a[i][v3[j]];
            }
            // conditie care asigura faptul ca sirul va fi format doar din
            // spatii si caractere
            else
                t[k] = ' ';
            k++;
        }
    }
    t[k] = '\0';
    strcpy(s, t);
}
void CodificareB(char *s, int i)
{
    char p[500], t[500];
    int j;
    if (s[strlen(s) - 1] == '\n')
    {
        s[strlen(s) - 1] = '\0';
    }
    strcpy(t, s);
    strcpy(p, s);
    // in sirul p se retin ultimele i caractere din s
    strcpy(p, p + (strlen(s) - i));
    t[strlen(s) - i] = '\0';
    // se modifica fiecare caracter din p, adaugandu-se i
    for (j = 0; j < strlen(p); j++)
    {
        // cazul in care caracterul este o litera mica
        if (p[j] >= 'a' && p[j] <= 'z')
        {
            // cazul in care adaugandu-se i, caracterul nu va mai fi o litera
            if (p[j] + i > 'z')
            {
                p[j] = 'A' + i - ('z' - p[j] + 1);
            }
            else
                p[j] = p[j] + i;
        }
        // cazul in care caracterul este o litera mare
        else if (p[j] >= 'A' && p[j] <= 'Z')
        {
            // cazul in care adaugandu-se i, caracterul nu va mai fi o litera
            if (p[j] + i > 'Z')
            {
                p[j] = 'a' + i - ('Z' - p[j] + 1);
            }
            else
                p[j] = p[j] + i;
        }
    }
    p[i] = '\0';
    // la sirul p modificat, se lipeste restul sirului s, retinut in t
    // astfel, ultimele i caractere modificate sunt aduse la inceputul sirului
    strcat(p, t);
    strcpy(s, p);
}
void DecodificareB(char *s, int i)
{
    char p[500], t[500];
    int j;
    if (s[strlen(s) - 1] == '\n')
        s[strlen(s) - 1] = '\0';
    strcpy(t, s);
    strcpy(p, s + i);
    // in p se pastreaza partea sirului s, care nu trebuie modificata
    t[i] = '\0';
    // terminatorul se pune pentru ca t sa retina doar primele i caractere 
    // din s caracterele modificate, ce trebuie decodificate
    // se modifica fiecare caracter din t, scazandu-se din el i
    for (j = 0; j < strlen(t); j++)
    {
        // cazul in care caracterul este o litera mica
        if (t[j] >= 'a' && t[j] <= 'z')
        {
            // cazul in care scazandu-se i, caracterul nu va mai fi o litera
            if (t[j] - i < 'a')
            {
                t[j] = 'Z' - i + (t[j] - 'a' + 1);
            }
            else
                t[j] = t[j] - i;
        }
        // cazul in care caracterul este o litera mare
        else if (t[j] >= 'A' && t[j] <= 'Z')
        {
            // cazul in care scazandu-se i, caracterul nu va mai fi o litera
            if (t[j] - i < 'A')
            {
                t[j] = 'z' - i + (t[j] - 'A' + 1);
            }
            else
                t[j] = t[j] - i;
        }
    }
    strcat(p, t);
    // la sirul p se lipeste sirul modificat, t
    // astfel, primele i caractere modificate sunt aduse la finalul sirului
    strcpy(s, p);
}

int main()
{
    char s[500], op[20], cheie[50];
    int i;
    fgets(s, 500, stdin);
    scanf("%s", op);
    getchar();
    // se citesc operatii pana la intalnirea sirului "STOP"
    while (strcmp(op, "STOP") != 0)
    {
        // cazul in care operatia se termina cu A
        // acesta genereaza alte 2 cazuri, cel in care operatia incepe cu C
        // si ne putem da seama ca este vorba de CodificareA
        // si cel in care aceasta incepe cu D si este DecodificareA
        if (op[strlen(op) - 1] == 'A')
        {
            fgets(cheie, 50, stdin);
            if (op[0] == 'C')
            {
                CodificareA(s, cheie);
                printf("%s\n", s);
            }
            if (op[0] == 'D')
            {
                DecodificareA(s, cheie);
                printf("%s\n", s);
            }
        }
        // cazul in care operatia se termina cu B
        // acesta genereaza alte 2 cazuri, cel in care operatia incepe cu C
        // si ne putem da seama ca este vorba de Codificareb
        // si cel in care aceasta incepe cu D si este Decodificareb
        if (op[strlen(op) - 1] == 'B')
        {
            scanf("%d", &i);
            if (op[0] == 'C')
            {
                CodificareB(s, i);
                printf("%s\n", s);
            }
            if (op[0] == 'D')
            {
                DecodificareB(s, i);
                printf("%s\n", s);
            }
            getchar();
        }

        scanf("%s", op);
        getchar();
    }
    return 0;
}
