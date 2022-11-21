#include "pzhelp"

PROGRAM {
    int i, j, N, M, A[100][100], max, min, R[100], C[100];

    N = READ_INT();
    M = READ_INT();

    FOR(i, 0 TO N-1) {
        FOR(j, 0 TO M-1) {
            A[i][j] = READ_INT();
        }
    }

    // Max per column
    FOR (j, 0 TO M-1) {
        max = A[0][j];
        FOR (i, 0 TO N-1) {
            if (A[i][j] > max) {
                max = A[i][j];
            }
        }
        C[j] = max;
    }

    min = C[0];
    FOR (j, 0 TO M-1) {
        if (C[j] < min) {
            min = C[j];
        }
    }
    WRITELN(min);

    // Min per row
    FOR (i, 0 TO N-1) {
        min = A[i][0];
        FOR (j, 0 TO M-1) {
            if (A[i][j] < min) {
                min = A[i][j];
            }
        }
        R[i] = min;
    }

    max = R[0];
    FOR (i, 0 TO N-1) {
        if (R[i] > max) {
            max = R[i];
        }
    }
    WRITE(max);
}
