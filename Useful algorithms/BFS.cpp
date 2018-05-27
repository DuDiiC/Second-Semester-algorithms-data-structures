/*Lista sasiedztwa jest najbardziej oplacalna struktura, pozwalajaca zastosowac algorytm BFS,
 *daje bowiem dostep do wszyskich sasiadow danego wierzcholka bez wykonywania dodatkowych operacji.
 *Struktura uzywana do algorytmu BFS to kolejka, tutaj nie mozna zastosowac implementacji z funkcja
 *rekurencyjna. Po przejsciu grafu za pomoca BFS, otrzymujemy drzewo rozpinajace, a szczegolnej wlasnosci.
 *Jest to drzewo, w ktorym wierzcholek poczatkowy jest polaczony z pozostalymi wierzcholkami grafu za pomoca
 *najkrotszej sciezki. Z tego powodu algorytm BFS jest czesto uzywany do znajdowania najkrotszych sciezek
 *miedzy wierzcholkami w grafie.
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector <int> *lista, bool *odwiedziny, int *ojcowie, int wierzcholek) {

    int badanyWierzcholek, sasiadWierzcholka;
    queue <int> kolejka;
    kolejka.push(wierzcholek); //wstawiamy przetwarzany wierzcholek na KOLEJKE
    odwiedziny[wierzcholek] = true; //odwiedzilismy wierzcholek wrzucajac go do kolejki

    while(kolejka.size() != 0) {    //poki kolejka nie jest pusta przeszukujemy wierzcholki polaczone
                                    //z aktualnym
        badanyWierzcholek = kolejka.front();
        kolejka.pop();

        cout << "jestem w wierzcholku: " << badanyWierzcholek << endl;
        cout << "przeszukuje wierzcholki: ";

        for(int j = 0; j < lista[badanyWierzcholek].size(); j++) { //petla dla wszyskich sasiadow wierzcholka

            sasiadWierzcholka = lista[badanyWierzcholek][j];
            if(odwiedziny[sasiadWierzcholka] == false) {
                cout << sasiadWierzcholka << " ";
                kolejka.push(sasiadWierzcholka);
                odwiedziny[sasiadWierzcholka] = true; //zaznaczamy jako odwiedzony
                ojcowie[sasiadWierzcholka] = badanyWierzcholek;
            }
        }
        cout << endl;
    }
}

int main() {

    int liczbaWierzcholkow, liczbaKrawedzi;
    int wPoczatkowy, wKoncowy;
    cin >> liczbaWierzcholkow >> liczbaKrawedzi;
    bool tablicaOdwiedzin[liczbaWierzcholkow];
    int tablicaOjcow[liczbaWierzcholkow];

    for(int i = 0; i < liczbaWierzcholkow; ++i) {
        tablicaOdwiedzin[i] = false; //czy wierzcholek i byl juz odwiedzony
        tablicaOjcow[i] = -1;   //na koniec -1 bedzie w tablicy jesli bedzie korzeniem
                                //dla danego spojnego fragmentu, ich ilosc oznacza ilosc
                                //skladowych spojnosci
    }

    vector <int> listaSasiedztwa[liczbaWierzcholkow];
    for(int i = 0; i < liczbaKrawedzi; ++i) { //wczytywanie danych do listy dla grafu nieskierowanego
        cin >> wPoczatkowy >> wKoncowy;
        listaSasiedztwa[wPoczatkowy].push_back(wKoncowy);
        listaSasiedztwa[wKoncowy].push_back(wPoczatkowy);
    }
    for(int i = 0; i < liczbaWierzcholkow; ++i) { //wywolanie bfs
        if(tablicaOdwiedzin[i] == false) {  //to gwarantuje, ze jesli graf nie byl spojny, to
                                            //przejscie odbedzie sie przez caly graf
            BFS(listaSasiedztwa, tablicaOdwiedzin, tablicaOjcow, i);
        }
    }

    cout << "Oto tablica ojcow: " << endl;
    for(int i = 0; i < liczbaWierzcholkow; ++i) {
        cout << tablicaOjcow[i] << " ";
    }
    cout << endl;

    return 0;
}
