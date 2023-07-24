#include <cctype>
#include <cstdio>
#include <cstring>

#define MAX_WORD_LENGTH 50

void touppercase(char *word) {
    for (int i = 0; i < strlen(word); i++) {
        word[i] = toupper(word[i]);
    }
}

int main(int argc, char *argv[]) {
    FILE *fin, *fout;

    char *fnameIn = argv[1];
    char *fnameOut = argv[2];

    /* fin = fopen(fnameIn, "r");
    if (fin == nullptr) return 1; */

    if ((fin = fopen(fnameIn, "r")) == nullptr) return 1;
    if ((fout = fopen(fnameOut, "w")) == nullptr) return 1;

    char word[MAX_WORD_LENGTH];

    /* while (true) {
        int res = fscanf(fin, "%s", word);
        if (res == EOF) break;
        fprintf(fout, "Word: %s\n", word);
    } */

    while (fscanf(fin, "%s", word) != EOF) {
        touppercase(word);
        fprintf(fout, "Word: %s (%llu)\n", word, strlen(word));
    }

    fclose(fout);
    fclose(fin);
}
