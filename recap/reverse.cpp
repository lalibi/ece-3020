#include <cstdio>
#include <cstring>

void reverse1(char *word) {
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        printf("%c", word[len - i - 1]);
    }
}

void reverse2(char *word) {
    int len = strlen(word);
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", word[i]);
    }
}

int main() {
    char word[51];

    scanf("%s", word);
    reverse1(word);
}
