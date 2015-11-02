#include <stdio.h>

char toLowerCase(char letter) {
    if (letter >= 'A' && letter <= 'Z') {
        return (letter + 32);
    } else {
        return letter;
    }
}

int main(int argc, char *argv[]) {

    int i = 0;
    int j = 0;
    char letter;

    for (i = 1; i < argc; i++) {
        printf("Argument %d: %s\n", i, argv[i]);

        for (j = 0; letter = argv[i][j], letter != '\0'; j++) {
            letter = toLowerCase(letter);

            switch (letter) {
                case 'a':
                    printf("%d: 'A'\n", j);
                    break;

                case 'e':
                    printf("%d: 'E'\n", j);
                    break;

                case 'i':
                    printf("%d: 'I'\n", j);
                    break;

                case 'o':
                    printf("%d: 'O'\n", j);
                    break;

                case 'u':
                    printf("%d: 'U'\n", j);
                    break;

                case 'y':
                    if (j >= 1) {
                        printf("%d: 'Y'\n", j);
                    } else if (j < 1) {
                        printf("%d: %c is not a vowel\n", j, letter);
                    }
                    break;

                default:
                    printf("%d: %c is not a vowel\n", j, letter);
            }
        }
    }

    return 0;
}