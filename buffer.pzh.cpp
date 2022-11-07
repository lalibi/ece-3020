#include "pzhelp"

PROGRAM { // addition2
    int first, second;
    WRITE("First: "); first = READ_INT();
    SKIP_LINE();
    WRITE("Second: "); second = READ_INT();
    WRITELN("Result: ", first + second);
}
