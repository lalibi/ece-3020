#include <iostream>
using namespace std;

int main() {
    int n, d;

    cin >> n;
    cin >> d;

    if (n < 100000 || n > 999999) {
        return 1;
    }

    if (d < 0 || d > 9) {
        return 1;
    }

    if (n % 10 == d && n / 100000 == d) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
}
