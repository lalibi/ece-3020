#include "pzhelp"

FUNC int digit_sum(int x, int p) {
    int sum = 0;

    while (x > 0) {
        sum = sum + pow(x % 10, p);
        x = x / 10;
    }

    return sum;
}

PROGRAM {
    int i, N;

    // WRITE("Enter N: ");
    N = READ_INT();

    FOR (i, 0 TO 99999999) {
        if (digit_sum(i, N) == i) {
            WRITELN(i);
        }
    }
}
