#include<iostream>
#include<string>

using namespace std;

int shortestPeriod(string word) {

    int period = 1;
    string comparison;

    while (period <= word.size()) {

        comparison = "";
        while (comparison.size() < word.size()) {

            comparison += word.substr(0, period);
        }

        if (comparison == word) return period;

        period++;
    }
}

int main() {

    string word;
    int cases;

    cin >> cases;
    while (cases--) {

        cin >> word;
        cout << shortestPeriod(word) << endl;
    }

    return 0;
}
