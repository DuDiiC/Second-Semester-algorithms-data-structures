/*
    algorytm dynamiczny - poczynajac od przedostatniego rzedu, dla kazdego elementu dodaje
    element z poziomu nizej o wiekszej wadze, operacje powtarzam az dojde do samej gory
*/

#include <iostream>

using namespace std;

int main() {
    int n, poziom = 0, k, i, j;

    cin >> n;

    //ustalenie poziomu
    for(int i = 1; i < n; i += poziom) ++poziom;

    int piramida[poziom][poziom];

    for(i = 0; i < poziom; ++i) {
        for(j = 0; j <= i ; ++j) {
            cin >> piramida[i][j];
        }
    }

    for(i = poziom - 2; i >= 0; --i) {
        for(j = 0; j <= i; ++j) {
            piramida[i][j] += max(piramida[i+1][j+1], piramida[i+1][j]);
        }
    }

    cout << piramida[0][0] << endl;
}
