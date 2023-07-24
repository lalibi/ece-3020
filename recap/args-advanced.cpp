#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " <number> <number>" << endl;
        return 1;
    }

    int x = atoi(argv[1]);
    int y = atoi(argv[2]);

    cout << x + y << endl;
}
