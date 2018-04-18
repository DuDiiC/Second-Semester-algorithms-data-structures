#include <iostream>
using namespace std;

void findPostOrder(int left, int right);

int main() {

    int cases;
    cin >> cases;

    for(int i = 0; i < cases; ++i) {

        int length, index = 0;
        string pre, in;
        cin >> length >> pre >> in;

        findPostOrder(0, length-1);
        cout << endl;
    }

    return 0;
}

void findPostOrder(int left, int right) {

}
