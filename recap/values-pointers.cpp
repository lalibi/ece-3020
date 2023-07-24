#include <cstdio>

int main() {
    int a, b, *c;

    a = 4;
    b = a;                            // Copy the value of a into b
    c = &a;                           // Copy the address of a into c

    printf("%d %d %d\n", a, b, *c);   // 4 4 4

    a += 1;

    printf("%d %d %d\n", a, b, *c);   // 5 4 5
}
