#include "pzhelp"

PROGRAM {
    int *p = new int, *q = new int, *t = new int;
    *p = *q = 17;
    *t = 5 * *p / 2;
    q = p;
    *q /= 2;
    *q = *t + *p;
    *t += *p + *q;
    WRITELN(*p + *q + *t);
}
