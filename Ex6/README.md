# Exercise 6: Types of Variables
## Extra Credit
### Come up with other ways to break this C code by changing the printf, then fix them.
1. I switched the variable assignment order of ```initial``` and ```first_name```
```
[ 50%] Building C object CMakeFiles/Ex6.dir/Ex6/ex6.c.o
.../Development/Projects/LCTHW/Ex6/ex6.c:18:44: warning: format specifies type 'char *' but the argument has type 'char' [-Wformat]
    printf("My full name is: %s %c %s.\n", initial, first_name, last_name);
                             ~~            ^~~~~~~
                             %c
.../Development/Projects/LCTHW/Ex6/ex6.c:18:53: warning: format specifies type 'int' but the argument has type 'char *' [-Wformat]
    printf("My full name is: %s %c %s.\n", initial, first_name, last_name);
                                ~~                  ^~~~~~~~~~
                                %s
2 warnings generated.
[100%] Linking C executable .../Development/Projects/LCTHW/builds/Debug/Ex6
[100%] Built target Ex6
```

2. Removing an argument from the printf statement and having a string format error (using %c where one should use %s)
```
[ 50%] Building C object CMakeFiles/Ex6.dir/Ex6/ex6.c.o
.../Development/Projects/LCTHW/Ex6/ex6.c:18:56: warning: format specifies type 'int' but the argument has type 'char *' [-Wformat]
    printf("My full name is: %s %c %s.\n", first_name, last_name);
                                ~~                     ^~~~~~~~~
                                %s
.../Development/Projects/LCTHW/Ex6/ex6.c:18:37: warning: more '%' conversions than data arguments [-Wformat]
    printf("My full name is: %s %c %s.\n", first_name, last_name);
                                   ~^
2 warnings generated.
[100%] Linking C executable .../Development/Projects/LCTHW/builds/Debug/Ex6
[100%] Built target Ex6
```

3. Removing 'f' from ```printf```
```
[ 50%] Building C object CMakeFiles/Ex6.dir/Ex6/ex6.c.o
.../Development/Projects/LCTHW/Ex6/ex6.c:12:5: warning: implicit declaration of function 'print' is invalid in C99 [-Wimplicit-function-declaration]
    print("You are %d miles away.\n", distance);
    ^
1 warning generated.
[100%] Linking C executable .../Development/Projects/LCTHW/builds/Debug/Ex6
Undefined symbols for architecture x86_64:
  "_print", referenced from:
      _main in ex6.c.o
ld: symbol(s) not found for architecture x86_64
clang: error: linker command failed with exit code 1 (use -v to see invocation)
make[3]: *** [.../Development/Projects/LCTHW/builds/Debug/Ex6] Error 1
make[2]: *** [CMakeFiles/Ex6.dir/all] Error 2
make[1]: *** [CMakeFiles/Ex6.dir/rule] Error 2
make: *** [Ex6] Error 2
```
4. Using ```%x``` where one should use ```%f```
```
[ 50%] Building C object CMakeFiles/Ex6.dir/Ex6/ex6.c.o
.../Development/Projects/LCTHW/Ex6/ex6.c:13:46: warning: format specifies type 'unsigned int' but the argument has type 'float' [-Wformat]
    printf("You have %x levels of power.\n", power);
                     ~~                      ^~~~~
                     %f
1 warning generated.
[100%] Linking C executable .../Development/Projects/LCTHW/builds/Debug/Ex6
[100%] Built target Ex6
```
### Go search for "printf formats" and try using a few of the more exotic ones.
While the octal, hex, and exponential formats might be 'exotic,' I was also struck by the variety of 'exotic' options
to modify string output. I was unsure of how to best utilize these, and wanted to experiment with the results.

Program input:
```
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
    printf("", empty_str);


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

```
Output:
```
10
    10
10
000010
string
              string
string
str
10.000000
110.011000
110.01
    110.01
110
```

### Research how many different ways you can write a number. Try octal, hexadecimal, and others you can find.
```
printf("%i", 100);    // 100
printf("%i", -100);   // -100
printf("%d", 100);    // 100
printf("%.10d", 100); // 0000000100
```

```
printf("%o", 07);      // 7
printf("%u", 7);       // 7
printf("%x", 0x7);     // 7
printf("%x", 0xFF);    // ff
printf("%X", 0xff);    // FF
printf("%.10X", 0xff); // 00000000FF
```

```
printf("%e", 100.0);    // 1.000000e+02
printf("%.0e", 100.0);  // 1e+02
printf("%.10e", 100.0); // 1.0000000000e+02
```

```
printf("%f", 100.0);    // 100.000000
printf("%.0f", 100.0);  // 100
printf("%.10f", 100.0); // 100.0000000000
```

```
printf("%f\n", 10000000.0); // 10000000.000000
printf("%e\n", 10000000.0); // 1.000000e+07
printf("%g\n", 10000000.0); // 1e+07

printf("%f\n", 0.123456);   // 0.123456
printf("%e\n", 0.123456);   // 1.234560e-01
printf("%g\n", 0.123456);   // 0.123456
```

### Try printing an empty string that's just "".
Though the build was successful, a warning was raised:

```
[ 50%] Building C object CMakeFiles/Ex6.dir/Ex6/ex6.c.o
.../Development/Projects/LCTHW/Ex6/ex6.c:14:46: warning: format specifies type 'unsigned int' but the argument has type 'float' [-Wformat]
    printf("You have %x levels of power.\n", power);
                     ~~                      ^~~~~
                     %f
.../Development/Projects/LCTHW/Ex6/ex6.c:20:12: warning: format string is empty [-Wformat-zero-length]
    printf("", empty_str);
           ^~
2 warnings generated.
[100%] Linking C executable .../Development/Projects/LCTHW/builds/Debug/Ex6
[100%] Built target Ex6
```