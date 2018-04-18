/*
    algorytm zachlanny dzialajacy w kierunku dol-gora, wybierajac na poczatku
    najwieksza wage na ostatnim poziomie
*/

#include <iostream>
#include <vector>
using namespace std;

//funkcje poczatek() oraz koniec() pomagajace sprawdzic, czy znajduje sie "na obrzezach" piramidy
int poczatek(int poziom);

int koniec(int poziom);

//zwraca pozycje z najwieksza waga na ostatnim poziomie
int najwiekszy(vector <int> piramid, int poziom,  int &pozycja);

int main() {

    int n, suma, poziom = 1, pozycja;
    vector < int > piramida;

    //wczytanie danych
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        piramida.push_back(temp);
    }

    //ustalenie poziomu
    for(int i = 1; i < n; i += poziom) ++poziom;

    //wlasciwy program, startuje od dolu
    suma = najwiekszy(piramida, poziom, pozycja);

    while(pozycja > 0) {

        if(pozycja == poczatek(poziom)) { //przypadek z rogu lewego

            pozycja = pozycja-(poziom-1);
            suma += piramida[pozycja];

        } else if(pozycja == koniec(poziom)) { //przypadek z rogu prawego

            pozycja = pozycja-poziom;
            suma += piramida[pozycja];

        } else { //przypadek "ze srodka, trzeba wybierac max"

            if(piramida[pozycja-poziom] > piramida[pozycja-(poziom-1)]) {

                pozycja = pozycja-poziom;
                suma += piramida[pozycja];

            } else {

                pozycja = pozycja-(poziom-1);
                suma += piramida[pozycja];
            }
        }
        --poziom;
    }
    cout << suma << endl;
}

int poczatek(int poziom) {
    int p = 1;
    for(int i = 1; i < poziom; ++i) {
        p += i;
    }
    return p-1;
}

int koniec(int poziom) {
    int k = 1;
    for(int i = 2; i <= poziom; ++i) {
        k += i;
    }
    return k-1;
}

int najwiekszy(vector <int> piramid, int poziom,  int &pozycja) {
    int p = poczatek(poziom);
    int k = koniec(poziom);
    int maximum = piramid[p];
    pozycja = p;
    for(int i = p+1; i < k; ++i) {
        if(maximum < piramid[i]) {
            maximum = piramid[i];
            pozycja = i;
        }
    }
    return maximum;
}
