#include <stdio.h>

char toLowerCase(char letter) {
    if (letter >= 'A' && letter <= 'Z') {
        /*
         * Could also rewrite this, of course, as the following
         * but it's a poor decision as it would require
         * my fellow developers to know or lookup the ASCII
         * value ranges for uppercase and lowercase letters:
         * if (letter >= 65 && letter <= 90)
         */
        return (letter + 32);
    } else {
        return letter;
    }
}

int main(int argc, char *argv[]) {

    int i = 0;
    char letter;

    // Initialize the for loop with a comma
    for (i = 0; letter = argv[1][i], letter != '\0'; i++) {
        letter = toLowerCase(letter);

        switch (letter) {
            case 'a':
                printf("%d: 'A'\n", i);
                break;

            case 'e':
                printf("%d: 'E'\n", i);
                break;

            case 'i':
                printf("%d: 'I'\n", i);
                break;

            case 'o':
                printf("%d: 'O'\n", i);
                break;

            case 'u':
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