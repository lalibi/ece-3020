#include <cstdio>

int main() {
    FILE *fin = fopen("data/grades.txt", "r");   // read
    if (fin == nullptr) return 1;

    int n;
    fscanf(fin, "%d", &n);

    float sum = 0;
    for (int i = 0; i < n; i++) {
        float g;
        fscanf(fin, "%f", &g);
        sum += g;
    }

    fclose(fin);

    FILE *fout = fopen("data/results.txt", "w");   // write
    if (fout == nullptr) return 1;

    fprintf(fout, "Avg: %.2f", sum / n);

    fclose(fout);

    return 0;
}
