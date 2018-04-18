/*
    algorytm zachlanny dzialajacy w kierunku gora-dol
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, i, suma, poziom = 1, pozycja = 0;
    vector <int> piramida;

    cin >> n;
    for(int i = 0; i < n; ++i) {

        int temp;
        cin >> temp;
        piramida.push_back(temp);
    }

    suma = piramida[0];

    for(int i = 1; i < n; i += poziom) {

        if(piramida[pozycja + poziom] > piramida[pozycja + poziom + 1]) {

            suma += piramida[pozycja + poziom];
            pozycja += poziom;

        } else {

            suma += piramida[pozycja + poziom + 1];
            pozycja += poziom+1;
        }
        ++poziom;
    }

    cout << suma << endl;
}
