#include <stdio.h>

int main(int argc, char *argv[]) {

    // Init
    int i = 0;

    // At i = 0, should present the executable itself
    for (i = 1; i < argc; ++i) {
        printf("arg %d: %s\n", i, argv[i]);
    }

    char *guitars[] = {
            "Fender", "Gibson",
            "Rickenbacker", "Ibanez"
    };
    int num_of_guitars  = 4;

    for (i = 0; i < num_of_guitars; ++i) {
        printf("guitars %d: %s\n", i, guitars[i]);
    }

    return 0;
}