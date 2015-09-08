#include <stdio.h>

int main() {
    int age = 10;
    int height = 75;

    printf("I am %d years old\n", age);
    printf("I am %d inches tall\n", height);

    return 0;
}

//#include <stdio.h>
//#include <errno.h>
//
//int main() {
//    char my_char = 'm';
//    int my_int = -29;
//    double my_double = 234567.574635;
//    float my_float = 3.45;
//    char my_string[] = "Marc";
//    unsigned int my_unsigned_int = 74;
//
//
//    printf("Single character: %c\n", my_char);
//    printf("Integer: %d\n", my_int);
//    printf("Double, exponential notation: %e\n", my_double);
//    printf("Double, exponential notation (with capital 'E'): %E\n", my_double);
//    printf("Floating-point: %f\n", my_float);
//    printf("Another method of formating with integer: %i\n", my_int);
//
//    errno = EACCES;
//    printf("errno string (EACCES): %m\n");
//    printf("String: %s\n", my_string);
//    printf("Unsigned integer: %u\n", my_unsigned_int);
//    printf("Hexadecimal notation: %x\n", my_int);
//    printf("Hexadecimal notation (all capitalized): %X\n", my_unsigned_int);
//    printf("This prints the percentage symbol: %%\n");
//
//    return 0;
//}