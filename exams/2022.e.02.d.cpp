#include "pzhelp"

FUNC int fun(int n) {
    int t;
    if (n <= 1) return 1;
    else return 2 * fun(n - 2);
}

PROGRAM {
    WRITELN(fun(17));
}
