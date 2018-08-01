#include<iostream>
#include<vector>

using namespace std;

int main() {
    long ilosc_wysokosci, ilosc_testow, liczba, i, test, mniejsza, wieksza;
    vector <long> wysokosci;
    cin>>ilosc_wysokosci;

    while(ilosc_wysokosci--) {
        cin>>liczba;
        wysokosci.push_back(liczba);
    }

    cin>>ilosc_testow;

    while(ilosc_testow--) {
        cin>>test;
        i=0;

        if(wysokosci[0]==test && wysokosci[wysokosci.size()-1]==test) {
            cout<<"X X"<<endl;
        } else {
            if(test<=wysokosci[0]) {
                while(test==wysokosci[i])
                    i++;
                wieksza=wysokosci[i];
                cout<<"X "<<wieksza<<endl;
            } else if(test>=wysokosci[wysokosci.size()-1]) {
                i=wysokosci.size()-1;
                while(test==wysokosci[i])
                    --i;
                mniejsza=wysokosci[i];
                cout<<mniejsza<<" X"<<endl;
            } else {
                while(test>=wysokosci[i] && i<wysokosci.size()) {
                    i++;
                }

                wieksza=wysokosci[i];
                while(wysokosci[i-1]==test) {
                    --i;
                }
                mniejsza=wysokosci[i-1];
                cout<<mniejsza<<" "<<wieksza<<endl;
            }
        }
    }

    return 0;
}
