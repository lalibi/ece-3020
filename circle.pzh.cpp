#include "pzhelp"

PROGRAM {
    REAL r, c, a;
    WRITE("Enter the radius of the circle: ");
    r = READ_REAL();

    REAL pi = 3.14159;

    c = 2 * pi * r;
    a = pi * r * r;

    WRITELN("Circumference:", FORM(c, 0, 3));
    WRITELN("Area:", FORM(a, 0, 3));
}
