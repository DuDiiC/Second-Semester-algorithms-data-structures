#include <iostream>
#include <vector>

using namespace std;



int main() {

    vector < string > slowa;
    string kolejneSlowo;
    int i, j, k;


    //wczytanie danych
    while(cin >> kolejneSlowo && kolejneSlowo != "#") {
        slowa.push_back(kolejneSlowo);
    }

    //uzupelnianie macierzy powiazaniami miedzy literami
    bool macierz[26][26] = {0};
    bool temp[26] = {0};
    for(i = 0; i < slowa.size()-1; ++i) {
        for(j = 0; j < min(slowa[i].size(), slowa[i+1].size()); ++j) {

            if(slowa[i][j] != slowa[i+1][j]) { //jak na danej pozycji inne litery

                //dla pozycji odpowiadajacym danym literom (osiaga sie je, odejmujac liczbe
                //odpowiadajaca literze 'A', dalej analogicznie)
                macierz[slowa[i][j] - 'A'][slowa[i+1][j] - 'A'] = true;
                temp[slowa[i][j]-'A'] = true;
                temp[slowa[i+1][j]-'A'] = true;
                break;
            }
        }
    }

    //szukam wspolnych "jedynek" w macierzy, tworzac macierz na ktorej bede bazowal
    //w szukaniu kolejnosci
    for(i = 0; i < 26; ++i) {
        for(j = 0; j < 26; ++j) {
            for(k = 0; k < 26; ++k) {

                macierz[j][k] = macierz[j][k] || (macierz[i][k] & macierz[j][i]);
            }
        }
    }

    //posortowanie liter w porzadku od ostatniej do pierwszej
    int ktoraPozycja, iloscLiter = 0;
    char porzadekKoncowy[26];
    for(i = 0; i < 26; ++i) {
        if(temp[i]) {
            ++iloscLiter;
            ktoraPozycja = 0;
            for(j = 0; j < 26; ++j) {
                if(macierz[i][j]) ++ktoraPozycja;
            }
            char litera = 'A' + i;
            porzadekKoncowy[ktoraPozycja] = litera;
        }
    }

    //wypisanie wyniku
    for(i = iloscLiter-1; i >= 0; --i) {
        cout << porzadekKoncowy[i];
    }
    cout << endl;
}
