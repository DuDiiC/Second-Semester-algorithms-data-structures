#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int Knuth_Morris_Pratt(string word) {
    vector <int>  tab(100);
    tab[0] = -1;
    int i = 1, j = -1;
    while(word[i]) {
        while(j >= 0 && word[j+1] != word[i]) {
            j = tab[j];
        }
        if(word[j+1] == word[i]) ++j;
        tab[i] = j;
        ++i;
    }
    return j;
}

int main() {
    int cases;
    cin >> cases;

    while(cases--) {

        string word;
        cin >> word;
        int length = word.size();
        int rep = Knuth_Morris_Pratt(word);

        if(length%(length-rep-1)) cout << length;
        else cout << length-rep-1;

        if(cases) cout << endl;
    }
}
