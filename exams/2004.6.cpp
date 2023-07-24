#include <cstdio>
#include <cstring>

bool compare_strings(const char *a, const char *b) {
    while (true) {
        if (*a != *b) return false;

        if (*a == '\0' || *b == '\0') break;

        a += 1;
        b += 1;
    }

    return true;
}

int main() {
    FILE *fin = fopen("data/fin.txt", "r");
    if (fin == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // if ((fin = fopen("data/fin.txt", "r")) == NULL) return 1;

    int count = 0;
    char word[100];
    while (fscanf(fin, "%s", word) != EOF) {
        // if (strcmp(word, "computer") == 0) {
        if (compare_strings(word, "computer")) {
            count += 1;
        }
    }

    printf("%d φορές computer στο αρχικό κείμενο\n", count);

    return 0;
}
