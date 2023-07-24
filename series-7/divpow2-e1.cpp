#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int x;

    cin >> x;

    if (x < 1 || x > 10000000) {
        return 1;
    }

    int p = 0;
    int max = -1;
    while (true) {
        int y = pow(2, p);

        if (y > x) {
            break;
        }

        if (x % y == 0) {
            if (p > max) {
                max = p;
            }
        }

        p += 1;
    }

    cout << max << endl;

    /* int p = floor(log2(x));

    while (true) {
        int y = (int) (pow(2, p));

        if (x % y == 0) {
            cout << p << endl;
            break;
        }

        p -= 1;
    } */

    return 0;
}
