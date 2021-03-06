#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("ERROR: You need at least one argument.\n");
        return 1;
    }

    int i = 0;
    char letter = 0;
//    int rand;
//    int k;

//    for (i = 0; argv[1][i] != '\0'; i++) {
//        char letter = argv[1][i];

    // Initialize the for loop with a comma
    for (i = 0; letter = argv[1][i], letter != '\0'; i++) {

        switch (letter) {
            case 'a':
            case 'A':
//                // Assign variable using incorrect data type
//                rand = argv[1];
//                printf("%d: 'rand'\n", rand);
                printf("%d: 'A'\n", i);
                break;

            case 'e':
            case 'E':
//                // Utilize the uninitialized variable from init block
//                printf("%d: my uninitialized variable in use\n", k);
                printf("%d: 'E'\n", i);
                break;

            case 'i':
            case 'I':
                printf("%d: 'I'\n", i);
                break;

            case 'o':
            case 'O':
                printf("%d: 'O'\n", i);
                break;

            case 'u':
            case 'U':
                printf("%d: 'U'\n", i);
                break;

            case 'y':
                if (i >= 1) {
                    printf("%d: 'Y'\n", i);
                } else if (i < 1) {
                    printf("%d: %c is not a vowel\n", i, letter);
                }
                break;

            default:
                printf("%d: %c is not a vowel\n", i, letter);
        }
    }

    return 0;
}