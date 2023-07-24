#include <iostream>
using namespace std;

int main() {
    int x;

    cin >> x;

    // 1st way
    /* if (x / 100 != 0 && x / 1000 == 0) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    } */

    // 2nd way
    /* int i = 0;
    while (x != 0) {
        x = x / 10;
        i++;
    }

    if (i == 3) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    } */

    // 3rd way - simpler
    if (x >= 100 && x <= 999) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}
