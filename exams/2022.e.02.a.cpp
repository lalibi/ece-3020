#include "pzhelp"

PROGRAM {
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 10, k = 3;

    int min = n, i = 0;
    while (i < min) {
        int temp = A[i], j = i;
        while (j != (n + i - k) % n) {
            A[j] = A[(j + k) % n];
            j = (j + k) % n;
            if (j < min) min = j;
        }
        A[(n + i - k) % n] = temp;
        i += 1;
    }

    for (int i = 0; i < n; i++) {
        WRITE(A[i], " ");
    }
}
