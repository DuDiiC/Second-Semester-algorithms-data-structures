#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <limits>
using namespace std;

int main() {

    int ilosc_testow;
    cin >> ilosc_testow;
    for(int i = 0; i < ilosc_testow; ++i) {

        int n, t, m;
        cin >> n >> t >> m;
        /*
            n - tyle samochodow jednoczesnie moze zabrac prom
            t - tyle czasu prom plynie miedzy brzegami
            m - ilosc przypadkow testowych
        */
        vector<queue<pair<int, int> > > samochody(2);
        vector<int> czasPrzybycia(m);

        for (int j = 0; j < m; ++j) {
            int czasPodrozy;
            string bank;
            cin >> czasPodrozy >> bank;
            if (bank == "left") {
                samochody[0].push(pair<int, int>(j, czasPodrozy));
            } else {
                samochody[1].push(pair<int, int>(j, czasPodrozy));
            }
        }

        int czas = 0;
        int brzeg = 0;
        /*
            0 - lewy brzeg
            1 - prawy brzeg
        */
        while (!(samochody[0].empty() && samochody[1].empty())) {

            int pierwszySamochod = numeric_limits<int>::max();

            if (!samochody[0].empty())
                pierwszySamochod = samochody[0].front().second;

            if (!samochody[1].empty())
                pierwszySamochod = min(pierwszySamochod, samochody[1].front().second);

            czas = max(czas, pierwszySamochod);

            int iloscSamochodow = 0;

            while (!samochody[brzeg].empty() && iloscSamochodow < n && samochody[brzeg].front().second <= czas) {

                czasPrzybycia[samochody[brzeg].front().first] = czas + t;
                samochody[brzeg].pop();
                ++iloscSamochodow;
            }

            czas += t;
            brzeg = (brzeg+1)%2;
        }

        for (int j = 0; j < m; ++j)
            cout << czasPrzybycia[j] << endl;

        if (i != ilosc_testow-1) cout << endl;
    }
    return 0;
}
