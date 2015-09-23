# Exercise 8: Sizes and Arrays
## How to Break It
### Get rid of the ```'\0'``` at the end of ```full_name``` and re-run it. Run it under Valgrind too. Now, move the definition of ```full_name``` to the top of ```main``` before ```areas```. Try running it under Valgrind a few times and see if you get some new errors. In some cases, you might still get lucky and not catch any errors.
Initially, I may have misunderstood the directions, as I removed the ```\0```, with the surrounding single-quotes out of habit. Of course, running this through Valgrind presented no errors:
```
 ➜  valgrind ./Ex8
==12113== Memcheck, a memory error detector
==12113== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==12113== Using Valgrind-3.11.0.SVN and LibVEX; rerun with -h for copyright info
==12113== Command: ./Ex8
==12113==
--12113-- run: /usr/bin/dsymutil "./Ex8"
The size of an int: 4
The size of areas (int[]): 20
The number of ints in areas: 5
The first area is 10, the second area is 12,
The size of a char: 1
The size of name (char[]): 5
The number of chars: 5
The size of full_name (char[]): 16
The number of chars: 16
name = "Marc" and full name = "Marc W. Laughton
"
==12113==
==12113== HEAP SUMMARY:
==12113==     in use at exit: 38,653 bytes in 417 blocks
==12113==   total heap usage: 512 allocs, 95 frees, 45,493 bytes allocated
==12113==
==12113== LEAK SUMMARY:
==12113==    definitely lost: 0 bytes in 0 blocks
==12113==    indirectly lost: 0 bytes in 0 blocks
==12113==      possibly lost: 0 bytes in 0 blocks
==12113==    still reachable: 0 bytes in 0 blocks
==12113==         suppressed: 38,653 bytes in 417 blocks
==12113==
==12113== For counts of detected and suppressed errors, rerun with: -v
==12113== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

Running the program a second time, leaving the single-quotations did produce a build error, reported by Valgrind below:
```
[ 50%] Building C object CMakeFiles/Ex8.dir/Ex8/ex8.c.o
.../Development/Projects/LCTHW/Ex8/ex8.c:7:105: warning: empty character constant [-Winvalid-pp-token]
    char full_name[] = {'M', 'a', 'r', 'c', ' ', 'W', '.', ' ', 'L', 'a', 'u', 'g', 'h', 't', 'o', 'n', ''};
                                                                                                        ^
.../Development/Projects/LCTHW/Ex8/ex8.c:7:105: error: expected expression
.../Development/Projects/LCTHW/Ex8/ex8.c:18:59: error: invalid application of 'sizeof' to an incomplete type 'char []'
    printf("The size of full_name (char[]): %ld\n", sizeof(full_name));
                                                          ^~~~~~~~~~~
.../Development/Projects/LCTHW/Ex8/ex8.c:19:49: error: invalid application of 'sizeof' to an incomplete type 'char []'
    printf("The number of chars: %ld\n", (sizeof(full_name) / sizeof(char)));
                                                ^~~~~~~~~~~
1 warning and 3 errors generated.
make[3]: *** [CMakeFiles/Ex8.dir/Ex8/ex8.c.o] Error 1
make[2]: *** [CMakeFiles/Ex8.dir/all] Error 2
make[1]: *** [CMakeFiles/Ex8.dir/rule] Error 2
make: *** [Ex8] Error 2
```

Moving the variable ```full_name``` above areas did not produce any errors in Valgrind, fortunately?
### Change it so that instead of ```areas[0]``` you try to print ```areas[10]``` and see what Valgrind thinks of that.
Imagining that C functions similarly to those in Python and Javascript, accessing an index outside of bounds should result in an error.
My expectation was that there would be an error (as with an Index out of Range or undefined, Python and Javascript respectively).

The Valgrind result is below:
```
 ➜  valgrind ./Ex8 -v
==12366== Memcheck, a memory error detector
==12366== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==12366== Using Valgrind-3.11.0.SVN and LibVEX; rerun with -h for copyright info
==12366== Command: ./Ex8 -v
==12366==
The size of an int: 4
The size of areas (int[]): 20
The number of ints in areas: 5
The first area is 1299913, the second area is 12,
The size of a char: 1
The size of name (char[]): 5
The number of chars: 5
The size of full_name (char[]): 17
The number of chars: 17
name = "Marc" and full name = "Marc W. Laughton"
==12366==
==12366== HEAP SUMMARY:
==12366==     in use at exit: 38,653 bytes in 417 blocks
==12366==   total heap usage: 512 allocs, 95 frees, 45,493 bytes allocated
==12366==
==12366== LEAK SUMMARY:
==12366==    definitely lost: 0 bytes in 0 blocks
==12366==    indirectly lost: 0 bytes in 0 blocks
==12366==      possibly lost: 0 bytes in 0 blocks
==12366==    still reachable: 0 bytes in 0 blocks
==12366==         suppressed: 38,653 bytes in 417 blocks
==12366==
==12366== For counts of detected and suppressed errors, rerun with: -v
==12366== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

To my surprise, the compiler built the program and substituted a random number in place of the out of bounds array index.
Its a valuable lesson in (1) paying attention to any build errors or warnings, (2) realizing that bugs may not be obvious, and (3) that
 the compiler's default behavior necessitates pragmatic coding no matter the program.

The results of the CMake build-process below:
```
[ 50%] Building C object CMakeFiles/Ex8.dir/Ex8/ex8.c.o
.../Development/Projects/LCTHW/Ex8/ex8.c:12:62: warning: array index 10 is past the end of the array (which contains 5 elements) [-Warray-bounds]
    printf("The first area is %d, the second area is %d,\n", areas[10], areas[1]);
                                                             ^     ~~
.../Development/Projects/LCTHW/Ex8/ex8.c:5:5: note: array 'areas' declared here
    int areas[] = {10, 12, 13, 14, 20};
    ^
1 warning generated.
[100%] Linking C executable .../Development/Projects/LCTHW/builds/Debug/Ex8
[100%] Built target Ex8
```
### Try other versions of these, doing it to name and full_name too.
I attempted to access an index within and without of bounds for the ```name``` and ```full_name```.
```
#include <stdio.h>

int main(int argc, char *argv[]) {

    int areas[] = {10, 12, 13, 14, 20};
    char name[] = "Marc";
    char full_name[] = {'M', 'a', 'r', 'c', ' ', 'W', '.', ' ', 'L', 'a', 'u', 'g', 'h', 't', 'o', 'n', '\0'};

    printf("The size of an int: %ld\n", sizeof(int));
    printf("The size of areas (int[]): %ld\n", sizeof(areas));
    printf("The number of ints in areas: %ld\n", (sizeof(areas) / sizeof(int)));
    printf("The first area is %d, the second area is %d,\n", areas[10], areas[1]);

    printf("The size of a char: %ld\n", sizeof(char));
    printf("The size of name (char[]): %ld\n", sizeof(name));
    printf("The number of chars: %ld\n", (sizeof(name) / sizeof(char)));

    printf("The size of full_name (char[]): %ld\n", sizeof(full_name));
    printf("The number of chars: %ld\n", (sizeof(full_name) / sizeof(char)));

    printf("name = \"%s\" and full name = \"%s\"\n", name, full_name);

    printf("The first third character of name (char[]) is: %c\n", name[2]);
    printf("The result of accessing an index outside of bounds in name (char[]) is: %c\n", name[50]);

    printf("The ninth character of name (char[]) is: %c\n", full_name[8]);
    printf("The result of accessing an index outside of bounds in name (char[]) is: %c\n", full_name[50]);

    return 0;

}
```

The results of CMake:
```
[ 50%] Building C object CMakeFiles/Ex8.dir/Ex8/ex8.c.o
.../Development/Projects/LCTHW/Ex8/ex8.c:12:62: warning: array index 10 is past the end of the array (which contains 5 elements) [-Warray-bounds]
    printf("The first area is %d, the second area is %d,\n", areas[10], areas[1]);
                                                             ^     ~~
.../Development/Projects/LCTHW/Ex8/ex8.c:5:5: note: array 'areas' declared here
    int areas[] = {10, 12, 13, 14, 20};
    ^
.../Development/Projects/LCTHW/Ex8/ex8.c:24:92: warning: array index 50 is past the end of the array (which contains 5 elements) [-Warray-bounds]
    printf("The result of accessing an index outside of bounds in name (char[]) is: %c\n", name[50]);
                                                                                           ^    ~~
.../Development/Projects/LCTHW/Ex8/ex8.c:6:5: note: array 'name' declared here
    char name[] = "Marc";
    ^
.../Development/Projects/LCTHW/Ex8/ex8.c:27:92: warning: array index 50 is past the end of the array (which contains 17 elements) [-Warray-bounds]
    printf("The result of accessing an index outside of bounds in name (char[]) is: %c\n", full_name[50]);
                                                                                           ^         ~~
.../Development/Projects/LCTHW/Ex8/ex8.c:7:5: note: array 'full_name' declared here
    char full_name[] = {'M', 'a', 'r', 'c', ' ', 'W', '.', ' ', 'L', 'a', 'u', 'g', 'h', 't', 'o', 'n', '\0'};
    ^
3 warnings generated.
[100%] Linking C executable .../Development/Projects/LCTHW/builds/Debug/Ex8
[100%] Built target Ex8
```

I also tested the executable against Valgrind:
```
 ➜  valgrind ./Ex8 -v
==12946== Memcheck, a memory error detector
==12946== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==12946== Using Valgrind-3.11.0.SVN and LibVEX; rerun with -h for copyright info
==12946== Command: ./Ex8 -v
==12946==
--12946-- run: /usr/bin/dsymutil "./Ex8"
The size of an int: 4
The size of areas (int[]): 20
The number of ints in areas: 5
The first area is 1299913, the second area is 12,
The size of a char: 1
The size of name (char[]): 5
The number of chars: 5
The size of full_name (char[]): 17
The number of chars: 17
name = "Marc" and full name = "Marc W. Laughton"
The first third character of name (char[]) is: r
==12946== Conditional jump or move depends on uninitialised value(s)
==12946==    at 0x10000A121: _platform_memchr$VARIANT$Haswell (in /usr/local/Cellar/valgrind/HEAD/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==12946==    by 0x1001CF9F6: __sfvwrite (in /usr/lib/system/libsystem_c.dylib)
==12946==    by 0x1001D9E45: __vfprintf (in /usr/lib/system/libsystem_c.dylib)
==12946==    by 0x1001FF80E: __v2printf (in /usr/lib/system/libsystem_c.dylib)
==12946==    by 0x1001FFAE0: __xvprintf (in /usr/lib/system/libsystem_c.dylib)
==12946==    by 0x1001D59D1: vfprintf_l (in /usr/lib/system/libsystem_c.dylib)
==12946==    by 0x1001D3837: printf (in /usr/lib/system/libsystem_c.dylib)
==12946==    by 0x100000CFA: main (ex8.c:24)
==12946==
==12946== Syscall param write(buf) points to uninitialised byte(s)
==12946==    at 0x1002DA97A: write$NOCANCEL (in /usr/lib/system/libsystem_kernel.dylib)
==12946==    by 0x1001D484C: _swrite (in /usr/lib/system/libsystem_c.dylib)
==12946==    by 0x1001CD306: __sflush (in /usr/lib/system/libsystem_c.dylib)
==12946==    by 0x1001CFAB0: __sfvwrite (in /usr/lib/system/libsystem_c.dylib)
==12946==    by 0x1001D9ECC: __vfprintf (in /usr/lib/system/libsystem_c.dylib)
==12946==    by 0x1001FF80E: __v2printf (in /usr/lib/system/libsystem_c.dylib)
==12946==    by 0x1001FFAE0: __xvprintf (in /usr/lib/system/libsystem_c.dylib)
==12946==    by 0x1001D59D1: vfprintf_l (in /usr/lib/system/libsystem_c.dylib)
==12946==    by 0x1001D3837: printf (in /usr/lib/system/libsystem_c.dylib)
==12946==    by 0x100000CFA: main (ex8.c:24)
==12946==  Address 0x100801828 is 72 bytes inside a block of size 4,096 alloc'd
==12946==    at 0x10000845B: malloc (in /usr/local/Cellar/valgrind/HEAD/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==12946==    by 0x1001D0696: __smakebuf (in /usr/lib/system/libsystem_c.dylib)
==12946==    by 0x1001E51E7: __swsetup (in /usr/lib/system/libsystem_c.dylib)
==12946==    by 0x1001FF5BD: __v2printf (in /usr/lib/system/libsystem_c.dylib)
==12946==    by 0x1001FFAE0: __xvprintf (in /usr/lib/system/libsystem_c.dylib)
==12946==    by 0x1001D59D1: vfprintf_l (in /usr/lib/system/libsystem_c.dylib)
==12946==    by 0x1001D3837: printf (in /usr/lib/system/libsystem_c.dylib)
==12946==    by 0x100000BF5: main (ex8.c:9)
==12946==
The result of accessing an index outside of bounds in name (char[]) is:
The ninth character of name (char[]) is: L
The result of accessing an index outside of bounds in name (char[]) is:
==12946==
==12946== HEAP SUMMARY:
==12946==     in use at exit: 38,653 bytes in 417 blocks
==12946==   total heap usage: 512 allocs, 95 frees, 45,493 bytes allocated
==12946==
==12946== LEAK SUMMARY:
==12946==    definitely lost: 0 bytes in 0 blocks
==12946==    indirectly lost: 0 bytes in 0 blocks
==12946==      possibly lost: 0 bytes in 0 blocks
==12946==    still reachable: 0 bytes in 0 blocks
==12946==         suppressed: 38,653 bytes in 417 blocks
==12946==
==12946== For counts of detected and suppressed errors, rerun with: -v
==12946== Use --track-origins=yes to see where uninitialised values come from
==12946== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)
```
## Extra Credit
### Try assigning to elements in the ```areas``` array with ```areas[0] = 100```; and similar.
The simple input:
```
areas[0] = 100;
areas[1] = 111;
printf("The new value at the 0th index of the areas array is: %d\n", areas[0]);
printf("The new value at the 1st index of the areas array is: %d\n", areas[1]);
```

The resulting output:
```
The new value at the 0th index of the areas array is: 100
The new value at the 1st index of the areas array is: 111
```
### Try assigning to elements of name and full_name.
I gave new character values to the elements/indexes of name and full_name:
```
name[0] = 'C';
printf("It's Marc with a 'C' he told the Starbucks barista and they wrote: '%s'\n", name);
name[1] = 'K';
printf("I alway have to tell people it's 'M-A-R-C', not 'M-A-R-%c.'\n", name[1]);
```

The resulting output:
```
It's Marc with a 'C' he told the Starbucks barista and they wrote: 'Carc'
I alway have to tell people it's 'M-A-R-C', not 'M-A-R-K.'
```
### Try setting one element of areas to a character from name.
The input:
```
areas[1] = name[0];
printf("The assigned value of 'areas[1]' is now: %d\n"
               "This appears to be the Unicode value of 'C,' which is 67.", areas[1]);
```

The output:
```
The assigned value of 'areas[1]' is now: 67
This appears to be the Unicode value of 'C,' which is 67.
```
### Go search online for the different sizes used for integers on different CPUs.
The size of ```int``` on 32-bit system architecture is ```4``` bytes, and ```8``` bytes on 64-bit system architecture.