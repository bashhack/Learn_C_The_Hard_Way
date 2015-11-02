# Exercise 13: Switch Statement
## How to Break It
### Forget a ```break``` and it'll run two or more blocks of code you don't want it to run.
Removing the first break from the program, resulted in the following error once the program encountered ```'a'```:
```
 ➜  ./Ex13 Marc
0: M is not a vowel
1: 'A'
1: 'E'
2: r is not a vowel
3: c is not a vowel
```
### Forget a ```default``` and have it silently ignore values you forgot.
Without the default case, the first break encountered after a vowel match stops the program completely preventing both a return to the default case and the continuation of the program itself.

```
 ➜  ./Ex13 Marc
1: 'A'
```
### Accidentally put in variable into the ```switch``` that evaluates to something unexpected, like an ```int``` that becomes weird values.
To test this condition, I initialized a new variable ```rand``` of type ```int``` which I then assigned to a value of data type ```char```.

After deleting the executable and rebuilding the program, I received the following output from CMake:
```
[ 50%] Building C object CMakeFiles/Ex13.dir/Ex13/ex13.c.o
/.../.../Development/Projects/Learn_C_The_Hard_Way/Ex13/ex13.c:20:22: warning: incompatible pointer to integer conversion assigning to 'int' from 'char *' [-Wint-conversion]
                rand = argv[1];
                     ^ ~~~~~~~
1 warning generated.
[100%] Linking C executable /.../.../Development/Projects/Learn_C_The_Hard_Way/builds/Debug/Ex13
[100%] Built target Ex13
```

The resulting output was generated after passing in a single argument to the program. As we have seen before, the C compiler assigned a random value to the variable:
```
 ➜  ./Ex13 Marc
0: M is not a vowel
1599932671: 'rand'
1: 'A'
2: r is not a vowel
3: c is not a vowel
```
### Use uninitialized values in the ```switch```.
I modified my program, as follows:
```
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("ERROR: You need at least one argument.\n");
        return 1;
    }

    int i = 0;
    int k;
//    int rand;

    for (i = 0; argv[1][i] != '\0'; i++) {
        char letter = argv[1][i];

        switch (letter) {
            case 'a':
            case 'A':
//                // Assign variable using incorrect data type
//                rand = argv[1];
//                printf("%d: 'rand'\n", rand);
                printf("%d: 'A'\n", i);
                break;

            case 'e':
            case 'E':
                // Utilize the uninitialized variable from init block
                printf("%d: my uninitialized variable in use\n", k);
                printf("%d: 'E'\n", i);
                break;

            case 'i':
            case 'I':
// Continued...abbreviated here for the sake of brevity
```

The output is shown below, where the uninitialized variable is printed to console as ```0```
```
 ➜  ./Ex13 espressoextreme
0: my uninitialized variable in use
0: 'E'
1: s is not a vowel
2: p is not a vowel
3: r is not a vowel
0: my uninitialized variable in use
4: 'E'
5: s is not a vowel
6: s is not a vowel
7: 'O'
0: my uninitialized variable in use
8: 'E'
9: x is not a vowel
10: t is not a vowel
11: r is not a vowel
0: my uninitialized variable in use
12: 'E'
13: m is not a vowel
0: my uninitialized variable in use
14: 'E'
```

## Extra Credit
### Write another program that uses math on the letter to convert it to lowercase, and then remove all the extraneous uppercase letters in the switch.
Please see ```ex13_conversion.c``` for the program I have written to accomplish this task.

In the process of completing this assignment, I also caught a small bug in the final case (testing for ```y```). As such, I refactored the original:
```
case 'Y':
    if (i > 2) {
        printf("%d: 'Y'\n", i);
    }
    break;
```

...into the following to ensure that the rules of the English language are represented correctly:
```
case 'y':
    if (i >= 1) {
        printf("%d: 'Y'\n", i);
    } else if (i < 1) {
        printf("%d: %c is not a vowel\n", i, letter);
    }
    break;
```

Testing this against two args, we have the following output:
```
 ➜  ./Ex13 yes
0: y is not a vowel
1: 'E'
2: s is not a vowel
```

```
 ➜  ./Ex13 eyes
0: 'E'
1: 'Y'
2: 'E'
3: s is not a vowel
```
### Use the ```','``` (comma) to initialize ```letter``` in the ```for-loop```.
```
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("ERROR: You need at least one argument.\n");
        return 1;
    }

    int i = 0;
    char letter = 0;

    // Initialize the for loop with a comma
    for (i = 0; letter = argv[1][i], letter != '\0'; i++) {

        switch (letter) {
            case 'a':
            case 'A':
                printf("%d: 'A'\n", i);
                break;

            case 'e':
            case 'E':
                printf("%d: 'E'\n", i);
                break;

            case 'i':
            case 'I':
                printf("%d: 'I'\n", i);
                break;

            case 'o':
            case 'O':
                printf("%d: 'O'\n", i);
                break;
// Continued...abbreviated here for the sake of brevity
```
### Make it handle all of the arguments you pass it with yet another ```for-loop```.
I've added a simple for loop to the program to print out the argument position, it's value, and the existing vowel-checking.
To view the program, please see ```ex13_args.c```. Its output is shown here:
```
 ➜  ./Ex13 one two three
Argument 1: one
0: 'O'
1: n is not a vowel
2: 'E'
Argument 2: two
0: t is not a vowel
1: w is not a vowel
2: 'O'
Argument 3: three
0: t is not a vowel
1: h is not a vowel
2: r is not a vowel
3: 'E'
4: 'E'
```
### Convert this ```switch-statement``` to an ```if-statement```. Which do you like better?
Please see my program ```ex13_if.c```. When I can opt for easier legibility of the program, I much prefer it, and as such I favor the ```switch-statement```.
### In the case for 'Y' I have the break outside the ```if-statement```. What's the impact of this and what happens if you move it inside the ```if-statement```. Prove to yourself that you're right.
I would expect the break inside to check the case as we have intended to write it (that is, to print ```Y``` if the condition is met and to fall to the default if needed).
After the change in the location of the ```break``` the default case can be reached successfully.

NOTE: Please see above where I addressed the vowel-checking logic for ```y``` and/or ```Y```

With the break inside:

```
 ➜  ./Ex13 yyyy
0: y is not a vowel
1: y is not a vowel
2: y is not a vowel
3: 'Y'
```

With the break outside:
```
 ➜  ./Ex13 yyyy
3: 'Y'
```

