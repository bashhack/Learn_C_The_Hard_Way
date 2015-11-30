# Exercise 14: Writing and Using Functions
## How to Break It
### Remove the forward declarations to confuse the compiler and cause it to complain about ```can_print_it``` and ```print_letters```
The removal of the forward declarations resulted in a CMake build error:
```
Scanning dependencies of target Ex14
[ 50%] Building C object CMakeFiles/Ex14.dir/Ex14/ex14.c.o
/.../.../Development/Projects/LCTHW/Ex14/ex14.c:13:9: warning: implicit declaration of function 'print_letters' is invalid in C99 [-Wimplicit-function-declaration]
        print_letters(argv[i]);
        ^
/.../.../Development/Projects/LCTHW/Ex14/ex14.c:17:6: error: conflicting types for 'print_letters'
void print_letters(char arg[]) {
     ^
/.../.../Development/Projects/LCTHW/Ex14/ex14.c:13:9: note: previous implicit declaration is here
        print_letters(argv[i]);
        ^
/.../.../Development/Projects/LCTHW/Ex14/ex14.c:24:13: warning: implicit declaration of function 'can_print_it' is invalid in C99 [-Wimplicit-function-declaration]
        if (can_print_it(ch)) {
            ^
/.../.../Development/Projects/LCTHW/Ex14/ex14.c:32:5: error: conflicting types for 'can_print_it'
int can_print_it(char ch) {
    ^
/.../.../Development/Projects/LCTHW/Ex14/ex14.c:24:13: note: previous implicit declaration is here
        if (can_print_it(ch)) {
            ^
2 warnings and 2 errors generated.
make[3]: *** [CMakeFiles/Ex14.dir/Ex14/ex14.c.o] Error 1
make[2]: *** [CMakeFiles/Ex14.dir/all] Error 2
make[1]: *** [CMakeFiles/Ex14.dir/rule] Error 2
make: *** [Ex14] Error 2
```

In researching why these warnings and errors were generated, I am again reminded of C's status as a compiled language -
and, consequently, of that implication as a strength and weakness dependent upon varied application. Further, it occurs
to me that the touted 'portability' of C would necessitate these types of forward declarations as a means of regulating
memory usage. It did not surprise then to find out that these forward declarations were a by-product of the single-pass
compiler behind C, itself a result of constraints of its precursor BCPL.
### When you call ```print_arguments``` inside ```main```, try adding 1 to ```argc``` so that it goes past the end of the ```argv``` array.
Increasing the ```argc``` variable by 1 resulted in the following error:
```
 ➜  ./Ex14
'E' == 69 'x' == 120
Segmentation fault: 11

```
Compiled and run without altering the ```argc``` variable, the result is shown below:
```
 ➜  ./Ex14
'E' == 69 'x' == 120
```
## Extra Credit
### Rework these functions so that you have fewer functions. For example, do you really need ```can_print_it```?
We can, if the check for alpha and blank were a one-time instance, simply remove the function call in this case. If the ```can_print_it``` function were to be accessed multiple times,
I'd advocate for breaking out the code into a utility function for easy reuse.

My modified ```print_letters``` function now looks like this:
```
void print_letters(char arg[]) {

    int i =  0;

    for (i = 0; arg[i] != '\0'; i++) {
        char ch = arg[i];

        if (isalpha(ch) || isblank(ch)) {
            printf("'%c' == %d ", ch, ch);
        }
    }

    printf("\n");
}
```

### Have ```print_arguments``` figure out how long each argument string is by using the ```strlen``` function, and then pass that length to ```print_letters```. Then, rewrite ```print_letters``` so it only processes this fixed length and doesn't rely on the ```'\0'``` terminator. You'll need the ```#include <string.h>``` for this.
TODO: Finish description of process
```
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// forward declarations
void print_letters(char arg[], size_t len);

void print_arguments(int argc, char *argv[]) {

    int i = 0;

    for (i = 0; i < argc; i++) {
        print_letters(argv[i], strlen(argv[i]));
    }

    for (i = 0; i < argc; i++) {
        printf("The arg is '%s' and its length is '%zu'\n", argv[i], strlen(argv[i]));
    }
}

void print_letters(char arg[], size_t len) {

    int i =  0;

    // Without terminator
    for (i = 0; i < len; i++) {
        char ch = arg[i];

        // Removing the function call
        if (isalpha(ch) || isblank(ch)) {
            printf("'%c' == %d ", ch, ch);
        }
    }

    printf("\n");
}

int main(int argc, char *argv[]) {

    print_arguments((argc), argv);

    int i = 0;

    printf("There were %d args passed to the function \n", argc);

    for (i = 0; i < argc; i++) {
        printf("'%s' is the arg", argv[i]);
        printf("\n");
    }
    return 0;
}
```

The output is shown below:
```
 ➜  ./Ex14 dog
'E' == 69 'x' == 120
'd' == 100 'o' == 111 'g' == 103
The arg is './Ex14' and its length is '6'
The arg is 'dog' and its length is '3'
There were 2 args passed to the function
'./Ex14' is the arg
'dog' is the arg
```
### Use ```man``` to look up information on ```isalpha``` and ```isblank```. Use other similar functions to print out only digits or other characters.
### Go read about how other people like to format their functions. Never use the K&R syntax (it's antiquated and confusing) but understand what it's doing in case you run into someone who likes it.

```
 ➜  ./Ex14
'E' == 69 'x' == 120
```

```
 ➜  ./Ex14 Get in da choppa
'E' == 69 'x' == 120
'G' == 71 'e' == 101 't' == 116
'i' == 105 'n' == 110
'd' == 100 'a' == 97
'c' == 99 'h' == 104 'o' == 111 'p' == 112 'p' == 112 'a' == 97
```

