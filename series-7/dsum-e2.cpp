#include <iostream>
using namespace std;

int main() {
    int x;

    cin >> x;

    if (x < 1 || x > 10000000) {
        return 1;
    }

    // int c = 0;
    int sum = 0;
    while (x != 0) {
        sum = sum + x % 10;
        // c += 1;
        x = x / 10;
    }

    cout << sum << endl;

    return 0;
}
