#include <cstdio>

int main() {
    char s[] = "Hello World!";
    char *p = s;

    printf("%s\n", s);       // Hello World!
    printf("%s\n", p);       // Hello World!
    printf("%s\n", p + 6);   // World!

    s[5] = '\0';
    printf("%s\n", s);   // Hello
}
