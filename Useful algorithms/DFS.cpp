/*Lista sasiedztwa jest najbardziej oplacalna struktura, pozwalajaca zastosowac algorytm DFS,
 *daje bowiem dostep do wszyskich sasiadow danego wierzcholka bez wykonywania dodatkowych operacji.
 *Zastosowana metoda DFS jest metoda rekurencyjna, mozna zastosowac rowniez implementacje uzywajaca
 *stosu. Jedyna roznica bedzie kolejnosc wchodzenia do poszczegolnych sasiadow - przy rekurencji zaczynamy
 *od pierwszego sasiada, przy zastosowaniu stosu bylby to ostatni sasiad. Efekt dzialania obu metod jest
 *identyczny, caly graf zawsze zostanie odwiedzony.
 */

#include <iostream>
#include <vector>
using namespace std;

void DFS(vector <int> *lista, bool *odwiedziny, int *ojcowie, int wierzcholek);

int main() {

    int liczbaWierzcholkow, liczbaKrawiedzi;
    int wPoczatkowy, wKoncowy;
    cin >> liczbaWierzcholkow >> liczbaKrawiedzi;
    bool tablicaOdwiedzin[liczbaWierzcholkow];
    int tablicaOjcow[liczbaWierzcholkow];

    for(int i = 0; i < liczbaWierzcholkow; ++i) {   //wszystko analogicznie jak w tablicach dla BFS
        tablicaOdwiedzin[i] = false;                //zmiana na true, gdy odwiedze
        tablicaOjcow[i] = -1;                       //jesli zostanie -1, to bedzie korzen w niezaleznym podgrafie
    }

    vector <int> listaSasiedztwa[liczbaWierzcholkow];
    for(int i = 0; i < liczbaKrawiedzi; ++i) { //wczytywanie krawedzi do listy sasiedztwa grafu nieskierowanego
        cin >> wPoczatkowy >> wKoncowy;
        listaSasiedztwa[wPoczatkowy].push_back(wKoncowy);
        listaSasiedztwa[wKoncowy].push_back(wPoczatkowy);
    }

    cout << "Kolejnosc odwiedzania wierzcholkow: ";
    for(int i = 0; i < liczbaWierzcholkow; ++i) {
        DFS(listaSasiedztwa, tablicaOdwiedzin, tablicaOjcow, i);
    }
    cout << endl;

    cout << "Oto tablica ojcow: ";
    for(int i = 0; i < liczbaWierzcholkow; ++i) {
        cout << tablicaOjcow[i] << " ";
    }
    cout << endl;

    return 0;
}

void DFS(vector <int> *lista, bool *odwiedziny, int *ojcowie, int wierzcholek) {
    cout << wierzcholek << " ";

    int badanySasiadWierzcholka;
    odwiedziny[wierzcholek] = true;

    for(int j = 0; j < lista[wierzcholek].size(); ++j) {

        badanySasiadWierzcholka = lista[wierzcholek][j];
        if(odwiedziny[badanySasiadWierzcholka] == false) {
            ojcowie[badanySasiadWierzcholka] = wierzcholek;
            DFS(lista, odwiedziny, ojcowie, badanySasiadWierzcholka);   //wywolanie rekurencyjne DFS, ktore symuluje
                                                                        //dzialanie stosu, stos jest tutaj niejawny,
                                                                        //nie jest potrzebny jako struktura
        }
    }

}
