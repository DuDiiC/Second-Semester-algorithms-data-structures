#include<iostream>
#include<vector>
#include<string>

using namespace std;

int strachy(string pole) {
    int ilosc = 0;
    int dlugosc =pole.size()-1;
    for(int j = 0; j <= dlugosc; ++j) {
        if(pole[j] == '.') {
            ilosc++;
            pole[j] = '#';
            if(j+1 <= dlugosc)
                pole[j+1] = '#';
            if(j+2 <= dlugosc)
                pole[j+2] = '#';
        }
    }

    return ilosc;
}

int main()
{
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        int dlugosc, iloscSt;
        cin >> dlugosc;
        string pole;
        cin >> pole;
        iloscSt = strachy(pole);
        cout << "Case " << i << ": "<< iloscSt << endl;
    }

    return 0;
}
