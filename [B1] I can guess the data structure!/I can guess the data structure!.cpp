#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
    int N;
    while(cin >> N) {

        stack <int> stos;
        queue <int> kolejka;
        priority_queue <int> kolejka_priorytetowa;

        bool stosik = true, kolejeczka = true, priorytka = true;

        for(int i = 0; i < N; ++i) {
            int polecenie, liczba;
            cin >> polecenie >> liczba;
            if(polecenie == 1) {

                stos.push(liczba);
                kolejka.push(liczba);
                kolejka_priorytetowa.push(liczba);

            } else if(polecenie == 2) {

                if(liczba != stos.top()) stosik = false;
                stos.pop();

                if(liczba != kolejka.front()) kolejeczka = false;
                kolejka.pop();

                if(liczba != kolejka_priorytetowa.top()) priorytka = false;
                kolejka_priorytetowa.pop();
            }
        }
        if(stosik && !kolejeczka && !priorytka) cout << "stack" << endl;
        else if(!stosik && kolejeczka && !priorytka) cout << "queue" << endl;
        else if(!stosik && !kolejeczka && priorytka) cout << "priority queue" << endl;
        else if(!stosik && !kolejeczka && !priorytka) cout << "impossible" << endl;
        else cout << "not sure" << endl;
    }

}
