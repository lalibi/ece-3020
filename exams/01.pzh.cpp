#include "pzhelp"

int a = 17, b = 7, c = 42;

PROC test(int &n, int r) {
    n = n / r;
    r = n % r;
}

PROGRAM {
    int n = 1717, r = 10;
    test(n, r);
    test(n, r);
    WRITELN(n + r);
}
