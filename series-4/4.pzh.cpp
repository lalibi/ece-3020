#include "pzhelp"

FUNC int digit_sum(int x) {
    int sum = 0;

    while (x > 0) {
        sum = sum + pow(x % 10, 4);
        x = x / 10;
    }

    return sum;
}

PROGRAM {
    int i;

    FOR (i, 1000 TO 9999) {
        if (digit_sum(i) == i) {
            WRITELN(i);
        }
    }
}
