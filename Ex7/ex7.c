#include <stdio.h>
#include <limits.h>

int main(int argc, char *argv[]) {

    int bugs = 100;
    double bug_rate = 1.2;
    unsigned long unsigned_long_max = ULONG_MAX;
    unsigned long long unsigned_long_long_max = ULONG_LONG_MAX;

    printf("You have %d bugs at the imaginary rate of %.2f.\n", bugs, bug_rate);


    unsigned long universe_of_defects = ULONG_MAX;
    printf("The entire universe has %lu bugs.\n", universe_of_defects);
    printf("The max unsigned long value is: %lu.\n", unsigned_long_max);
    printf("The max unsigned long long value is: %llu.\n", unsigned_long_long_max);

    double expected_bugs = bugs * bug_rate;
    printf("You are expected to have %.2f bugs.\n", expected_bugs);

    double part_of_universe = expected_bugs / universe_of_defects;
    printf("That is only a %e portion of the universe.\n", part_of_universe);

    //Weird experiment
    char nul_byte = '\0';
    int care_percentage = bugs * nul_byte;
    printf("Which means you should care %d%%.\n", care_percentage);

    return 0;
}