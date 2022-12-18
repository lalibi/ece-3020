#include <stdio.h>
#include <stdlib.h>

/* #include <iostream>
#include <cstdlib>
using namespace std; */

int compare(const void *p, const void *q) {
    return (*(int *) p - *(int *) q);
}

int main() {
    int i, N;

    // cin >> N;
    scanf("%d", &N);

    // int *A = new int[N];
    int *A = (int *) malloc(N * sizeof(int));
    // int *B = new int[N];
    int *B = (int *) malloc(N * sizeof(int));

    for (i = 0; i < N; i++) {
        // cin >> A[i];
        scanf("%d", &A[i]);
    }

    for (i = 0; i < N; i++) {
        // cin >> B[i];
        scanf("%d", &B[i]);
    }

    qsort(A, N, sizeof(int), compare);
    qsort(B, N, sizeof(int), compare);

    int min = 0, max = 0;
    int same = true;

    for (i = 0; i < N; i++) {
        if (A[i] != B[i]) {
            same = false;
            min = A[i] < B[i] ? A[i] : B[i];
            break;
        }
    }

    for (i = N - 1; i >= 0; i--) {
        if (A[i] != B[i]) {
            max = A[i] > B[i] ? A[i] : B[i];
            break;
        }
    }

    if (same) {
        // cout << "yes" << endl;
        printf("yes\n");
    } else {
        // cout << "no " << min << " " << max << endl;
        printf("no %d %d\n", min, max);
    }

    free(A);
    free(B);

    return 0;
}
