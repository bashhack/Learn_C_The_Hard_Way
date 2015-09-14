#include <stdio.h>

int main(int argc, char *argv[]) {

    int distance = 100,
            my_int = 10;
    float power = 2.345f,
            my_float = 10.0;
    double super_power = 56789.5432,
            my_double = 110.011;
    char initial = 'W';
    char first_name[] = "Marc",
            last_name[] = "Laughton",
            empty_str[] = "",
            my_string[] = "string";


    printf("You are %d miles away.\n", distance);
    printf("You have %f levels of power.\n", power);
    printf("You have %f awesome super powers.\n", super_power);
    printf("I have a middle initial %c.\n", initial);
    printf("I have a first name %s.\n", first_name);
    printf("I have a last name %s.\n", last_name);
    printf("My full name is: %s %c %s.\n", first_name, initial, last_name);
    printf("", empty_str); // Warning: Intentionally incorrect


    // Testing types of string formatting output

    /* print an integer, no formatting */
    printf("%d\n", my_int);
    /* print an integer, padded on left with spaces to total 6 chars */
    printf("%6d\n", my_int);
    /* print an integer, padded on right with spaces to total 6 chars */
    printf("%-6d\n", my_int);
    /* print an integer, padded on left with zeroes to total 6 chars */
    printf("%.6d\n", my_int);


    /* print a string, no formatting */
    printf("%s\n", my_string);
    /* print a string, padded with spaces on left to 20 chars */
    printf("%20s\n", my_string);
    /* print a string, padded with spaces on right to 20 chars */
    printf("%-20s\n", my_string);
    /* print a string, truncated after 3 chars */
    printf("%.3s\n", my_string);

    /* print a float, default precision is 6 places */
    printf("%f\n", my_float);

    /* print a double, default precision is 6 places */
    printf("%f\n", my_double);
    /* print a double, 2 places of precision */
    printf("%.2f\n", my_double);
    /* print a double, 2 places of precision, padded with space to 10 */
    printf("%10.2f\n", my_double);
    /* print a double, use exponential notation if more than 3 digits */
    printf("%.3g\n", my_double);

    return 0;
}