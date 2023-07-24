#include <cctype>
#include <cstdio>
#include <cstring>

#define MAX_WORD_LENGTH 50
#define MAX_LINE_LENGTH 500

void print_to_upper(FILE *f, char *word) {
    for (int i = 0; i < strlen(word); i++) {
        fprintf(f, "%c", toupper(word[i]));
    }
}

int main(int argc, char **argv) {
    FILE *fin, *fout;
    int len;
    char word[MAX_WORD_LENGTH], line[MAX_LINE_LENGTH];

    /* fin = fopen(argv[1], "r");
    if (fin == nullptr) return 1; */

    if ((fin = fopen(argv[1], "r")) == nullptr) return 1;
    if ((fout = fopen(argv[2], "w")) == nullptr) return 1;

    // Read each line
    while (fgets(line, MAX_LINE_LENGTH, fin) != NULL) {
        // Read first word
        sscanf(line, "%s", word);
        int len = strlen(word);
        fprintf(fout, "%s ", word);

        // Read the rest of the line
        char *remainingLine = line + strlen(word) + 1;
        while (sscanf(remainingLine, "%s", word) == 1) {
            if (strlen(word) >= len) {
                fprintf(fout, "%s", word);
            } else {
                print_to_upper(fout, word);
            }
            fprintf(fout, " ");
            remainingLine += strlen(word) + 1;
        }
        fprintf(fout, "\n");
    }

    fclose(fout);
    fclose(fin);

    return 0;
}
