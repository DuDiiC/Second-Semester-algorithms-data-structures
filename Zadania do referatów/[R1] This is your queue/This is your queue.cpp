#include <iostream>
#include <list>

using namespace std;

int main() {
    int populacja, ilosc_testow, nr_testu = 1;
    cin >> populacja >> ilosc_testow;

    while(populacja && ilosc_testow) {
        cout << "Case " << nr_testu++ << ":" << endl;
        list <int> kolejka;
        char wybor;
        int numer_pacjenta;

        populacja = min(ilosc_testow, populacja);

        for(int i = 1; i <= populacja; ++i) kolejka.push_back(i);

        for(int i = 0; i < ilosc_testow; ++i) {
            cin >> wybor;

            if(wybor == 'N') {

                cout << kolejka.front() << endl;
                kolejka.push_back(kolejka.front());
                kolejka.pop_front();

            } else {

                cin >> numer_pacjenta;
                kolejka.remove(numer_pacjenta);
                kolejka.push_front(numer_pacjenta);

            }
        }
        cin >> populacja >> ilosc_testow;
    }

    return 0;
}
