#include "pzhelp"

PROGRAM {
    int N, K, P[20000], s, c, i, j;

    N = READ_INT();
    K = READ_INT();

    FOR (i, 0 TO N-1) {
        P[i] = READ_INT();
    }

    FOR (i, 0 TO N-1) {
        c = 0;
        s = 0;
        FOR (j, i TO N) {
            c = c + 1;
            s = s + P[j];

            if (s == K) {
                WRITELN(c);
                break;
            } else if (s > K) {
                break;
            }
        }
    }

    WRITELN(s);
}