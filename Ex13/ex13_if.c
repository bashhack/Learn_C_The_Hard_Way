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

            if (letter == 'a' || letter  == 'A') {
                printf("%d: 'A'\n", j);
            } else if (letter == 'e' || letter  == 'E') {
                printf("%d: 'E'\n", j);
            } else if (letter == 'i' || letter  == 'I') {
                printf("%d: 'I'\n", j);
            } else if (letter == 'o' || letter  == 'O') {
                printf("%d: 'O'\n", j);
            } else if (letter == 'u' || letter  == 'U') {
                printf("%d: 'U'\n", j);
            } else if (j >= 1 && (letter == 'y' || letter == 'Y')) {
                    printf("%d: 'Y'\n", j);
            } else {
                printf("%d: %c is not a vowel\n", j, letter);
            }
        }
    }

    return 0;
}