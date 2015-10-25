#include <stdio.h>

int main(int argc, char *argv[]) {

    int i = 0;

    if (argc == 1) {
        printf("There's only one argument.\n");
    } else if (argc > 1 && argc < 4) {
        printf("Here's your arguments:\n");

        for (i = 0; i < argc; i++) {
            printf("%s ", argv[i]);
        }

        printf("\n");
    } else {
        printf("You have too many arguments!\n");
        printf("Your last argument was %s.\n", argv[argc -1]);
    }

    return 0;
}
