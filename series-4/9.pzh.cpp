#include "pzhelp"

PROGRAM {
    int i, j, N, M;
    REAL A[100][100], sum, R[100], C[100];

    N = READ_INT();
    M = READ_INT();

    FOR(i, 0 TO N-1) {
        FOR(j, 0 TO M-1) {
            A[i][j] = READ_REAL();
        }
    }

    // Sum per row
    FOR (i, 0 TO N-1) {
        sum = 0;
        FOR (j, 0 TO M-1) {
            sum += A[i][j];
        }
        R[i] = sum / M;
    }

    sum = 0;
    FOR (i, 0 TO N-1) {
        sum += R[i];
    }
    WRITELN(FORM(sum / N, 0, 3));

    // Sum per column
    FOR (j, 0 TO M-1) {
        sum = 0;
        FOR (i, 0 TO N-1) {
            sum += A[i][j];
        }
        C[j] = sum / N;
    }

    sum = 0;
    FOR (j, 0 TO M-1) {
        sum += C[j];
    }
    WRITELN(FORM(sum / M, 0, 3));
}
