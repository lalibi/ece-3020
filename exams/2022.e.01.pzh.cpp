#include "pzhelp"

int a = 17, b = 7, c = 42;

PROC p(int a, int &c) {
    int b = 2 * c++;
    WRITELN(a, b, c);
    if (a > c) {
        p(++b / 5, c);
        WRITELN(a, b, c);
    } else c *= 3;
}

PROGRAM {
    p(c, b);
    WRITELN(a, b, c);
}
