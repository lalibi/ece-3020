#include <iostream>

using namespace std;

int main() {
    // Declarations
    int i, j, s;
    char ch;
    float x, y;

    int a[10] = {0};                             // All elements are 0
    int b[] = {1, 2, 3};                         // Initialize with 1, 2, 3

    int *c = new int[10];                        // Allocate 10 elements
    delete[] c;                                  // Free memory

    int *d = (int *) malloc(10 * sizeof(int));   // Allocate 10 elements
    free(d);                                     // Free memory

    // Input
    cin >> i >> j;
    cin >> x >> y;
    cin >> ch;

    // Output
    cout << x << " " << y << endl;

    // Conditionals
    if (x > 10) {
        cout << "Greater than 10" << endl;
    }

    if (x > 10) {
        cout << "Greater than 10" << endl;
    } else {
        cout << "Less than 10" << endl;
    }

    if (x > 10) {
        cout << "Greater than 10" << endl;
    } else if (x > 5) {
        cout << "Greater than 5" << endl;
    } else {
        cout << "Less than 5" << endl;
    }

    if (ch == 'A') {
        cout << "A" << endl;
    } else if (ch == 'B') {
        cout << "B" << endl;
    } else {
        cout << "Other" << endl;
    }

    switch (ch) {
    case 'a':
    case 'A':
        cout << 'a' << endl;
        break;
    case 'b':
    case 'B':
        cout << 'b' << endl;
        break;
    default:
        cout << "Other" << endl;
    }

    switch (i) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 9:
        cout << "Odd" << endl;
        break;
    case 2:
    case 4:
    case 6:
    case 8:
        cout << "Even" << endl;
        break;
    default:
        cout << "Number has more than one digit" << endl;
    }

    // Loops
    i = 0;
    while (i < 10) {
        cout << i << endl;
        i++;
    }

    i = 0;
    do {
        cout << i << endl;
        i++;
    } while (i < 10);

    for (i = 0; i < 10; i++) {
        cout << i << endl;
    }

    s = 0;
    while (s < 100) {
        cin >> i;
        s += i;
    }

    s = 0;
    while (true) {
        cin >> i;
        s += i;
        if (s >= 100) break;
    }

    return 0;
}
