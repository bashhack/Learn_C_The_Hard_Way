# Exercise 2: Make Is Your Python Now
## Extra Credit
### Create an all: `ex1` target that will build `ex1` with just the command `make`.
```
CFLAGS = -Wall -g

all: ex1

clean:
    rm -f ex1
```
### Read `man make` to find out more information on how to run it.
> The purpose of the make utility is to determine automatically which pieces of a large program need to be recompiled,
and issue the commands to recompile them.

> To  prepare to use make, you must write a file called the makefile that describes the relationships among files
in your program, and the states the commands for updating each file. In a program, typically the executable file is
updated from object files, which are in turn made by compiling source files.

> Once a suitable makefile exists, each time you change some source files, this simple shell command (make)
suffices to perform all necessary recompilations. The make program uses the makefile data base and the
last-modification times of the files to decide which of the files need to be updated. For each of those files,
it issues the commands recorded in the data base.

There are many options for the `make` command, including:

1. -d: prints debugging info
```
 ➜  make ex2 -d
GNU Make 3.81
Copyright (C) 2006  Free Software Foundation, Inc.
This is free software; see the source for copying conditions.
There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.

This program built for i386-apple-darwin11.3.0
Reading makefiles...
Reading makefile `Makefile'...
Updating makefiles....
    Considering target file `Makefile'.
        Looking for an implicit rule for `Makefile'.
        Trying pattern rule with stem `Makefile'.
        Trying implicit prerequisite `Makefile.o'.
        Trying pattern rule with stem `Makefile'.
        Trying implicit prerequisite `Makefile.c'.
        Trying pattern rule with stem `Makefile'.
        Trying implicit prerequisite `Makefile.cc'.
        Trying pattern rule with stem `Makefile'.
        Trying implicit prerequisite `Makefile.C'.
  ...
```
2. -v: prints version info
```
 ➜  make ex2 -v
GNU Make 3.81
Copyright (C) 2006  Free Software Foundation, Inc.
This is free software; see the source for copying conditions.
There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.

This program built for i386-apple-darwin11.3.0

```
3. -I: specifies a directory dir to search for included makefiles
```
 ➜  mkdir MyNewDir
 ➜  cp Makefile MyNewDir
 ➜  make -I MyNewDir ex2
```

### Read `man cc` to find out more information on what the flags `-Wall` and `-g` do.
> Both `-Wall` and `-g` are flags that append the command `cc` (i.e., clang).

> clang is a C, C++, and Objective-C compiler which encompasses preprocessing, parsing, optimization,
code generation, assembly, and linking.

> `-Wall`: This enables all the warnings about constructions that some users consider questionable,
and that are easy to avoid (or modify to prevent the warning), even in conjunction with macros.
This also enables some language-specific warnings described in C++ Dialect Options and Objective-C
and Objective-C++ Dialect Options. -Wall turns on the following warning flags:

```
Waddress
Warray-bounds=1 (only with -O2)
Wc++11-compat  -Wc++14-compat
Wchar-subscripts
Wenum-compare (in C/ObjC; this is on by default in C++)
Wimplicit-int (C and Objective-C only)
Wimplicit-function-declaration (C and Objective-C only)
Wbool-compare
Wcomment
Wformat
Wmain (only for C/ObjC and unless -ffreestanding)
Wmaybe-uninitialized
Wmissing-braces (only for C/ObjC)
Wnonnull
Wopenmp-simd
Wparentheses
Wpointer-sign
Wreorder
Wreturn-type
Wsequence-point
Wsign-compare (only in C++)
Wstrict-aliasing
Wstrict-overflow=1
Wswitch
Wtautological-compare
Wtrigraphs
Wuninitialized
Wunknown-pragmas
Wunused-function
Wunused-label
Wunused-value
Wunused-variable
Wvolatile-register-var
```

> `-g`: Generate debug information.  Note that Clang debug information works best at -O0.
Produce debugging information in the operating system's native format (stabs, COFF, XCOFF, or DWARF 2).
GDB can work with this debugging information. On most systems that use stabs format, -g enables use of
extra debugging information that only GDB can use; this extra information makes debugging work better
in GDB but probably makes other debuggers crash or refuse to read the program. If you want to control
for certain whether to generate the extra information, use -gstabs+, -gstabs, -gxcoff+, -gxcoff, or -gvms (see below).

> GCC allows you to use -g with -O. The shortcuts taken by optimized code may occasionally produce surprising results:
some variables you declared may not exist at all; flow of control may briefly move where you did not expect it;
some statements may not be executed because they compute constant results or their values are already at hand;
some statements may execute in different places because they have been moved out of loops.

### Research Makefiles online and see if you can improve this one even more.
```
#
# 'make depend' uses makedepend to automatically generate dependencies
# 				(dependencies are added to end of Makefile)
# 'make'		build executable file assigned at main
# 'make clean'	removes all .o and executable files
#

# define the C compiler to use
CC = gcc

# define any compile-time flags
CFLAGS = -Wall -g

# define any directories containing header files other than /usr/include
#
INCLUDES =

# define library paths in addition to /usr/lib
#		if I wanted to include libraries not in /usr/lib I'd specify
#		their path using -Lpath, something like:
LFLAGS =

# define any libraries to link into executable:
# 	if I want to link in libraries (libx.so or libx.a) I use the -llibname
# 	option, something like (this will link in libmylib.so and libm.so:
LIBS =

# define the C source files
SRCS = ex1.c

# define the C object files
#
# This uses Suffix Replacement within a macro:
# 	$(name:string1=string2)
# 			For each word in 'name' replace 'string1' with 'string2'
# Below we are replacing the suffix .c of all words in the macro SRCS
# with the .o suffix
#
OBJS = $(SRCS:.c=.o)

# define the executable file
MAIN = ex1

#
# The following part of the makefile is generic; it can be used to
# build any executable just by changing the definitions above and by
# deleting dependencies appended to the file from 'make depend'
#

.PHONY: depend clean

all: $(MAIN)
	@echo Simple compiler named $(MAIN) has been compiled

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

# this is the suffix replacement for building .o's from .c's
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .c file) and $@: the name of the target of the rule (a .o file)
# (see the gnu make manual about automatic variables)
.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


clean:
	$(RM) *.o *~ $(MAIN)

depend:
	makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it
```

### Find a `Makefile` in another C project and try to understand what it's doing.
I reviewed an example Makefile from the Stanford University CS 107, which was another
great introduction to key concepts that allow for the creation of extensible and highly readable Makefiles:

1. Use of comments, denoted by `#` help visually separate concerns and logically ordered code.
2. Addition of several more CFLAGS params (including `-std=c99`) illustrate the flexibility of error-checking.
3. Variable assignments, like `SOURCES` `OBJECTS` and `TARGET` were used to transform the Makefile into a reusable resource.


