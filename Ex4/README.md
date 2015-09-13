# Exercise 4: Introducing Valgrind
## Extra Credit
### Fix this program using Valgrind and the compiler as your guide.
NOTE: I also ran additional compiling checks via CMake, and wanted to compare the resulting output with that of Valgrind.

When building via CMake, I came across the following (to be expected, of course):

```
[ 50%] Building C object CMakeFiles/Ex4.dir/Ex4/ex4.c.o
../Development/Projects/LCTHW/Ex4/ex4.c:9:19: warning: more '%' conversions than data arguments [-Wformat]
    printf("I am %d years old.\n");
                 ~^
1 warning generated.
[100%] Linking C executable ../Development/Projects/LCTHW/builds/Debug/Ex4
[100%] Built target Ex4
```

When checking the executable against Valgrind, I received the following output:

```
 ➜  valgrind ./Ex4
==1866== Memcheck, a memory error detector
==1866== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==1866== Using Valgrind-3.11.0.SVN and LibVEX; rerun with -h for copyright info
==1866== Command: ./Ex4
==1866==
--1866-- run: /usr/bin/dsymutil "./Ex4"
I am 75507600 years old.
==1866== Conditional jump or move depends on uninitialised value(s)
==1866==    at 0x1001D7851: __vfprintf (in /usr/lib/system/libsystem_c.dylib)
==1866==    by 0x1001FF80E: __v2printf (in /usr/lib/system/libsystem_c.dylib)
==1866==    by 0x1001FFAE0: __xvprintf (in /usr/lib/system/libsystem_c.dylib)
==1866==    by 0x1001D59D1: vfprintf_l (in /usr/lib/system/libsystem_c.dylib)
==1866==    by 0x1001D3837: printf (in /usr/lib/system/libsystem_c.dylib)
==1866==    by 0x100000F47: main (ex4.c:10)
==1866==
==1866== Conditional jump or move depends on uninitialised value(s)
==1866==    at 0x1001D797B: __vfprintf (in /usr/lib/system/libsystem_c.dylib)
==1866==    by 0x1001FF80E: __v2printf (in /usr/lib/system/libsystem_c.dylib)
==1866==    by 0x1001FFAE0: __xvprintf (in /usr/lib/system/libsystem_c.dylib)
==1866==    by 0x1001D59D1: vfprintf_l (in /usr/lib/system/libsystem_c.dylib)
==1866==    by 0x1001D3837: printf (in /usr/lib/system/libsystem_c.dylib)
==1866==    by 0x100000F47: main (ex4.c:10)
==1866==
==1866== Conditional jump or move depends on uninitialised value(s)
==1866==    at 0x1001DA3B5: __ultoa (in /usr/lib/system/libsystem_c.dylib)
==1866==    by 0x1001D79BE: __vfprintf (in /usr/lib/system/libsystem_c.dylib)
==1866==    by 0x1001FF80E: __v2printf (in /usr/lib/system/libsystem_c.dylib)
==1866==    by 0x1001FFAE0: __xvprintf (in /usr/lib/system/libsystem_c.dylib)
==1866==    by 0x1001D59D1: vfprintf_l (in /usr/lib/system/libsystem_c.dylib)
==1866==    by 0x1001D3837: printf (in /usr/lib/system/libsystem_c.dylib)
==1866==    by 0x100000F47: main (ex4.c:10)
==1866==
==1866== Conditional jump or move depends on uninitialised value(s)
==1866==    at 0x10000A121: _platform_memchr$VARIANT$Haswell (in /usr/local/Cellar/valgrind/HEAD/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==1866==    by 0x1001CF9F6: __sfvwrite (in /usr/lib/system/libsystem_c.dylib)
==1866==    by 0x1001D9E45: __vfprintf (in /usr/lib/system/libsystem_c.dylib)
==1866==    by 0x1001FF80E: __v2printf (in /usr/lib/system/libsystem_c.dylib)
==1866==    by 0x1001FFAE0: __xvprintf (in /usr/lib/system/libsystem_c.dylib)
==1866==    by 0x1001D59D1: vfprintf_l (in /usr/lib/system/libsystem_c.dylib)
==1866==    by 0x1001D3837: printf (in /usr/lib/system/libsystem_c.dylib)
==1866==    by 0x100000F47: main (ex4.c:10)
==1866==
==1866== Syscall param write(buf) points to uninitialised byte(s)
==1866==    at 0x1002DA97A: write$NOCANCEL (in /usr/lib/system/libsystem_kernel.dylib)
==1866==    by 0x1001D484C: _swrite (in /usr/lib/system/libsystem_c.dylib)
==1866==    by 0x1001CD306: __sflush (in /usr/lib/system/libsystem_c.dylib)
==1866==    by 0x1001CFAB0: __sfvwrite (in /usr/lib/system/libsystem_c.dylib)
==1866==    by 0x1001D9ECC: __vfprintf (in /usr/lib/system/libsystem_c.dylib)
==1866==    by 0x1001FF80E: __v2printf (in /usr/lib/system/libsystem_c.dylib)
==1866==    by 0x1001FFAE0: __xvprintf (in /usr/lib/system/libsystem_c.dylib)
==1866==    by 0x1001D59D1: vfprintf_l (in /usr/lib/system/libsystem_c.dylib)
==1866==    by 0x1001D3837: printf (in /usr/lib/system/libsystem_c.dylib)
==1866==    by 0x100000F47: main (ex4.c:10)
==1866==  Address 0x1008017e5 is 5 bytes inside a block of size 4,096 alloc'd
==1866==    at 0x10000845B: malloc (in /usr/local/Cellar/valgrind/HEAD/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==1866==    by 0x1001D0696: __smakebuf (in /usr/lib/system/libsystem_c.dylib)
==1866==    by 0x1001E51E7: __swsetup (in /usr/lib/system/libsystem_c.dylib)
==1866==    by 0x1001FF5BD: __v2printf (in /usr/lib/system/libsystem_c.dylib)
==1866==    by 0x1001FFAE0: __xvprintf (in /usr/lib/system/libsystem_c.dylib)
==1866==    by 0x1001D59D1: vfprintf_l (in /usr/lib/system/libsystem_c.dylib)
==1866==    by 0x1001D3837: printf (in /usr/lib/system/libsystem_c.dylib)
==1866==    by 0x100000F33: main (ex4.c:9)
==1866==
I am 1 inches tall.
==1866==
==1866== HEAP SUMMARY:
==1866==     in use at exit: 38,653 bytes in 417 blocks
==1866==   total heap usage: 512 allocs, 95 frees, 45,493 bytes allocated
==1866==
==1866== LEAK SUMMARY:
==1866==    definitely lost: 0 bytes in 0 blocks
==1866==    indirectly lost: 0 bytes in 0 blocks
==1866==      possibly lost: 0 bytes in 0 blocks
==1866==    still reachable: 0 bytes in 0 blocks
==1866==         suppressed: 38,653 bytes in 417 blocks
==1866==
==1866== For counts of detected and suppressed errors, rerun with: -v
==1866== Use --track-origins=yes to see where uninitialised values come from
==1866== ERROR SUMMARY: 5 errors from 5 contexts (suppressed: 0 from 0)
```
Running my program (despite the intentional errors), generated the strange output shown here:

```
I am 1354332224 years old.
I am 32767 inches tall.

Process finished with exit code 0
```

After correcting the errors in the program, the following is the output generated from Valgrind:

```
 ➜  valgrind ./Ex4
==1937== Memcheck, a memory error detector
==1937== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==1937== Using Valgrind-3.11.0.SVN and LibVEX; rerun with -h for copyright info
==1937== Command: ./Ex4
==1937==
--1937-- run: /usr/bin/dsymutil "./Ex4"
I am 10 years old.
I am 75 inches tall.
==1937==
==1937== HEAP SUMMARY:
==1937==     in use at exit: 38,653 bytes in 417 blocks
==1937==   total heap usage: 512 allocs, 95 frees, 45,493 bytes allocated
==1937==
==1937== LEAK SUMMARY:
==1937==    definitely lost: 0 bytes in 0 blocks
==1937==    indirectly lost: 0 bytes in 0 blocks
==1937==      possibly lost: 0 bytes in 0 blocks
==1937==    still reachable: 0 bytes in 0 blocks
==1937==         suppressed: 38,653 bytes in 417 blocks
==1937==
==1937== For counts of detected and suppressed errors, rerun with: -v
==1937== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
### Read up on Valgrind on the internet.
I found it incredibly helpful to understand and research how Valgrind operates (even if only in a cursory manner):

- It acts as a VM performing JIT compilation
- The host machine (2014 "13 Macbook Air i7) never actually sees any of the program run on its own processor
- Valgrind is actually a full suite of debugging tools developed by developer Julian Seward, for which he won a Google-O'Reilly Open Source Award

NOTE: Many were saying on blogs and forums (i.e., StackOverflow) that Valgrind was not supported on OSX Yosemite; however,
I was fortunate in avoiding the install 'workarounds.' I simply first tried the first and suggested approach which is to
run ```brew install --HEAD valgrind``` in the CLI. It is, of course, necessary to have Homebrew installed.

### Download other software and build it by hand. Try something you already use but never built for yourself.
I decided to build Weechat from source on my Ubuntu 15.04 VM, and found the process to be straight forward and rewarding.

### Look at how the Valgrind source files are laid out in the source directory and read its Makefile. Don't worry, none of that makes sense to me either.
Wow...completely over my head at this point, but very interesting as well. Since starting this course/book/journey, I've found myself
hopping over to Github more than usual to look at source code and feel quite motivated by reviewing and reading more code.