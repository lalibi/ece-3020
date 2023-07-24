#include <iostream>
using namespace std;

int main() {
    int x;

    cin >> x;

    if ((x * x) % 100 == 24) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
}
