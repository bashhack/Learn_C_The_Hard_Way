/*
 * Updating Ex12 to reflect how the program behaves at runtime
 * with no additional arguments supplied beyond the program
 * itself, which the compiler sees as the 'first' argument.
 */

#include <stdio.h>

int main(int argc, char *argv[]) {

    int i = 0;

    if (argc == 1) {
        printf("You've not supplied any arguments above and beyond the first (the program itself).\n");
    } else if (argc == 2) {
        printf("You've only supplied one argument.\n");
    } else if (argc > 1 && argc < 4) {
        printf("Here's your arguments:\n");

        for (i = 0; i < argc; i++) {
            printf("%s ", argv[i]);
        }

        printf("\n");
    } else {
        printf("You have too many arguments!\n");
    }

    return 0;
}