#include <iostream>
#include <cstdlib>
using namespace std;

struct Zespol {
    int pozycjaRankingowa;
    string nazwaZespolu;
    int punkty = 0, rozegraneMecze = 0,
        zwyciestwa = 0, remisy = 0, przegrane = 0,
        zdobyteBramki = 0, straconeBramki = 0, roznicaBramek = 0;
};

bool alfabetycznie(string pierwszy, string drugi) {
//funkcja zwraca prawde, jesli alfabetycznie pierwszy jest pierwszy wyraz
    string pierwszy1;
    string drugi1;
    for(int i = 0; i < pierwszy.length(); ++i) {
        pierwszy1 += tolower(pierwszy[i]);
    }
    for(int i = 0; i < drugi.length(); ++i) {
        drugi1 += tolower(drugi[i]);
    }
    if(pierwszy1 < drugi1) return true;
    else return false;
}

void sortowanie(Zespol druzyna[], int ilosc) {
    bool czyWatpliwosci = false;
    for(int i = 0; i < ilosc-1; ++i) {
        int temp = i;
        for(int j = i+1; j <=ilosc-1; ++j) {
            if(druzyna[j].punkty > druzyna[temp].punkty) temp = j;
            else if(druzyna[j].punkty == druzyna[temp].punkty && temp != j) {
                if(druzyna[j].zwyciestwa > druzyna[temp].zwyciestwa) temp = j;
                else if(druzyna[j].zwyciestwa == druzyna[temp].zwyciestwa) {
                    if(druzyna[j].roznicaBramek > druzyna[temp].roznicaBramek) temp = j;
                    else if(druzyna[j].roznicaBramek == druzyna[temp].roznicaBramek) {
                        if(druzyna[j].zdobyteBramki > druzyna[temp].zdobyteBramki) temp = j;
                        else if(druzyna[j].zdobyteBramki == druzyna[temp].zdobyteBramki) {
                            if(druzyna[j].rozegraneMecze < druzyna[temp].rozegraneMecze) temp = j;
                            else if(druzyna[j].rozegraneMecze == druzyna[temp].rozegraneMecze) {
                                if(alfabetycznie(druzyna[j].nazwaZespolu, druzyna[temp].nazwaZespolu)) temp = j;
                            }
                        }
                    }
                }
            }
        }
        swap(druzyna[i], druzyna[temp]);
    }
}

int main() {
    int N, iloscDruzyn, iloscMeczy;
    string nazwaTurnieju;
    cin >> N;
    cin.sync();
    for(int i = 0; i < N; ++i) {
        getline(cin, nazwaTurnieju);

        cin >> iloscDruzyn;
        cin.sync();
        Zespol zespol[iloscDruzyn];

        for(int j = 0; j < iloscDruzyn; ++j)
            getline(cin, zespol[j].nazwaZespolu);

        cin >> iloscMeczy;
        cin.sync();

        for(int j = 0; j < iloscMeczy; ++j) {
            string nazwa1, gol1, gol2, nazwa2;
            int pierwszy = 0, drugi = 0;

            getline(cin, nazwa1, '#');
            for(int k = 0; k < iloscDruzyn; ++k) {
                if(nazwa1 == zespol[k].nazwaZespolu) {
                    zespol[k].nazwaZespolu = nazwa1;
                    pierwszy = k;
                    break;
                }
            }

            getline(cin, gol1, '@');
            int gool1 = atoi(gol1.c_str());

            getline(cin, gol2, '#');
            int gool2 = atoi(gol2.c_str());

            getline(cin, nazwa2);
            for(int k = 0; k < iloscDruzyn; ++k) {
                if(nazwa2 == zespol[k].nazwaZespolu) {
                    zespol[k].nazwaZespolu = nazwa2;
                    drugi = k;
                    break;
                }
            }
            int nrZwyciezcy, nrPrzegranego;
            if(gool1 != gool2) {//gdy ktorys wygral
                if(gool1 > gool2) {
                    nrZwyciezcy = pierwszy;
                    nrPrzegranego = drugi;

                    zespol[nrZwyciezcy].zdobyteBramki += gool1;
                    zespol[nrZwyciezcy].straconeBramki += gool2;
                    zespol[nrPrzegranego].zdobyteBramki += gool2;
                    zespol[nrPrzegranego].straconeBramki += gool1;
                } else {
                    nrZwyciezcy = drugi;
                    nrPrzegranego = pierwszy;

                    zespol[nrZwyciezcy].zdobyteBramki += gool2;
                    zespol[nrZwyciezcy].straconeBramki += gool1;
                    zespol[nrPrzegranego].zdobyteBramki += gool1;
                    zespol[nrPrzegranego].straconeBramki += gool2;
                }

                zespol[nrZwyciezcy].punkty += 3;
                zespol[nrZwyciezcy].zwyciestwa++;
                zespol[nrPrzegranego].przegrane++;
            } else { //gdy byl remis
                zespol[pierwszy].zdobyteBramki += gool1;
                zespol[pierwszy].straconeBramki += gool1;
                zespol[drugi].zdobyteBramki += gool1;
                zespol[drugi].straconeBramki += gool1;

                zespol[pierwszy].punkty += 1;
                zespol[drugi].punkty += 1;
                zespol[pierwszy].remisy += 1;
                zespol[drugi].remisy += 1;
            }
            zespol[pierwszy].rozegraneMecze++;
            zespol[drugi].rozegraneMecze++;
        }

        for(int j = 0; j < iloscDruzyn; ++j) {
            zespol[j].roznicaBramek = zespol[j].zdobyteBramki - zespol[j].straconeBramki;
        }

        //sortowanie
        sortowanie(zespol, iloscDruzyn);

        for(int j = 0; j < iloscDruzyn; ++j) {
            zespol[j].pozycjaRankingowa = j+1;
        }

        cout << nazwaTurnieju << endl;
        for(int j = 0; j < iloscDruzyn; ++j) {
            cout << zespol[j].pozycjaRankingowa << ") " << zespol[j].nazwaZespolu
                 << " " << zespol[j].punkty << "p, " << zespol[j].rozegraneMecze
                 << "g (" << zespol[j].zwyciestwa << "-" << zespol[j].remisy << "-"
                 << zespol[j].przegrane << "), " << zespol[j].zdobyteBramki-zespol[j].straconeBramki
                 << "gd (" << zespol[j].zdobyteBramki << "-" << zespol[j].straconeBramki << ")" << endl;
        }
        if(i != N-1) cout << endl;
    }

    return 0;
}
