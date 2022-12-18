#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

#define MAX 60

void print_spaces(FILE *f, int spaces) {
    for (int i = 0; i < spaces; i++) {
        fprintf(f, " ");
    }
}

void print_line(FILE *f, char line[][MAX + 1], int word_count, int line_length, bool fill = true) {
    int spaces = MAX - line_length + 1;

    for (int i = 0; i < word_count; i++) {
        fprintf(f, "%s", line[i]);
        // If we are not at the end of the line, print one or more spaces
        if (i != word_count - 1) {
            fprintf(f, " ");
            // If we need to fill with more spaces, do so
            if (fill) {
                int spaces_to_add = spaces / (word_count - i - 1);
                print_spaces(f, spaces_to_add);
                spaces -= spaces_to_add;
            }
        }
    }
    fprintf(f, "\n");
}

int main() {
    char word[MAX + 1];
    char line[MAX / 2][MAX + 1] = {0};

    FILE *fin = fopen("in.txt", "r");
    FILE *fout = fopen("out.txt", "w");

    int line_length = 0;
    int word_count = 0;

    while (true) {
        fscanf(fin, "%s", word);

        // If we are about to exceed the line length, print the line and reset
        if (line_length + strlen(word) > MAX) {
            print_line(fout, line, word_count, line_length);

            line_length = 0;
            word_count = 0;
        } else if (feof(fin)) {
            // If we are at the end of the file, print the line and exit
            print_line(fout, line, word_count, line_length, false);

            break;
        }

        // Add the word to the line
        strcpy(line[word_count], word);
        line_length += strlen(word) + 1;
        word_count++;
    }

    fclose(fout);
    fclose(fin);

    return 0;
}
