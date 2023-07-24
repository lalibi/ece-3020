#include <iostream>
using namespace std;

int main() {
    int x;

    cin >> x;

    if (x % 7 == 0 && x % 6 != 0) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
}
