# Exercise 3: Formatted Printing
## Extra Credit
### Find as many other ways to break ex3.c as you can.
1. Init variable age without value assignment, resulting compiled value is a nasal demon (per Usenet parlance)
```
I am 1612554294 years old
I am 75 inches tall

Process finished with exit code 0
```
2. Created, assigned, and used in printf statement a variable age without first declaring its type.
```
/Users/marclaughton/Development/Projects/LCTHW/Ex3/ex3.c:4:5: error: use of undeclared identifier 'age'
    age = 10;
    ^
/Users/marclaughton/Development/Projects/LCTHW/Ex3/ex3.c:7:35: error: use of undeclared identifier 'age'
    printf("I am %d years old\n", age);
                                  ^
2 errors generated.
make[3]: *** [CMakeFiles/Ex3.dir/Ex3/ex3.c.o] Error 1
make[2]: *** [CMakeFiles/Ex3.dir/all] Error 2
make[1]: *** [CMakeFiles/Ex3.dir/rule] Error 2
make: *** [Ex3] Error 2
```
3. Assigned value to typed, unnamed variable and used type designator in printf statement.
```
/Users/marclaughton/Development/Projects/LCTHW/Ex3/ex3.c:5:9: error: expected identifier or '('
    int = 75;
        ^
/Users/marclaughton/Development/Projects/LCTHW/Ex3/ex3.c:8:37: error: expected expression
    printf("I am %d inches tall\n", int);
                                    ^
2 errors generated.
make[3]: *** [CMakeFiles/Ex3.dir/Ex3/ex3.c.o] Error 1
make[2]: *** [CMakeFiles/Ex3.dir/all] Error 2
make[1]: *** [CMakeFiles/Ex3.dir/rule] Error 2
make: *** [Ex3] Error 2
```
4. Created discrepancy in the spelling of the variable 'height'
```
/Users/marclaughton/Development/Projects/LCTHW/Ex3/ex3.c:8:37: error: use of undeclared identifier 'hight'; did you mean 'height'?
    printf("I am %d inches tall\n", hight);
                                    ^~~~~
                                    height
/Users/marclaughton/Development/Projects/LCTHW/Ex3/ex3.c:5:9: note: 'height' declared here
    int height = 75;
        ^
1 error generated.
make[3]: *** [CMakeFiles/Ex3.dir/Ex3/ex3.c.o] Error 1
make[2]: *** [CMakeFiles/Ex3.dir/all] Error 2
make[1]: *** [CMakeFiles/Ex3.dir/rule] Error 2
make: *** [Ex3] Error 2
```

### Run `man 3 printf` and read about the other '%' format characters you can use. These should look familiar if you used them in other languages (printf is where they come from).
```
#include <stdio.h>
#include <errno.h>

int main() {
    char my_char = 'm';
    int my_int = -29;
    double my_double = 234567.574635;
    float my_float = 3.45;
    char my_string[] = "Marc";
    unsigned int my_unsigned_int = 74;


    printf("Single character: %c\n", my_char);
    printf("Integer: %d\n", my_int);
    printf("Double, exponential notation: %e\n", my_double);
    printf("Double, exponential notation (with capital 'E'): %E\n", my_double);
    printf("Floating-point: %f\n", my_float);
    printf("Another method of formating with integer: %i\n", my_int);

    errno = EACCES;
    printf("errno string (EACCES): %m\n");
    printf("String: %s\n", my_string);
    printf("Unsigned integer: %u\n", my_unsigned_int);
    printf("Hexadecimal notation: %x\n", my_int);
    printf("Hexadecimal notation (all capitalized): %X\n", my_unsigned_int);
    printf("This prints the percentage symbol: %%\n");

    return 0;
}
```
Result Output:
```
Single character: m
Integer: -29
Double, exponential notation: 2.345676e+05
Double, exponential notation (with capital 'E'): 2.345676E+05
Floating-point: 3.450000
Another method of formating with integer: -29
errno string (EACCES): Permission denied
String: Marc
Unsigned integer: 74
Hexadecimal notation: ffffffe3
Hexadecimal notation (all capitalized): 4A
This prints the percentage symbol: %

Process finished with exit code 0
```

### Add ex3 to your Makefile's `all` list. Use this to make clean all and build all your exercises so far.
```
CFLAGS = -Wall -g -std=c99

all: ex1 ex2 ex3

clean:
		rm -f ex1 ex2
```
### Add ex3 to your Makefile's `clean` list as well. Now use make clean will remove it when you need to.
```
CFLAGS = -Wall -g -std=c99

all: ex1 ex2 ex3

clean:
		rm -f ex1 ex2 ex3
```