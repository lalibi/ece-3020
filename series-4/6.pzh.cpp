#include "pzhelp"

FUNC bool is_palindrome(char W[]) {
    int i, l;
    l = strlen(W);

    FOR (i, 0 TO l/2 - 1) {
        int j = l - 1 - i;
        if (W[i] != W[j]) {
            return false;
        }
    }

    return true;
}

PROGRAM {
    int i, j, N, c;
    bool f;
    char W[21];

    N = READ_INT();

    // Empty the buffer to get rid of the '\n'
    SKIP_LINE();

    c = 0;
    // For each word/phrase
    FOR (i, 1 TO N) {
        // For each letter
        j = 0;
        f = false;
        while (true) {
            char c = getchar();
            if (c == '\n') {
                break;
            } else if (j == 20) {
                f = true;
                // Empty the buffer
                SKIP_LINE();
                break;
            } else {
                W[j] = c;
                j = j + 1;
            }
        }
        W[j] = '\0';

        if (j == 0) {
            WRITELN("empty");
        } else if (f) {
            WRITELN("error");
        } else if (is_palindrome(W)) {
            WRITELN("yes");
            c = c + 1;
        } else {
            WRITELN("no");
        }
    }

    REAL perc = (REAL) c / N * 100;
    WRITELN(FORM(perc, 0, 3));
}
