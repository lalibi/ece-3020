#include <cstdio>

int main() {
    FILE *fin = fopen("in.txt", "r");
    FILE *fout = fopen("out.txt", "w");

    int n;
    fscanf(fin, "%d", &n);

    int *a = new int[n];

    for (int i = 0; i < n; i++) {
        fscanf(fin, "%d", &a[i]);
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    fprintf(fout, "Sum: %d Avg: %f\n", sum, (float) sum / n);

    int odds = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 1) {
            odds += 1;
        }
    }
    fprintf(fout, "Odds: %d\n", odds);

    int min = a[0];
    int max = a[0];
    for (int i = 1; i < n; i++) {   // Start from 1
        if (a[i] < min) min = a[i];
        if (a[i] > max) max = a[i];
    }
    fprintf(fout, "Min: %d Max: %d\n", min, max);

    return 0;
}
