# Exercise 11: While-Loop And Boolean Expressions
## How to Break It
### Forget to initialize the first ```int i```; so have it loop wrong.
Removing the initializer value and passing arguments to the program resulted in no display of arg count in the subsequent output.

The output generated was:
```
 ➜  ./Ex11 one two three
band 0: Genesis
band 1: Yes
band 2: Camel
band 3: Pink Floyd
```

### Forget to initialize the second loop's ```i``` so that it retains the value from the end of the first loop. Now your second loop might or might not run.
Removing the initializer value from the second loop and passing arguments to the program resulted in no display of the ```progRockBands```.

The output was:
```
 ➜  ./Ex11 one two three
arg 0: ./Ex11
arg 1: one
arg 2: two
arg 3: three
```

### Forget to do a ```i++``` increment at the end of the loop and you get a "forever loop", one of the dreaded problems of the first decade or two of programming.
A wise lesson - CMake did not warn when the counter increment was removed, nor did Valgrind present any compiler errors/warnings.

## Extra Credit
### Make these loops count backward by using ```i--``` to start at ```argc``` and count down to 0. You may have to do some math to make the array indexes work right.
My solution was to follow the pattern I revert to when writing more performant JavaScript while-loops:

```
/* Decrement Version */
int main(int argc, char *argv[]) {

    // Go through each string in argv
    int i = argc;
    while (i--) {
        printf("arg %d: %s\n", i, argv[i]);
    }

    // Making my own array of strings
    char *progRockBands[] = {
            "Genesis", "Yes",
            "Camel", "Pink Floyd"
    };

    int num_bands = 4;
    i = num_bands;
    while (i--) {
        printf("band %d: %s\n", i, progRockBands[i]);
    }

    return 0;

}
```

### Use a while loop to copy the values from ```argv``` into ```states```.
NOTE: The ```states``` array is the ```progRockBands```

My modified program is shown below:
```
#include <stdio.h>

/* Copying the values */
int main(int argc, char *argv[]) {

    // Go through each string in argv
    int i = 0;
    while (i < argc) {
        printf("arg %d: %s\n", i, argv[i]);
        i++;
    }

    // Making my own array of strings
    char *progRockBands[] = {
            "Genesis", "Yes",
            "Camel", "Pink Floyd"
    };


    i = 0;
    while (i < argc) {
        progRockBands[i] = argv[i];
        i++;
    }

    int num_bands = 4;
    i = 0; // watch for this
    while (i < num_bands) {
        printf("band %d: %s\n", i, progRockBands[i]);
        i++;
    }

    return 0;

}
```

The output without args passed to the program is shown here:
```
 ➜  ./Ex11
arg 0: ./Ex11
band 0: ./Ex11
band 1: Yes
band 2: Camel
band 3: Pink Floyd
```

The output with args passed to the program is shown here:
```
 ➜  ./Ex11 one two three
arg 0: ./Ex11
arg 1: one
arg 2: two
arg 3: three
band 0: ./Ex11
band 1: one
band 2: two
band 3: three
```

### Make this copy loop never fail such that if there's too many ```argv``` elements it won't put them all into ```states```.
I was able to accomplish this task by passing more args than there were in the initial state of the ```progRockBands``` array.

The output is shown below:
```
 ➜  ./Ex11 one two three four five
arg 0: ./Ex11
arg 1: one
arg 2: two
arg 3: three
arg 4: four
arg 5: five
band 0: ./Ex11
band 1: one
band 2: two
band 3: three
Abort trap: 6
```

Further, program ```./Ex11``` continued processing until the CPU spiked and I manually stopped the process.

### Research if you've really copied these strings. The answer may surprise and confuse you though.
From the research I was able to gather, it does look like this method does in fact copy the strings, as we expected.

However, there is much discussion around the proper way to copy strings and arrays in C, including but not limited to:

> memcpy

...and

> strcpy