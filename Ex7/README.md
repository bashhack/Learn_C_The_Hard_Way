# Exercise 7: More Variables, Some Math
## Extra Credit
### Make the number you assign to universe_of_defects various sizes until you get a warning from the compiler.
I wanted to explore the additional C libraries available beyond the ```stdio.h```, and found a utility library ```limits.h```.
 Using the built in symbolic constants, I used ```LONG_MAX``` assigned to my variable and added ```1L```.

```
#include <stdio.h>
#include <limits.h>

int main(int argc, char *argv[]) {

    int bugs = 100;
    double bug_rate = 1.2;
    long long_max = LONG_MAX;

    printf("You have %d bugs at the imaginary rate of %.2f.\n", bugs, bug_rate);

    long universe_of_defects = LONG_MAX + 1L;
    printf("The entire universe has %ld bugs.\n", universe_of_defects);
    printf("The max long value is: %ld.\n", long_max);

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
```

This resulted in the following error:
```
[ 50%] Building C object CMakeFiles/Ex7.dir/Ex7/ex7.c.o
.../Development/Projects/LCTHW/Ex7/ex7.c:14:41: warning: overflow in expression; result is -9223372036854775808 with type 'long' [-Winteger-overflow]
    long universe_of_defects = LONG_MAX + 1L;
                                        ^
1 warning generated.
[100%] Linking C executable .../Development/Projects/LCTHW/builds/Debug/Ex7
[100%] Built target Ex7
```

### What do these really huge numbers actually print out?
```
You have 100 bugs at the imaginary rate of 1.20.
The entire universe has -9223372036854775808 bugs.
The max long value is: 9223372036854775807.
You are expected to have 120.00 bugs.
That is only a -1.301043e-17 portion of the universe.
Which means you should care 0%.

Process finished with exit code 0
```

### Change long to unsigned long and try to find the number that makes that one too big.
Taking a similar approach to the last exercise, I added ```1UL``` to ```ULONG_MAX```. This resulted in the following output:

```
You have 100 bugs at the imaginary rate of 1.20.
The entire universe has 0 bugs.
The max long value is: 0.
You are expected to have 120.00 bugs.
That is only a inf portion of the universe.
Which means you should care 0%.
```

Checking the value of ```ULONG_MAX``` on its own resulted in: ```18446744073709551615```.

### Go search online to find out what unsigned does.
An unsigned value represents a non-zero integer value.

### Try to explain to yourself (before I do in the next exercise) why you can multiply a char and an int.
Given that both ```int``` and ```char``` are numerical types (assigned a byte value, ```4``` and ```1```, respectively),
when we multiply, perhaps the compiler simply treats both types as valid numeric operands.