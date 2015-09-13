#include <stdio.h>

//Warning: This program below is wrong on purpose.

int main() {
    int age = 10;
    int height;

    printf("I am %d years old.\n");
    printf("I am %d inches tall.\n", height);

    return 0;
}

//Warning: This program below is to test Valgrind on valid input

//int main() {
//    int age = 10;
//    int height = 75;
//
//    printf("I am %d years old.\n", age);
//    printf("I am %d inches tall.\n", height);
//
//    return 0;
//}
