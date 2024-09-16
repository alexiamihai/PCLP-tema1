#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void adunare(char *a, char *b, char *c, int N)
{
    int ok, k, reza[1001], imza[1001], rezb[1001],
        imzb[1001], rez[1001], imz[1001], i;
    // se construiesc vectorii formati din cifrele corespunzatoare
    // fiecarui caracter din sirurile a si b
    for (i = 1; i < (N - 1) / 2; i++)
    {
        reza[i] = a[i] - '0';
    }
    for (i = (N - 1) / 2 + 1; i < N - 1; i++)
    {
        imza[i] = a[i] - '0';
    }
    for (i = 1; i < (N - 1) / 2; i++)
    {
        rezb[i] = b[i] - '0';
    }
    for (i = (N - 1) / 2 + 1; i < N - 1; i++)
    {
        imzb[i] = b[i] - '0';
    }
    // adunarea partii reale pentru numerele care au acelasi semn
    if ((a[0] == '0' && b[0] == '0') || (a[0] == '1' && b[0] == '1'))
    {
        ok = 0;
        // adunarea incepe de la cifrele de pe ultimele pozitii, iar in
        // cazul in care suma depaseste numarul 10, se pastreaza doar
        // restul sumei la impartirea cu 10, iar ok devine 1, urmand sa
        // fie adaugat la adunarea urmatoarelor 2 cifre
        for (i = (N - 1) / 2 - 1; i >= 1; i--)
        {
            rez[i] = (reza[i] + rezb[i] + ok) % 10;
            if (reza[i] + rezb[i] + ok > 9)
                ok = 1;
            else
                ok = 0;
        }
    }
    // bitul de semn al partii reale ia valoarea 0, daca ambele numere sunt
    // pozitive si 1, daca numerele sunt negative
    if (a[0] == '0' && b[0] == '0')
    {
        rez[0] = 0;
    }
    if (a[0] == '1' && b[0] == '1')
    {
        rez[0] = 1;
    }
    // adunarea partii imaginare pentru numerele care au acelasi semn
    if ((a[(N - 1) / 2] == '0' && b[(N - 1) / 2] == '0')
    || (a[(N - 1) / 2] == '1' && b[(N - 1) / 2] == '1'))
    {
        ok = 0;
        for (i = N - 2; i > (N - 1) / 2; i--)
        {
            imz[i] = (imza[i] + imzb[i] + ok) % 10;
            if (imza[i] + imzb[i] + ok > 9)
                ok = 1;
            else
                ok = 0;
        }
    }
    // bitul de semn al partii imaginare ia valoarea 0, daca ambele numere sunt
    // pozitive si 1, daca numerele sunt negative
    if (a[(N - 1) / 2] == '0' && b[(N - 1) / 2] == '0')
    {
        imz[(N - 1) / 2] = 0;
    }
    if (a[(N - 1) / 2] == '1' && b[(N - 1) / 2] == '1')
    {
        imz[(N - 1) / 2] = 1;
    }
    // adunarea partii reale, in cazul in care numerele au semn diferit
    // cazul in care partea reala a lui a este pozitiva, iar cea a lui b
    // este negativa
    if (a[0] == '0' && b[0] == '1')
    {
        // deoarece in acest caz, operatia devine, de fapt, o scadere
        // aflam care dintre numere are partea reala mai mare
        // comparam cifra cu cifra si imediat ce gasim 2 cifre care nu
        // sunt egale, putem decide care dintre numere este mai mare
        ok = 0;
        for (i = 1; i < (N - 1) / 2; i++)
        {
            if (a[i] < b[i])
            {
                ok = 1;
                break;
            }
            else if (b[i] == a[i])
            {
                ok = 0;
            }
            else
                break;
        }
        // cazul in care a are partea reala mai mare decat partea reala a lui b
        if (ok == 0)
        {
            // in k se pastreaza numarul care trebuie scazut din cifra curenta,
            // in cazul in care la scaderea precedenta, a fost necesara
            // adaugarea lui 10 la cifra descazutului
            k = 0;
            for (i = (N - 1) / 2 - 1; i > 0; i--)
            {
                reza[i] = reza[i] - k;
                // daca cifra din care se scade este prea mica, i se adauga 10,
                // urmand ca din cifra urmatoare sa se scada 1
                if (reza[i] < rezb[i])
                {
                    rez[i] = 10 + reza[i] - rezb[i];
                    k = 1;
                }
                else
                {
                    rez[i] = reza[i] - rezb[i];
                    k = 0;
                }
            }
            // intrucat s-a scazut un numar negativ dintr-un numar pozitiv,
            // bitul de semn devine 0
            rez[0] = 0;
        }
        // cazul in care b are partea reala mai mare decat partea reala a lui a
        else
        {
            k = 0;
            for (i = (N - 1) / 2 - 1; i > 0; i--)
            {
                // daca cifra din care se scade este prea mica, i se adauga 10,
                // urmand ca din cifra urmatoare sa se scada 1
                rezb[i] = rezb[i] - k;
                if (rezb[i] < reza[i])
                {
                    rez[i] = 10 + rezb[i] - reza[i];
                    k = 1;
                }
                else
                {
                    rez[i] = rezb[i] - reza[i];
                    k = 0;
                }
            }
            // intrucat s-a scazut un numar pozitiv dintr-un numar negativ,
            // bitul de semn devine 1
            rez[0] = 1;
        }
    }
    // cazul in care partea reala a lui a este negativa, iar cea a lui b
    // este pozitiva
    if (a[0] == '1' && b[0] == '0')
    {
        ok = 0;
        for (i = 1; i <= (N - 1) / 2 - 1; i++)
        {
            if (b[i] < a[i])
            {
                ok = 1;
                break;
            }
            else if (b[i] == a[i])
            {
                ok = 0;
            }
            else
                break;
        }
        // cazul in care b are partea reala mai mare decat partea reala a lui a
        if (ok == 0)
        {
            k = 0;
            for (i = (N - 1) / 2 - 1; i > 0; i--)
            {
                rezb[i] = rezb[i] - k;
                if (rezb[i] < reza[i])
                {
                    rez[i] = 10 + rezb[i] - reza[i];
                    k = 1;
                }
                else
                {
                    rez[i] = rezb[i] - reza[i];
                    k = 0;
                }
            }
            // intrucat s-a scazut un numar negativ dintr-un numar pozitiv,
            // bitul de semn devine 0
            rez[0] = 0;
        }
        // cazul in care a are partea reala mai mare decat partea reala a lui b
        else
        {
            k = 0;
            for (i = (N - 1) / 2 - 1; i > 0; i--)
            {
                reza[i] = reza[i] - k;
                if (reza[i] < rezb[i])
                {
                    rez[i] = 10 + reza[i] - rezb[i];
                    k = 1;
                }
                else
                {
                    rez[i] = reza[i] - rezb[i];
                    k = 0;
                }
            }
            // intrucat s-a scazut un numar pozitiv dintr-un numar negativ,
            // bitul de semn devine 1
            rez[0] = 1;
        }
    }
    // adunarea partii imaginare, in cazul in care numerele au semn diferit
    // cazul in care partea imaginara a lui a este pozitiva, iar cea a lui b
    // este negativa
    if (a[(N - 1) / 2] == '0' && b[(N - 1) / 2] == '1')
    {
        ok = 0;
        for (i = (N - 1) / 2 + 1; i <= N - 2; i++)
        {
            if (a[i] < b[i])
            {
                ok = 1;
                break;
            }
            else if (b[i] == a[i])
            {
                ok = 0;
            }
            else
                break;
        }
        // cazul in care a are partea imaginara mai mare decat partea
        //reala a lui b
        if (ok == 0)
        {
            k = 0;
            for (i = N - 2; i > (N - 1) / 2; i--)
            {
                imza[i] = imza[i] - k;
                if (imza[i] < imzb[i])
                {
                    imz[i] = 10 + imza[i] - imzb[i];
                    k = 1;
                }
                else
                {
                    imz[i] = imza[i] - imzb[i];
                    k = 0;
                }
            }
            // intrucat s-a scazut un numar negativ dintr-un numar pozitiv,
            // bitul de semn devine 0
            imz[(N - 1) / 2] = 0;
        }
        // cazul in care b are partea imaginara mai mare decat partea
        //imaginara a lui a
        else
        {
            k = 0;
            for (i = N - 2; i > (N - 1) / 2; i--)
            {
                imzb[i] = imzb[i] - k;
                if (imzb[i] < imza[i])
                {
                    imz[i] = 10 + imzb[i] - imza[i];
                    k = 1;
                }
                else
                {
                    imz[i] = imzb[i] - imza[i];
                    k = 0;
                }
            }
            // intrucat s-a scazut un numar pozitiv dintr-un numar negativ,
            // bitul de semn devine 1
            imz[(N - 1) / 2] = 1;
        }
    }
    // cazul in care partea imaginara a lui b este pozitiva, iar cea a lui a
    // este negativa
    if (a[(N - 1) / 2] == '1' && b[(N - 1) / 2] == '0')
    {
        ok = 0;
        for (i = (N - 1) / 2 + 1; i < N - 1; i++)
        {
            if (b[i] < a[i])
            {
                ok = 1;
                break;
            }
            else if (b[i] == a[i])
            {
                ok = 0;
            }
            else
                break;
        }
        // cazul in care b are partea imaginara mai mare decat partea
        //imaginara a lui a
        if (ok == 0)
        {
            k = 0;
            for (i = N - 2; i > (N - 1) / 2; i--)
            {
                imzb[i] = imzb[i] - k;
                if (imzb[i] < imza[i])
                {
                    imz[i] = 10 + imzb[i] - imza[i];
                    k = 1;
                }
                else
                {
                    imz[i] = imzb[i] - imza[i];
                    k = 0;
                }
            }
            // intrucat s-a scazut un numar negativ dintr-un numar pozitiv,
            // bitul de semn devine 0
            imz[(N - 1) / 2] = 0;
        }
        // cazul in care a are partea imaginara mai mare decat partea
        //reala a lui b
        else
        {
            k = 0;
            for (i = N - 2; i > (N - 1) / 2; i--)
            {
                imza[i] = imza[i] - k;
                if (imza[i] < imzb[i])
                {
                    imz[i] = 10 + imza[i] - imzb[i];
                    k = 1;
                }
                else
                {
                    imz[i] = imza[i] - imzb[i];
                    k = 0;
                }
            }
            // intrucat s-a scazut un numar pozitiv dintr-un numar negativ,
            // bitul de semn devine 1
            imz[(N - 1) / 2] = 1;
        }
    }
    // sirul c este alcatuit din toate elementele celor 2 vectori,
    // transformate in caractere
    for (i = 0; i <= (N - 1) / 2 - 1; i++)
    {
        c[i] = rez[i] + '0';
    }
    for (i = (N - 1) / 2; i < N - 1; i++)
    {
        c[i] = imz[i] + '0';
    }
    c[N - 1] = '\0';
}
void scadere(char *a, char *b, char *c, int N)
{
    int ok, k, reza[1001], imza[1001], rezb[1001],
        imzb[1001], rez[1001], imz[1001], i;
    // se construiesc vectorii formati din cifrele corespunzatoare
    // fiecarui caracter din sirurile a si b
    for (i = 1; i < (N - 1) / 2; i++)
    {
        reza[i] = a[i] - '0';
    }
    for (i = (N - 1) / 2 + 1; i < N - 1; i++)
    {
        imza[i] = a[i] - '0';
    }
    for (i = 1; i < (N - 1) / 2; i++)
    {
        rezb[i] = b[i] - '0';
    }
    for (i = (N - 1) / 2 + 1; i < N - 1; i++)
    {
        imzb[i] = b[i] - '0';
    }
    // scaderea partii reale pentru numerele care au semn diferit
    // operatia devine o adunare de numere cu acelasi semn
    if ((a[0] == '0' && b[0] == '1') || (a[0] == '1' && b[0] == '0'))
    {
        ok = 0;
        for (i = (N - 1) / 2 - 1; i >= 1; i--)
        {
            // adunarea incepe de la cifrele de pe ultimele pozitii, iar in
            // cazul in care suma depaseste numarul 10, se pastreaza doar
            // restul sumei la impartirea cu 10, iar ok devine 1, urmand sa
            // fie adaugat la adunarea urmatoarelor 2 cifre
            rez[i] = (reza[i] + rezb[i] + ok) % 10;
            if (reza[i] + rezb[i] + ok > 9)
                ok = 1;
            else
                ok = 0;
        }
    }
    // bitul de semn al partii reale ia valoarea 0, daca se scade un numar
    // negativ dintr-un numar pozitiv si 1, daca se scade un numar pozitiv
    // dintr-un numar negativ
    if (a[0] == '0' && b[0] == '1')
    {
        rez[0] = 0;
    }
    if (a[0] == '1' && b[0] == '0')
    {
        rez[0] = 1;
    }
    // scaderea partii imaginare pentru numerele care au semn diferit
    if ((a[(N - 1) / 2] == '0' && b[(N - 1) / 2] == '1') ||
    (a[(N - 1) / 2] == '1' && b[(N - 1) / 2] == '0'))
    {
        ok = 0;
        for (i = N - 2; i > (N - 1) / 2; i--)
        {
            imz[i] = (imza[i] + imzb[i] + ok) % 10;
            if (imza[i] + imzb[i] + ok > 9)
                ok = 1;
            else
                ok = 0;
        }
    }
    // bitul de semn al partii reale ia valoarea 0, daca se scade un numar
    // negativ dintr-un numar pozitiv si 1, daca se scade un numar pozitiv
    // dintr-un numar negativ
    if (a[(N - 1) / 2] == '0' && b[(N - 1) / 2] == '1')
    {
        imz[(N - 1) / 2] = 0;
    }
    if (a[(N - 1) / 2] == '1' && b[(N - 1) / 2] == '0')
    {
        imz[(N - 1) / 2] = 1;
    }
    // scaderea partii reale pentru numerele care au acelasi semn
    // cazul in care partea reala a ambelor numere este pozitiva
    if (a[0] == '0' && b[0] == '0')
    {
        ok = 0;
        for (i = 1; i < (N - 1) / 2; i++)
        {
            if (a[i] < b[i])
            {
                ok = 1;
                break;
            }
            else if (b[i] == a[i])
            {
                ok = 0;
            }
            else
                break;
        }
        // cazul in care a are partea reala mai mare decat partea reala a lui b
        if (ok == 0)
        {
            k = 0;
            for (i = (N - 1) / 2 - 1; i > 0; i--)
            {
                reza[i] = reza[i] - k;
                if (reza[i] < rezb[i])
                {
                    rez[i] = 10 + reza[i] - rezb[i];
                    k = 1;
                }
                else
                {
                    rez[i] = reza[i] - rezb[i];
                    k = 0;
                }
            }
            // intrucat s-a scazut un numar negativ dintr-un numar pozitiv,
            // bitul de semn devine 0
            rez[0] = 0;
        }
        // cazul in care b are partea reala mai mare decat partea reala a lui a
        else
        {
            k = 0;
            for (i = (N - 1) / 2 - 1; i > 0; i--)
            {
                rezb[i] = rezb[i] - k;
                if (rezb[i] < reza[i])
                {
                    rez[i] = 10 + rezb[i] - reza[i];
                    k = 1;
                }
                else
                {
                    rez[i] = rezb[i] - reza[i];
                    k = 0;
                }
            }
            // intrucat s-a scazut un numar pozitiv dintr-un numar negativ,
            // bitul de semn devine 1
            rez[0] = 1;
        }
    }
    // cazul in care partea reala a ambelor numere este negativa
    if (a[0] == '1' && b[0] == '1')
    {
        ok = 0;
        for (i = 1; i <= (N - 1) / 2 - 1; i++)
        {
            if (b[i] < a[i])
            {
                ok = 1;
                break;
            }
            else if (b[i] == a[i])
            {
                ok = 0;
            }
            else
                break;
        }
        // cazul in care b are partea reala mai mare decat partea reala a lui a
        if (ok == 0)
        {
            k = 0;
            for (i = (N - 1) / 2 - 1; i > 0; i--)
            {
                rezb[i] = rezb[i] - k;
                if (rezb[i] < reza[i])
                {
                    rez[i] = 10 + rezb[i] - reza[i];
                    k = 1;
                }
                else
                {
                    rez[i] = rezb[i] - reza[i];
                    k = 0;
                }
            }
            // intrucat s-a scazut un numar negativ dintr-un numar pozitiv,
            // bitul de semn devine 0
            rez[0] = 0;
        }
        // cazul in care a are partea reala mai mare decat partea reala a lui b
        else
        {
            k = 0;
            for (i = (N - 1) / 2 - 1; i > 0; i--)
            {
                reza[i] = reza[i] - k;
                if (reza[i] < rezb[i])
                {
                    rez[i] = 10 + reza[i] - rezb[i];
                    k = 1;
                }
                else
                {
                    rez[i] = reza[i] - rezb[i];
                    k = 0;
                }
            }
            // intrucat s-a scazut un numar pozitiv dintr-un numar negativ,
            // bitul de semn devine 1
            rez[0] = 1;
        }
    }
    // scaderea partii imaginare pentru numerele care au acelasi semn
    // cazul in care partea imaginara a ambelor numere este pozitiva
    if (a[(N - 1) / 2] == '0' && b[(N - 1) / 2] == '0')
    {
        ok = 0;
        for (i = (N - 1) / 2 + 1; i < N - 1; i++)
        {
            if (a[i] < b[i])
            {
                ok = 1;
                break;
            }
            else if (b[i] == a[i])
            {
                ok = 0;
            }
            else
                break;
        }
        // cazul in care a are partea imaginara mai mare decat partea imaginara
        //  a lui b
        if (ok == 0)
        {
            k = 0;
            for (i = N - 2; i > (N - 1) / 2; i--)
            {
                imza[i] = imza[i] - k;
                if (imza[i] < imzb[i])
                {
                    imz[i] = 10 + imza[i] - imzb[i];
                    k = 1;
                }
                else
                {
                    imz[i] = imza[i] - imzb[i];
                    k = 0;
                }
            }
            // intrucat s-a scazut un numar negativ dintr-un numar pozitiv,
            // bitul de semn devine 0
            imz[(N - 1) / 2] = 0;
        }
        // cazul in care b are partea imaginara mai mare decat partea imaginara
        //  a lui a
        else
        {
            k = 0;
            for (i = N - 2; i > (N - 1) / 2; i--)
            {
                imzb[i] = imzb[i] - k;
                if (imzb[i] < imza[i])
                {
                    imz[i] = 10 + imzb[i] - imza[i];
                    k = 1;
                }
                else
                {
                    imz[i] = imzb[i] - imza[i];
                    k = 0;
                }
            }
            // intrucat s-a scazut un numar pozitiv dintr-un numar negativ,
            // bitul de semn devine 1
            imz[(N - 1) / 2] = 1;
        }
    }
    // cazul in care partea imaginara a ambelor numere este negativa
    if (a[(N - 1) / 2] == '1' && b[(N - 1) / 2] == '1')
    {
        ok = 0;
        for (i = (N - 1) / 2 + 1; i < N - 1; i++)
        {
            if (b[i] < a[i])
            {
                ok = 1;
                break;
            }
            else if (b[i] == a[i])
            {
                ok = 0;
            }
            else
                break;
        }
        // cazul in care b are partea imaginara mai mare decat partea
        // imaginara a lui a
        if (ok == 0)
        {
            k = 0;
            for (i = N - 2; i > (N - 1) / 2; i--)
            {
                imzb[i] = imzb[i] - k;
                if (imzb[i] < imza[i])
                {
                    imz[i] = 10 + imzb[i] - imza[i];
                    k = 1;
                }
                else
                {
                    imz[i] = imzb[i] - imza[i];
                    k = 0;
                }
            }
            // intrucat s-a scazut un numar negativ dintr-un numar pozitiv,
            // bitul de semn devine 0
            imz[(N - 1) / 2] = 0;
        }
        // cazul in care a are partea imaginara mai mare decat partea
        // imaginara a lui b
        else
        {
            k = 0;
            for (i = N - 2; i > (N - 1) / 2; i--)
            {
                imza[i] = imza[i] - k;
                if (imza[i] < imzb[i])
                {
                    imz[i] = 10 + imza[i] - imzb[i];
                    k = 1;
                }
                else
                {
                    imz[i] = imza[i] - imzb[i];
                    k = 0;
                }
            }
            // intrucat s-a scazut un numar pozitiv dintr-un numar negativ,
            // bitul de semn devine 1
            imz[(N - 1) / 2] = 1;
        }
    }
    // sirul c este alcatuit din toate elementele celor 2 vectori,
    // transformate in caractere
    for (i = 0; i <= (N - 1) / 2 - 1; i++)
    {
        c[i] = rez[i] + '0';
    }
    for (i = (N - 1) / 2; i < N - 1; i++)
    {
        c[i] = imz[i] + '0';
    }
    c[N - 1] = '\0';
}

// functia de afisare
void afisare(char *a)
{
    printf("%s\n", a);
}

int main()
{
    int N;
    char a[1001], b[1001], c[1001], op, nr = 0;
    scanf("%d", &N);
    getchar();
    fgets(a, N, stdin);
    getchar();
    op = getchar();
    while (op != '0')
    {
        getchar();

        // se executa operatia corespunzatoare semnului
        // se afiseaza rezultatul, care mai apoi este retinut in sirul a
        // pentru a fi utilizat in calculele viitoare
        if (op == '+')
        {
            fgets(b, N, stdin);
            getchar();
            adunare(a, b, c, N);
            afisare(c);
            strcpy(a, c);
        }
        else
        {
            fgets(b, N, stdin);
            getchar();
            scadere(a, b, c, N);
            afisare(c);
            strcpy(a, c);
        }
        nr++;
        op = getchar();
    }
    return 0;
}
