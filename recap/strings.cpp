#include <cstdio>
#include <cstring>

int main() {
    char s[] = "KaTERINA";
    char c[10];
    char *p = s;

    printf("%d\n", strlen(s));   // 8
    printf("%d\n", strlen(p));   // 8

    // We cannot do assignment between arrays / strings
    // c = s
    strcpy(c, s);

    printf("%s\n", s);   // KaTERINA
    printf("%s\n", p);   // KaTERINA
    printf("%s\n", c);   // KaTERINA

    s[1] = 'A';

    printf("%s\n", s);   // KATERINA
    printf("%s\n", p);   // KATERINA
    printf("%s\n", c);   // KaTERINA

    c[1] = 'A';

    printf("%s\n", s);   // KATERINA
    printf("%s\n", p);   // KATERINA
    printf("%s\n", c);   // KATERINA

    if (s == p) {
        printf("s == p\n");
    } else {
        printf("s != p\n");
    }

    // We cannot do comparison between arrays / strings
    /* if (s == c) {
        printf("s == c\n");
    } else {
        printf("s != c\n");
    } */

    if (strcmp(s, c) == 0) {   // -1 0 1
        printf("s == c\n");
    } else {
        printf("s != c\n");
    }

    printf("%d\n", strcmp(s, "NIKOS"));      // -1
    printf("%d\n", strcmp(s, "KATERINA"));   //  0
    printf("%d\n", strcmp(s, "ALEKA"));      //  1
}
