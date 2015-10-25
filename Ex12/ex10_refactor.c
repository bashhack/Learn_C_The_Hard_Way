#include <stdio.h>

//Ex10
int main(int argc, char *argv[]) {

    // Init
    int i = 0,
        j = 0;

//    for (i = 1; i < argc; ++i) {
//        printf("arg %d: %s\n", i, argv[i]);
//    }

    /* Refactoring the loop above using if-else block */
    if (argc > 1) {
        printf("You have passed arguments to your program!\nThey are listed below:\n");

        for (i = 1; i < argc; ++i) {
            printf("arg %d: %s\n", i, argv[i]);
        }

        printf("\n");
    } else {
        printf("There were no args passed to the program.\n");
    }

    char *guitars[] = {
            "Fender", "Gibson",
            "Rickenbacker", "Ibanez"
    };

    int num_of_guitars;

    num_of_guitars = 4;

    for (j = 0; j < num_of_guitars; ++j) {
        // Using if block with break statement to leave loop early
        if (j == 2) {
            break;
        }
        printf("guitars %d: %s\n", j, guitars[j]);
    }

    return 0;
}
