#include <stdio.h>

int main(int argc, char *argv[]) {

    // Init
    int i = 0,
        j = 0;

    // At i = 0, should present the executable itself
    for (i = 1; i < argc; ++i) {
        printf("arg %d: %s\n", i, argv[i]);
    }

    char *guitars[] = {
            "Fender", "Gibson",
            "Rickenbacker", "Ibanez"
    };

    int num_of_guitars;

    num_of_guitars = 4;

//    guitars[1] = argv[1];
//    argv[1] = guitars[1];

    for (j = 0; j < num_of_guitars; ++j) {
        printf("guitars %d: %s\n", j, guitars[j]);
    }

//    printf("result of assignment to argv %s", argv[1]);
//    printf("result of assignment to guitars %s", guitars[1]);

    return 0;
}