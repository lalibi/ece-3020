#include "pzhelp"

PROGRAM {
    int a, b, c, d, x1, x2;
    WRITE("Enter values for a, b and c: ");
    a = READ_INT();
    b = READ_INT();
    c = READ_INT();

    d = b * b - 4 * a * c;

    WRITELN("Discriminant:", d);

    if (d > 0) {
        x1 = (-b + sqrt(d)) / (2 * a);
        x2 = (-b - sqrt(d)) / (2 * a);

        WRITELN("x1:", x1);
        WRITELN("x2:", x2);
    }
}
