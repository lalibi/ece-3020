#include "pzhelp"
#include <bits/stdc++.h>

PROC slice(int P[20000], int C[20000], int start, int end) {
    int i;
    FOR (i, start TO end) {
        C[i-start] = P[i];
    }
}

PROC sort(int C[20000]) {
    int n = sizeof(C) / sizeof(C[0]);
    std::sort(C, C + n);
}

PROGRAM {
    int N, K, P[20000], S[20000], i, j;

    WRITE("Enter the number of residences: ");
    N = READ_INT();

    WRITE("?: ");
    K = READ_INT();

    FOR (i, 0 TO N-1) {
        WRITE("Enter the number of residents in residence #", i+1, ": ");
        P[i] = READ_INT();
    }

    FOR (i, 0 TO N-1) {
        FOR (j, i TO N-1) {
            int l = j - i + 1;
            if (l < K) continue;
            slice(P, S, i, j);
            sort(S);
            int median_pos = (l-1) / 2;
            WRITELN("Start:", i, "End:", j, "Median (pos):", median_pos, "Median (value):", S[median_pos]);
        }
    }

    return 0;
}
