PROBLEMA 1- PROBLEMA CUTIILOR

    Rezolvarea primei probleme mi-a luat cateva ore.
    Am utilizat pentru implementarea acesteia trei functii:
        1. prizonierulcastiga() - functia principala a programului,
        care verifica daca prizonierul x reuseste sa gaseasca cutia cu
        numarul sau corespunzator. Functia creeaza si o lista cu toate
        cutiile deschise de prizonier, pana la intalnirea celei cu numarul
        corespunzator.
            Prin intermediul unei structuri repetitive cu test initial
        se trece dintr-o cutie in alta, verificandu-se mereu daca valoarea
        din cutia respectiva este egala cu numarul prizonierului.
            In cazul in care acest lucru este fals, numarul cutiei urmatoare,
        care trebuie verificata, devine cel din interiorul cutiei actuale.
            Numarul fiecarei cutii deschise este adaugat in vectorul lista[].
            Am folosit vectorul cicluri pentru a diferentia elementele care
        pot fi inceputul unui ciclu de celelalte, astfel incat ciclurile sa
        nu se repete si sa fie adaugate in matrice in ordine crescatoare.
        Numerele ce reprezinta inceputul unui ciclu primesc valoarea 0, in
        timp ce restu;, cele care doar fac parte din cicluri, primesc
        valoarea 1.
            Variabila nrcd este folosita drept contor pentru numarul de cutii
        deschise, pana la gasirea celei cautate.
            Verificarea se realizeaza la final, prin intermediul variabilei ok,
        care este initializata cu 0 si care devine devine 1 daca numarul de 
        cutii deschise pana la gasirea numarului prizonierului este mai mic
        decat jumatatea numarului total de prizonieri.

        2. functia adaugaciclu() - aceasta functie adauga ciclul gasit in functia
        precedenta pe o noua linie a matricei, in care sunt retinute toate ciclurile
        determinate de cutii

        3. functia afisarecicluri() - afiseaza toate ciclurile formate de cutii din
        matrice

        In main, functia prizonierulcastiga() este apelata pentru fiecare prizonier.
    Daca in urma apelului functiei, ok a primit valoarea 0, inseamna ca unul
    dintre prizonieri nu a reusit sa-si gaseasca numarul, motiv pentru care
    variabila eliberare ia valoarea 0 si arata faptul ca niciun prizonier nu
    va fi eliberat.
        Se verifica, de asemenea, daca numarul cu care a inceput ciclul, adica
    numarul prizonierului si al primei cutii deschise, nu face parte din alt
    ciclu. In acest caz, ciclul salvat in vectorul lista[] poate fi adaugat
    in matrice, pentru a putea fi afisat ulterior.
        La final, se afiseaza toate ciclurile din matrice.

PROBLEMA 2- NUMERE COMPLEXE LUNGI

    Rezolvarea celei de-a doua probleme mi-a luat o zi. 
    Am utilizat pentru implementarea acesteia trei functii:
        1. adunare() - functie folosita pentru adunarea a doua
        numere complexe, lungi.
            Pentru inceput, caracterele fiecarui sir sunt transformate
        in cifrele corespunzatoare si retinute in cate 2 vectori pentru fiecare
        dintre cele 2 siruri. Astfel, reza[] retine cifrele corespunzatoare
        partii reale ale numarului determinat de a, inclusiv bitul de semn,
        iar imza[] pe cele care apartin partii imaginare. Analog pentru rezb[]
        si imzb[]. Am plasat elementele partii imaginare intre pozitiile 
        (n-2)/2-1 si n-1, pentru a facilita referirea la ele, in restul
        programului.
            Am luat separat mai multe cazuri ale adunarii si am folosit acelasi
        procedeu pentru a calcula atat partea reala, cat si partea imaginara.
        Singura diferenta o reprezinta contorul, care porneste fie de la 
        (N-1)/2 sau de la N-2 in cazul partii imaginare. Din acest motiv, in
        continuare ma voi referi doar la partea reala a numerelor.
            Cazuri:
                1. numerele au acelasi semn, sunt fie pozitive, fie negative
                    - In acest caz, adunarea incepe de la cifrele de pe 
                    ultimele pozitii, iar in cazul in care suma depaseste 
                    numarul 10, se pastreaza doar restul sumei la impartirea
                    cu 10, iar ok devine 1, urmand sa fie adaugat la adunarea
                    urmatoarelor 2 cifre. Ok este o variabila initializata cu 
                    0, care are rolul de a arata daca suma trebuie crescuta cu 
                    1, in cazul in care suma cifrelor devine mai mare decat 9,
                    sau nu.
                    - Daca ambele numere sunt pozitive, atunci bitul de semn al
                    rezultatului ia valoarea 0, iar daca numerele sunt negative
                    ia valoarea 1
                2. numerele au semne diferite, caz in care operatia este de
                fapt o scadere
                    - Se stabileste mai intai care dintre numere este mai mare,
                    pentru ca mai apoi sa se efectueze scaderea
                    -In cazul in care cifra din care se scade este mai mica
                    decat cea care se scade, se adauga 10 la prima cifra,
                    urmand sa se scada 1 din cifra urmatoare.
                    -In cazul in care numarul pozitiv se scade din cel negativ,
                    rezultatul va avea ca bit de semn 1, fiind negativ.
                    -In cazul in care numarul negativ se scade din cel pozitiv,
                    rezultatul va avea ca bit de semn 0, fiind pozitiv.
            Rezultatele se vor retine in 2 vectori, rez[] si imz[], din care
         se va alcatui mai apoi vectorul c, care va contine toate cifrele
        rezultatelor, in caractere.

        2. scadere() - functie, in esenta, similara cu adunarea
            Spre deosebire de adunare, la scadere se aduna numerele in cazul in
        care acestea au semne diferite si se scad, daca au acelasi semn.

        3. afisare() - afiseaza rezultatul
        
        In main, se verifica tipul operatiei primite, iar in cazul in care se
    citeste simbolul +, se apeleaza functia adunare(), iar in cazul in care
    se citeste simbolul -, se apeleaza functia scadere().
        Dupa fiecare operatie, se afiseaza rezultatul obtinut, care mai apoi
    este copiat in a, pentru a putea fi folosit la calculele urmatoare.

PROBLEMA 3- TRANSMISIE BRUIATA

    Rezolvarea celei de-a treia probleme mi-a in jur de doua zile.
    Am utilizat pentru implementarea acesteia patru functii:
        1. CodificareA()
            Am calculat lungimea cheii, pentru a afla numarul de coloane
        necesare pentru matrice si apoi, numarul necesar de linii, luand
        in considerare si terminatorul sirului.
            Am creat apoi matricea, si am completat-o cu caracterele sirului.
        In cazul in care aceasta nu era completa, am transformat elementele
        ramase in spatii.
            Am folosit apoi 2 vectori, pe care i-am sortat cu ajutorul
        algoritmului selection sort. Primul vector, v, este folosit pentru
        sortarea cheii, iar cel de-al doilea vector, v2, retine numarul
        coloanei corespunzatoare unui anumit caracter din cheie.
            Respectand ordinea impusa de sortare, am adaugat in sirul t
        caracterele, litere sau spatii, apoi am copiat sirul in s.

        2. DecodificareA() - functie, in esenta, similara cu adunarea
            Am calculat lungimea cheii, pentru a afla numarul de coloane
        necesare pentru matrice si apoi, numarul necesar de linii, luand
        in considerare si terminatorul sirului.
            Am folosit 2 vectori, pe care i-am sortat cu ajutorul
        algoritmului selection sort. Primul vector, v, este folosit pentru
        sortarea cheii, iar cel de-al doilea vector, v2, retine numarul
        coloanei corespunzatoare unui anumit caracter din cheie.
            Cu cheia acum sortata, am adaugat elementele sirului in matrice,
        adaugandu-le pe coloana, avand grija sa completez toate elementele
        libere cu spatii.
            Am restabilit in vectorul v3, ordinea in care coloanele din matrice
        trebuie selectate, in functie de cheia initiala, cea nesortata.
        Folosindu-ma de aceasta ordine, am adaugat in sirul t
        caracterele, litere sau spatii, apoi am copiat sirul in s.

        3. CodificareB()
            Se retin caracterele care trebuie modificate intr-un alt sir p,
        iar cele care raman intacte se pastreaza intr-un alt sir t.
            Se modifica fiecare caracter din p, adunandu-se valoarea primita
        in i, la acestea. 
            Avem 2 cazuri:
                1. caracterul este o litera mica
                    In cazul in care adaugandu-i-se i, caracterul nu va mai fi
                litera, se face trecerea la litere mari si valoarea primita i
                i se adauga lui 'A', scazandu-se totodata diferenta dintre
                caracterul initial si ultima litera mica, 'z'.
                1. caracterul este o litera mare
                    In cazul in care adaugandu-i-se i, caracterul nu va mai fi
                litera, se face trecerea la litere mici si valoarea primita i
                i se adauga lui 'a', scazandu-se totodata diferenta dintre
                caracterul initial si ultima litera mare, 'Z'.
            La sirul p modificat se lipeste sirul t, iar p se copiaza in s.

        4. DecodificareB()
            Se retin caracterele care nu trebuie modificate intr-un alt sir p,
        iar primele i caractere care trebuie decodificate se pastreaza
        intr-un alt sir t.
            Se modifica fiecare caracter din t, scazandu-se din ele valoarea
            primita in i.
            Avem 2 cazuri:
                1. caracterul este o litera mica
                    In cazul in care scazandu-se i, caracterul nu va mai fi
                litera, se face trecerea la litere mari si valoarea primita i
                i se scade din 'Z', adunandu-se totodata diferenta dintre
                caracterul initial si prima litera mica, 'a'.
                1. caracterul este o litera mare
                    In cazul in care scazandu-se i, caracterul nu va mai fi
                litera, se face trecerea la litere mici si valoarea primita i
                i se scade din 'z', adunandu-se totodata diferenta dintre
                caracterul initial si prima litera mare, 'A'.
            La sirul p se lipeste sirul t modificat, iar p se copiaza in s.
        
        In main, se citesc operatii pana la intalnirea lui "STOP". Daca
    operatiile se termina in A, se poate observa ca este vorba fie de
    CodificareaA, fie de DecodificareaA, asa ca se verifica si primul caracter
    si se apeleaza functia corespunzatoare. Analog, pentru operatiile care se
    termina in B.
        Dupa fiecare operatie, se afiseaza rezultatul obtinut.

PROBLEMA 4 - CAR DEALER

    Rezolvarea celei de-a patra probleme mi-a luat cateva ore.
    Pentru a retine datele fiecarei masini, am folosit o structura alocata
    dinamic.
    Am utilizat pentru implementarea problemei trei functii, cate una pentru
    fiecare cerinta:
        1. statistica_combustibil() - functie folosita pentru rezolvarea primei
        cerinte.
            Pentru fiecare masina, se verifica ce tip de combustibil are si
        se incrementeaza valoarea corespunzatoare, care mai tarziu va fi
        transmisa in main pentru a se putea determina numarul de masini de
        fiecare tip, dupa combustibil.

        2. consum_total_de_combustibil() - functie folosita pentru rezolvarea
        celei de-a doua cerinte.
            Pentru fiecare masina se calculeaza in vectorii consum[] si suma[],
        consumul total de combustibil si suma totala platita, in functie de
        tipul de combustibil folosit de masina.
            Prin intermediul structurilor repetitive, calculam suma si consumul
        total pentru fiecare marca de masina. Am folosit un vector numit unic[]
        pentru a retine masinile care au fost deja luate in calcul, pentru a
        nu repeta marcile.
            Astfel, se cauta masinile x cu unic[x] == 0 si apoi toate masinile
        care au aceeasi marca. Se aduna atat consumul tuturor masinilor gasite,
        cat si suma platita de acestea. Rezultatele obtinute sunt retinute
        in vectori transimsi ca parametri, de care m-am folosit in main pentru
        a afisa consumul si suma totala.

        3. numere_de_inmatriculare() - functie folosita pentru rezolvarea
        celei de-a treia cerinte.
            Se verifica fiecare numar de inmatriculare, iar daca unul dintre
        ele nu este corect, variabila ok devine 1. In cazul in care aceasta
        ramane 0, inseamna ca toate numerele de inmatriculare sunt corecte.
            Pentru fiecare numar, am calculat cate litere are la inceput, cate
        cifre contine si cate litere are la final. Daca acestea respecta
        cerinta, numarul este corect, daca nu, acest lucru este semnalat de
        variabila bun.

        In main, se citesc datele pentru fiecare masina si se aloca dinamic
    memorie pentru acestea. Apoi se citeste litera cerintei si se apeleaza
    functia corespunzatoare. Pentru fiecare cerinta se afiseaza rezultatele
    obtinute.
