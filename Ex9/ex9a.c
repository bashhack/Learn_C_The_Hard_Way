#include <stdio.h>

int main(int argc, char *argv[]) {

    // Init
    char nameString[4] = {'a'};
    int name = 0;

    for (int i = 0; i < 4; ++i) {

        // Utilize bitwise operator
        name = (name << 8) + nameString[i];
    }

    // Signed int
    printf("%d\n", name);
    // Unsigned hex
    printf("%X\n", name);

    return 0;
}

// Result is 1627389952 and 61000000, respectively.