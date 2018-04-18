/* the program uses the Levenstein algorithm */

#include <iostream>

using namespace std;

int main() {

    int N1, N2, nr_testu = 1;
    cin >> N1 >> N2;

    while(N1 && N2) {

        int N1_tab[N1], N2_tab[N2];
        for(int i = 0; i < N1; ++i) cin >> N1_tab[i];
        for(int i = 0; i < N2; ++i) cin >> N2_tab[i];

        int tab_wynik[N1 + 1][N2 + 1];

        for(int i = 0; i <= N1; ++i) {
            for(int j = 0; j <= N2; ++j) {
                if(i == 0 || j == 0) {

                    tab_wynik[i][j] = 0;

                } else if(N1_tab[i-1] == N2_tab[j-1]) { //

                    tab_wynik[i][j] = tab_wynik[i-1][j-1] + 1;

                } else {

                    tab_wynik[i][j] = max(tab_wynik[i-1][j], tab_wynik[i][j-1]);
                }
            }
        }

        cout << "Twin Towers #" << nr_testu++ << endl;
        cout << "Number of Tiles : " << tab_wynik[N1][N2] << endl;
        cout << endl;

        cin >> N1 >> N2;
    }

    return 0;
}
