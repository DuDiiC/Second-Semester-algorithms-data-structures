#include <iostream>
using namespace std;

int totalValue;
bool yesOrNo;
char character;

bool searchTree(int value) { //recursive tree search

    bool leftLeaf = false, rightLeaf = false; //is exist?
    int valueInThisCase = 0, sign = 1;

    while(cin >> character) { //loading char by char

        if(character == ' ' || character == '\n') //white sign
            continue;

        else if(character == ')') // end of this leaf
            return false;

        else if(character == '(') // new leaf
            break;

        else if(character == '-') //negative number
            sign = -1;

        else if(isdigit(character)) { //loading number digit by digit
            valueInThisCase *= 10;
            valueInThisCase += (character - 48);
        }

    }

    valueInThisCase *= sign; //positive or negative
    value += valueInThisCase;

    leftLeaf = searchTree(value); //recursive for left subtree

    while (cin >> character && character!='('); //bypassing white signs

    rightLeaf = searchTree(value);

    if (!leftLeaf && !rightLeaf && value==totalValue)
        yesOrNo = true;

    while (cin >> character && character != ')');

    return true;
}

int main() {
    char character;

    while (cin >> totalValue) {

        yesOrNo = false;
        while (cin >> character && character != '('); //bypassing white signs

        searchTree(0);

        //printing the results
        if(yesOrNo)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    return 0;
}
