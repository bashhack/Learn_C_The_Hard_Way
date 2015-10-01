# Exercise 9: Arrays and Strings
## How to Break It
### Get rid of the initializers that setup ```name```.
I ran the program having commented out the following:

- the first initializer ```{'a'}```
- the individual initializer values at each index of the name array

Checking the Valgrind output, there were certainly errors:
```
 ➜  valgrind ./Ex9
==19730== Memcheck, a memory error detector
==19730== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==19730== Using Valgrind-3.11.0.SVN and LibVEX; rerun with -h for copyright info
==19730== Command: ./Ex9
==19730==
--19730-- run: /usr/bin/dsymutil "./Ex9"
numbers: 0 0 0 0
==19730== Conditional jump or move depends on uninitialised value(s)
==19730==    at 0x10000A121: _platform_memchr$VARIANT$Haswell (in /usr/local/Cellar/valgrind/HEAD/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==19730==    by 0x1001CF9F6: __sfvwrite (in /usr/lib/system/libsystem_c.dylib)
==19730==    by 0x1001D9E45: __vfprintf (in /usr/lib/system/libsystem_c.dylib)
==19730==    by 0x1001FF80E: __v2printf (in /usr/lib/system/libsystem_c.dylib)
==19730==    by 0x1001FFAE0: __xvprintf (in /usr/lib/system/libsystem_c.dylib)
==19730==    by 0x1001D59D1: vfprintf_l (in /usr/lib/system/libsystem_c.dylib)
==19730==    by 0x1001D3837: printf (in /usr/lib/system/libsystem_c.dylib)
==19730==    by 0x100000DA8: main (ex9.c:12)
==19730==
==19730== Syscall param write(buf) points to uninitialised byte(s)
==19730==    at 0x1002DA97A: write$NOCANCEL (in /usr/lib/system/libsystem_kernel.dylib)
==19730==    by 0x1001D484C: _swrite (in /usr/lib/system/libsystem_c.dylib)
==19730==    by 0x1001CD306: __sflush (in /usr/lib/system/libsystem_c.dylib)
==19730==    by 0x1001CFAB0: __sfvwrite (in /usr/lib/system/libsystem_c.dylib)
==19730==    by 0x1001D9ECC: __vfprintf (in /usr/lib/system/libsystem_c.dylib)
==19730==    by 0x1001FF80E: __v2printf (in /usr/lib/system/libsystem_c.dylib)
==19730==    by 0x1001FFAE0: __xvprintf (in /usr/lib/system/libsystem_c.dylib)
==19730==    by 0x1001D59D1: vfprintf_l (in /usr/lib/system/libsystem_c.dylib)
==19730==    by 0x1001D3837: printf (in /usr/lib/system/libsystem_c.dylib)
==19730==    by 0x100000DA8: main (ex9.c:12)
==19730==  Address 0x100801836 is 6 bytes inside a block of size 4,096 alloc'd
==19730==    at 0x10000845B: malloc (in /usr/local/Cellar/valgrind/HEAD/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==19730==    by 0x1001D0696: __smakebuf (in /usr/lib/system/libsystem_c.dylib)
==19730==    by 0x1001E51E7: __swsetup (in /usr/lib/system/libsystem_c.dylib)
==19730==    by 0x1001FF5BD: __v2printf (in /usr/lib/system/libsystem_c.dylib)
==19730==    by 0x1001FFAE0: __xvprintf (in /usr/lib/system/libsystem_c.dylib)
==19730==    by 0x1001D59D1: vfprintf_l (in /usr/lib/system/libsystem_c.dylib)
==19730==    by 0x1001D3837: printf (in /usr/lib/system/libsystem_c.dylib)
==19730==    by 0x100000D81: main (ex9.c:9)
==19730==
name:
numbers: 1 2 3 4
name:
==19730== Conditional jump or move depends on uninitialised value(s)
==19730==    at 0x100009C78: strlen (in /usr/local/Cellar/valgrind/HEAD/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==19730==    by 0x1001D6D61: __vfprintf (in /usr/lib/system/libsystem_c.dylib)
==19730==    by 0x1001FF80E: __v2printf (in /usr/lib/system/libsystem_c.dylib)
==19730==    by 0x1001FFAE0: __xvprintf (in /usr/lib/system/libsystem_c.dylib)
==19730==    by 0x1001D59D1: vfprintf_l (in /usr/lib/system/libsystem_c.dylib)
==19730==    by 0x1001D3837: printf (in /usr/lib/system/libsystem_c.dylib)
==19730==    by 0x100000E1E: main (ex9.c:36)
==19730==
name:
another: Laughton
another each: L a u g h t o n
==19730==
==19730== HEAP SUMMARY:
==19730==     in use at exit: 38,732 bytes in 417 blocks
==19730==   total heap usage: 512 allocs, 95 frees, 45,572 bytes allocated
==19730==
==19730== LEAK SUMMARY:
==19730==    definitely lost: 0 bytes in 0 blocks
==19730==    indirectly lost: 0 bytes in 0 blocks
==19730==      possibly lost: 0 bytes in 0 blocks
==19730==    still reachable: 0 bytes in 0 blocks
==19730==         suppressed: 38,732 bytes in 417 blocks
==19730==
==19730== For counts of detected and suppressed errors, rerun with: -v
==19730== Use --track-origins=yes to see where uninitialised values come from
==19730== ERROR SUMMARY: 12 errors from 3 contexts (suppressed: 0 from 0)
```
### Accidentally set ```name[3] = 'A';``` so that there's no terminator.
While the program built and Valgrind did not present any errors in its summary, the output was not was I expected:

```
 ➜  valgrind ./Ex9
==19803== Memcheck, a memory error detector
==19803== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==19803== Using Valgrind-3.11.0.SVN and LibVEX; rerun with -h for copyright info
==19803== Command: ./Ex9
==19803==
--19803-- run: /usr/bin/dsymutil "./Ex9"
numbers: 0 0 0 0
name: a
numbers: 1 2 3 4
name: M a r c
name: MarcA'�
another: Laughton
another each: L a u g h t o n
==19803==
==19803== HEAP SUMMARY:
==19803==     in use at exit: 38,732 bytes in 417 blocks
==19803==   total heap usage: 512 allocs, 95 frees, 45,572 bytes allocated
==19803==
==19803== LEAK SUMMARY:
==19803==    definitely lost: 0 bytes in 0 blocks
==19803==    indirectly lost: 0 bytes in 0 blocks
==19803==      possibly lost: 0 bytes in 0 blocks
==19803==    still reachable: 0 bytes in 0 blocks
==19803==         suppressed: 38,732 bytes in 417 blocks
==19803==
==19803== For counts of detected and suppressed errors, rerun with: -v
==19803== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

Without the terminator, the program ran and placed a random string of characters in its place.

CMake gave a more accurate overview of the mistake, flagging a warning:
```
[ 50%] Building C object CMakeFiles/Ex9.dir/Ex9/ex9.c.o
.../.../Development/Projects/LCTHW/Ex9/ex9.c:33:48: warning: data argument not used by format string [-Wformat-extra-args]
           name[0], name[1], name[2], name[3], name[4]);
                                               ^
1 warning generated.
```
### Set the initializer to ```{'a','a','a','a'}``` so there's too many 'a' characters and no space for the ```'\0'``` terminator.
Adding an extra array initializer immediately made CMake generate a warning:

```
[ 50%] Building C object CMakeFiles/Ex9.dir/Ex9/ex9.c.o
.../.../Development/Projects/LCTHW/Ex9/ex9.c:6:46: warning: excess elements in array initializer
    char name[5] = {'a', 'a', 'a', 'a', 'a', 'a'};
                                             ^~~
.../.../Development/Projects/LCTHW/Ex9/ex9.c:33:48: warning: data argument not used by format string [-Wformat-extra-args]
           name[0], name[1], name[2], name[3], name[4]);
                                               ^
2 warnings generated.
```
## Extra Credit
### Assign the characters into ```numbers``` and then use ```printf``` to print them a character at a time. What kind of compiler warnings did you get?
Neither CMake nor Valgrind threw errors or gave warnings, though the output was certainly unexpected:
```
numbers: 77 97 114 99
```
The input values given were:
```
int main(int argc, char *argv[]) {

    int numbers[4] = {0};

    // setup the numbers
    numbers[0] = 'M';
    numbers[1] = 'a';
    numbers[2] = 'r';
    numbers[3] = 'c';

    // print them out initialized
    printf("numbers: %d %d %d %d\n",
           numbers[0], numbers[1], numbers[2], numbers[3]);

    return 0;
}
```
### Do the inverse for ```name```, trying to treat it like an array of ```int``` and print it out one ```int``` at a time. What does Valgrind think of that?
Again, neither Valgrind nor CMake gave pause, and instead compiled the program substituting the output with the following:
```
name: ���Z�
```

Wondering if this may have been a result of the behavior of the terminal panel within my IDE (CLion), I ran the program in the Bash shell environment in Terminal and received the same result.
### If an array of characters is 4 bytes long, and an integer is 4 bytes long, then can you treat the whole ```name``` array like it's just an integer? How might you accomplish this crazy hack?
Here, we're dealing with a classic question of big vs little endianness, which - ironically, shouldn't affect or matter with C-style strings, as ASCII characters.

Nonetheless, the essential idea behind big vs little endianness comes from how we talk about and understand memory allocation. I found some great research from IBM developer documentation on the subject, finding it very clear:

For the following, we imagine that we have a 32-bit entity, ```64 6f 67``` (hexidecimal representation of the English word 'dog').

In a big-endian assignment, the most significant value is inserted at memory address 1000 and goes from biggest to smallest significance as we work our way up the index position in memory.

```
Big-Endian Example:

1000 - 64
1001 - 6f
1002 - 67
```

The reverse is true for the little-endian assignment:
```
Little-Endian Example:

1000 - 67
1001 - 6f
1002 - 64
```

To jump ahead a little bit, to the next Extra Credit assignment, I drew out the arrays first, which helped.

```
++++++++++++++++++++++++++++++++
+  [N1] + [N2] + [N3] + [N4] + +
++++++++++++++++++++++++++++++++
```

Here, we have our 4 byte array visualized with 4 elements (N). Since 4 bytes is also 32 bits, I then divided 32 bits by 4 bytes, giving me the maximum possible value for each N element as 8 bits.

We could then further extrapolate this into code by doing something like the following:
```
#include <stdio.h>

int main(int argc, char *argv[]) {

    // Init
    char nameString[4] = {'a'};
    int name = 0;

    for (int i = 0; i < 4; ++i) {

        // Utilize bitwise operator
        name = (name << 8) + nameString[i];
    }

    // Signed int
    printf("%d\n", name);
    // Unsigned hex
    printf("%X\n", name);

    return 0;
}

// Result is 1627389952 and 61000000, respectively.
```
### Take out a piece of paper and draw out each of these arrays as a row of boxes. Then do the operations you just did on paper to see if you get them right.
See above, where it is drawn out and explained.
### Convert ```name``` to be in the style of ```another``` and see if the code keeps working.
The program I wrote is shown below:
```
#include <stdio.h>

int main(int argc, char *argv[]) {

    /*
     * Convert name variable to the style of 'another'
     */
    char *name2 = "Marc";

    printf("The value of name2 is: %s\n", name2);

    return 0;
};
```

Running the program above generated the following:
```
The value of name2 is: Marc

Process finished with exit code 0
```

The results from the Valgrind test suite presented no errors:
```
 ➜  valgrind ./Ex9
==22238== Memcheck, a memory error detector
==22238== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==22238== Using Valgrind-3.11.0.SVN and LibVEX; rerun with -h for copyright info
==22238== Command: ./Ex9
==22238==
--22238-- run: /usr/bin/dsymutil "./Ex9"
The value of name2 is: Marc
==22238==
==22238== HEAP SUMMARY:
==22238==     in use at exit: 38,732 bytes in 417 blocks
==22238==   total heap usage: 512 allocs, 95 frees, 45,572 bytes allocated
==22238==
==22238== LEAK SUMMARY:
==22238==    definitely lost: 0 bytes in 0 blocks
==22238==    indirectly lost: 0 bytes in 0 blocks
==22238==      possibly lost: 0 bytes in 0 blocks
==22238==    still reachable: 0 bytes in 0 blocks
==22238==         suppressed: 38,732 bytes in 417 blocks
==22238==
==22238== For counts of detected and suppressed errors, rerun with: -v
==22238== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```