#include <iostream>
using namespace std;

int babelkowe(int tab[], int n) {
    int licznik = 0;
    for(int i = 0; i < n-1; ++i) {
        for(int j = n-1; j >= i+1; --j) {
            if(tab[j-1] > tab[j]) {
                swap(tab[j-1], tab[j]);
                ++licznik;
            }
        }
    }

    return licznik;
}

int main() {
    int N;
    while(cin >> N) {
        int tab[N];
        for(int i = 0; i < N; ++i) {
            cin >> tab[i];
        }

        cout << "Minimum exchange operations : " << babelkowe(tab, N) << endl;
    }
    return 0;
}
