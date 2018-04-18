#include <iostream>
using namespace std;

int index;

void findPostOrder(int left, int right, string pree, string inn); //recurcive function

int main() {

    int cases;
    cin >> cases;

    for(int i = 0; i < cases; ++i) {

        int length;
        index = 0;
        string pre, in;

        cin >> length >> pre >> in;

        findPostOrder(0, length-1, pre, in);

        cout << endl;
    }

    return 0;
}

void findPostOrder(int left, int right, string pree, string inn) {

    if(left <= right) {
        int j;
        for(j = left; j <= right; j++) {
            if(inn[j] == pree[index]) break;
        }

        if(j != right+1) {
            ++index;
            findPostOrder(left, j-1, pree, inn);
            findPostOrder(j+1, right, pree, inn);
            cout << inn[j];
        }
    } else return; //bottom of recursion

}
