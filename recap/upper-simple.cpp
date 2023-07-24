#include <cctype>
#include <cstdio>
#include <cstring>

int main(int argc, char **argv) {
    FILE *fin, *fout;
    int len;
    char word[50];

    /* fin = fopen(argv[1], "r");
    if (fin == nullptr) return 1; */

    if ((fin = fopen(argv[1], "r")) == nullptr) return 1;
    if ((fout = fopen(argv[2], "w")) == nullptr) return 1;

    fscanf(fin, "%s", word);
    fprintf(fout, "%s ", word);
    len = strlen(word);

    while (fscanf(fin, "%s", word) != EOF) {
        if (strlen(word) >= len) {
            fprintf(fout, "%s", word);
        } else {
            for (int i = 0; i < strlen(word); i++) {
                fprintf(fout, "%c", toupper(word[i]));
                // fprintf(fout, "%c", word[i] - 32);
            }
        }
        fprintf(fout, " ");
    }

    fclose(fout);
    fclose(fin);

    return 0;
}
