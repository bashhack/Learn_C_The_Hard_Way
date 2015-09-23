#include <stdio.h>

int main(int argc, char *argv[]) {

    int areas[] = {10, 12, 13, 14, 20};
    char name[] = "Marc";
    char full_name[] = {'M', 'a', 'r', 'c', ' ', 'W', '.', ' ', 'L', 'a', 'u', 'g', 'h', 't', 'o', 'n', '\0'};

    printf("The size of an int: %ld\n", sizeof(int));
    printf("The size of areas (int[]): %ld\n", sizeof(areas));
    printf("The number of ints in areas: %ld\n", (sizeof(areas) / sizeof(int)));
    printf("The first area is %d, the second area is %d,\n", areas[0], areas[1]);

    printf("The size of a char: %ld\n", sizeof(char));
    printf("The size of name (char[]): %ld\n", sizeof(name));
    printf("The number of chars: %ld\n", (sizeof(name) / sizeof(char)));

    printf("The size of full_name (char[]): %ld\n", sizeof(full_name));
    printf("The number of chars: %ld\n", (sizeof(full_name) / sizeof(char)));

    printf("name = \"%s\" and full name = \"%s\"\n", name, full_name);

    printf("The third character of name (char[]) is: %c\n", name[2]);
    printf("The result of accessing an index outside of bounds in name (char[]) is: %c.\n", name[50]);

    printf("The ninth character of name (char[]) is: %c\n", full_name[8]);
    printf("The result of accessing an index outside of bounds in name (char[]) is: %c\n", full_name[50]);


    // Extra credit
    areas[0] = 100;
    areas[1] = 111;
    printf("The new value at the 0th index of the areas array is: %d\n", areas[0]);
    printf("The new value at the 1st index of the areas array is: %d\n", areas[1]);

    name[0] = 'C';
    printf("It's Marc with a 'C' he told the Starbucks barista and they wrote: '%s'\n", name);
    name[1] = 'K';
    printf("I alway have to tell people it's 'M-A-R-C', not 'M-A-R-%c.'\n", name[1]);

    areas[1] = name[0];
    printf("The assigned value of 'areas[1]' is now: %d\n"
                   "This appears to be the Unicode value of 'C,' which is 67.", areas[1]);

    return 0;

}