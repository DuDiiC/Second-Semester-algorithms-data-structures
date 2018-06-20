#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <ctime>
#include <cstdlib>
#define INF 10000000
using namespace std;

struct Wierzcholek {
    int numer;
    int x;
    int y;
};

struct Krawedz {
    Wierzcholek start;
    Wierzcholek koniec;
    double dlugosc;
};

double dlugoscKrawedzi(Wierzcholek temp1, Wierzcholek temp2) {
    return sqrt(pow(temp2.x - temp1.x, 2) + pow(temp2.y - temp1.y, 2));
}

bool rownoscWierzcholkow(Wierzcholek temp1, Wierzcholek temp2) {
    if(temp1.numer == temp2.numer) return 1;
    return 0;
}

double dlugoscCykluCalego(vector<Wierzcholek> cykl) {
    double dlugoscDrogi = 0;
    for(int i = 0; i < cykl.size()-1; ++i) {
        dlugoscDrogi += dlugoscKrawedzi(cykl[i], cykl[i+1]);
    }
    dlugoscDrogi += dlugoscKrawedzi(cykl[cykl.size()-1], cykl[0]);
    return dlugoscDrogi;
}

int main() {

    int iloscDanych;
    cout << "Podaj ilosc wierzcholkow grafu: ";
    cin >> iloscDanych;
    double dlugoscCyklu;

    //operacje i zmienne potrzebne do obliczenia czasu
    double czasTrwania;
    cout.setf(ios::fixed);
    cout.precision(3);
    time_t start, koniec;

    vector <Wierzcholek> wierzcholki;

    //wczytanie danych z pliku
    string sciezka;
    cout << "Podaj nazwe pliku albo pelna sciezke: ";
    cin >> sciezka;
    ifstream danePoczatkowe(sciezka.c_str());
    Wierzcholek tempW;
    for(int i = 0; i < iloscDanych; ++i) {
        danePoczatkowe >> tempW.numer >> tempW.x >> tempW.y;
        wierzcholki.push_back(tempW);
    }
    danePoczatkowe.close();

     //tablica odleglosci
    double ** tablicaDlugosci = new double * [iloscDanych];
    for(int i = 0; i < iloscDanych; ++i) {
        tablicaDlugosci[i] = new double [iloscDanych];
    }
    for(int i = 0; i < iloscDanych; ++i) {
        for(int j = 0; j < iloscDanych; ++j) {
            tablicaDlugosci[i][j] = dlugoscKrawedzi(wierzcholki[i], wierzcholki[j]);
        }
    }

    //otwarcie pliku do zapisu
    int dlugoscSciezki = sciezka.length();
    sciezka = sciezka.erase(dlugoscSciezki - 4, dlugoscSciezki);
    sciezka += ".out.txt";
    ofstream daneKoncowe(sciezka.c_str());

    /* ALGORYTM NAJBLIZSZEGO SASIADA
     * tworzenie pierwszego cyklu:
     * obieramy wierzcholek poczatkowy, nastepnie sprawdzamy drogi do wszystkich pozostalych wierzcholkow, wybieramy te najkrotsza i laczymy krawedzia
     * usuwamy polaczony wierzcholek z poczatkowego zbioru, dodajemy go do naszego cyklu
     * postepujemy tak dla wszystkich wierzcholkow w zbiorze
     */

    start = clock();

    vector <Krawedz> cyklPoczatkowy;
    int minDlugosc;
    int numerMinDlugosci;
    Krawedz tempK;
    tempK.start = wierzcholki[0];
    cyklPoczatkowy.push_back(tempK);
    wierzcholki.erase(wierzcholki.begin());

    while(!wierzcholki.empty()) {
        minDlugosc = INF;
        numerMinDlugosci = -1;

        for(int i = 0; i < wierzcholki.size(); ++i) {
            if(cyklPoczatkowy[cyklPoczatkowy.size()-1].start.numer == wierzcholki[i].numer) continue;

            if(dlugoscKrawedzi(cyklPoczatkowy[cyklPoczatkowy.size()-1].start, wierzcholki[i]) < minDlugosc) {
                numerMinDlugosci = i;
                minDlugosc = dlugoscKrawedzi(cyklPoczatkowy[cyklPoczatkowy.size()-1].start, wierzcholki[i]);
            }
        }

        cyklPoczatkowy[cyklPoczatkowy.size()-1].koniec = wierzcholki[numerMinDlugosci];
        tempK.start = cyklPoczatkowy[cyklPoczatkowy.size()-1].koniec;
        cyklPoczatkowy.push_back(tempK);
        wierzcholki.erase(wierzcholki.begin() + numerMinDlugosci);
    }
    cyklPoczatkowy[cyklPoczatkowy.size()-1].koniec = cyklPoczatkowy[0].start;

    //zamiana wektora krawedzi na wektor wierzcholkow
    vector <Wierzcholek> cykl;
    for(int i = 0; i < cyklPoczatkowy.size(); ++i) {
        cykl.push_back(cyklPoczatkowy[i].start);
    }

    dlugoscCyklu = dlugoscCykluCalego(cykl);

    //cout << "Dlugosc calego cyklu = " << dlugoscCyklu <<endl;

    /* ALGORYTM 2-OPT
     * algorytm poprawiania juz uzyskanego cyklu
     * zamieniaj dwie krawedzie i sprawdzaj czy koszt sie poprawi
     * wykonanie dla wszystkich mozliwych par krawedzi, poza tymi ktore juz sa
     */

    bool czyPoprawa = false;
    int i1, i2, j1, j2;

    for(int i = 0; i < cykl.size()-3; ++i) { //dla kazdego wierzcholka w cyklu
        for(int j = i+2; j < cykl.size()-1; ++j) { //wszystkie inne wierzcholki poza sasiednimi
            i1 = cykl[i].numer-1;
            i2 = cykl[i+1].numer-1;
            j1 = cykl[j].numer-1;
            j2 = cykl[j+1].numer-1;
            if(tablicaDlugosci[i1][i2] + tablicaDlugosci[j1][j2] > tablicaDlugosci[i1][j1] + tablicaDlugosci[i2][j2]) {

                reverse(cykl.begin()+i+1, cykl.begin()+j+1);

                if(dlugoscCyklu == dlugoscCykluCalego(cykl)) continue;
                dlugoscCyklu = dlugoscCykluCalego(cykl);
                cout << "Poprawiam, nowa dlugosc cyklu: " << dlugoscCyklu << endl;
                czyPoprawa = true;
            }
        }
        if(czyPoprawa && i == cykl.size()-4) {
            czyPoprawa = false;
            i = 0;
        }
    }

    koniec = clock();;
    cout << "Czas trwania programu: " << (koniec-start)/(double)CLOCKS_PER_SEC<< "s" << endl;

    for(int i = 0; i < iloscDanych; ++i) {
        delete[] tablicaDlugosci[i];
    }
    delete[] tablicaDlugosci;

    daneKoncowe << "Uzyskany cykl ma postac: " << endl;
    for(int i = 0; i < cykl.size()-1; ++i) {
        daneKoncowe << cykl[i].numer << "(" << cykl[i].x << ", " << cykl[i].y << ") -> " << cykl[i+1].numer << "(" << cykl[i+1].x << ", " << cykl[i+1].y << ")" << endl;
    }
    daneKoncowe << "Po zastosowaniu poprawek dlugosc cyklu to: " << dlugoscCyklu << endl;

    //sprawdzanie rozbieznosci z optymalnym wynikiem
    cout << "Czy znasz dlugosc optymalnej drogi? (T/N): ";
    char porownanie;
    cin >> porownanie;
    if(porownanie == 'T') {
        double optymalnaDlugosc;
        cout << "Podaj optymalna dlugosc: ";
        cin >> optymalnaDlugosc;

        double oIleGorsza = (dlugoscCyklu*100/optymalnaDlugosc) - 100.;

        cout << "Uzuskana dlugosc jest o " << oIleGorsza << "% gorsza od optymalnej" << endl;
    }

    daneKoncowe.close();

    return 0;
}
