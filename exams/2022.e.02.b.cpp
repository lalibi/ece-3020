#include "pzhelp"

PROGRAM {
    int arr[] = {7, 0, 33};
    int *p = arr + 1, *g = arr;
    ++*p;
    g += 2;
    WRITELN(*(g - 1), arr[1], *p, *g);
}
