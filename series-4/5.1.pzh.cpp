#include "pzhelp"

FUNC int digit_sum(int x, int P[]) {
    int y = x, sum;

    sum = 0;
    while (y != 0) {
        int last_digit = y % 10;
        sum = sum + P[last_digit];
        y = y / 10;
    }

    return sum;
}

PROGRAM {
    int i, N, P[10];

    N = READ_INT();

    FOR (i, 0 TO 9) {
        P[i] = pow(i, N);
    }

    FOR (i, 0 TO 99999999) {
        if (i == digit_sum(i, P)) {
            WRITELN(i);
        }
    }
}
