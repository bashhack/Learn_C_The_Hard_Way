# Exercise 10: Arrays Of Strings, Looping
## How to Break It
### Take your favorite other language, and use it to run this program, but with as many command line arguments as possible. See if you can bust it by giving it way too many arguments.
Given that my day-to-day job duties include maintaining and writing large amounts of JavaScript, I wanted to approach my solution using a language I use professionally.

Utilizing the Node.js runtime environment, I wrote a small program to allow me to keep track of command line arguments (see ```nodeCLI```).

```
#! /usr/local/bin/node

var i = 0,
    j = 0,
    guitars = [],
    numOfGuitars = 0;

guitars = [
    "Fender",
    "Gibson",
    "Rickenbacker",
    "Ibanez"
]

numOfGuitars = 4;

for (i = 0; i < numOfGuitars; i++) {
    console.log('guitars ' + i + ': ' + guitars[i]);
}

for (j = 2; j < process.argv.length; j++) {
    console.log('arg ' + j + ': ' + process.argv[j]);
}
```

I passed as many as 250+ args, but was unsuccessful in presenting any errors and/or warnings. Knowing that the Bash language provides commands to query the constraints of the UNIX architecture, I wrote another simple script:

```
#! /bin/bash

/*
 *
 * Simple UNIX script to find max arg count for sys (OSX 10.10.5, Yosemite)
 *
 */

getconf ARG_MAX
```

Which gave the following result: ```262144```

### Initialize ```i``` to 0 and see what that does. Do you have to adjust ```argc``` as well or does it just work? Why does 0-based indexing work here?
Setting the initializer to ```0``` worked just fine, which I expected after having experimented with the intializers in my Node.js program. When running my earlier program, I saw that the first two args (when setting initializer to ```0```) were (1) the Node environment and (2) the program itself.

Here, in C, setting the initializer to ```0``` gave the program - the environment itself was not presented, in this case.

### Set ```num_states``` wrong so that it's a higher value and see what it does.
This was interesting: I expected the output to be the same (i.e., to fail 'cleanly'), with the erroneous assignment to ```num_of_guitars``` (my ```num_states```).

However, after I cleaned and re-built the project, I received the following output:
```
guitars 0: Fender
guitars 1: Gibson
guitars 2: Rickenbacker
guitars 3: Ibanez
guitars 4:

Process finished with exit code 11
```

Unfortunately, exit codes (at least in my understanding) don't always have exact one-to-one analogs. Wanting to see if I could get a more concrete reading of the error, I ran my program through Valgrind where...well...the program generated an error log that ran until my MacBook Pro Quad-Core i7 was brought to a complete standstill requiring a restart to fully kill the running process.

## Extra Credit
### Figure out what kind of code you can put into the parts of a ```for-loop```.
The basic structure of a ```for-loop``` seems to be the same here in C, as it is the languages which have been inspired by or derived from it:

```
for (SOME EXPRESSION) {
    // Do something here a number of times, until expression is no longer true
}
```

Building the project with the variable ```null``` in the array, CMake was unable to complete the task and generated the following error:
```
[ 50%] Building C object CMakeFiles/Ex10.dir/Ex10/ex10.c.o
.../.../Development/Projects/Learn_C_The_Hard_Way/Ex10/ex10.c:16:29: error: use of undeclared identifier 'null'
            "Rickenbacker", null
                            ^
1 error generated.
make[3]: *** [CMakeFiles/Ex10.dir/Ex10/ex10.c.o] Error 1
make[2]: *** [CMakeFiles/Ex10.dir/all] Error 2
make[1]: *** [CMakeFiles/Ex10.dir/rule] Error 2
make: *** [Ex10] Error 2
```

Per best practice, whether I am writing new code or maintaining legacy code, I avoid ```var``` declarations within the body of the ```for-loop``` as JavaScript does not have block scope. As such, I declare my variables at the top of the enclosing function, and I gather this may be best practice in C, as well.
### Look up how to use the ```','``` (comma) character to separate multiple statements in the parts of the ```for-loop```, but between the ```';'``` (semicolon) characters.
Depending on the loop, I sometimes (due to legacy code bases I work on) write loops that look like this:

```
for (var x = X, y = Y, etc.; x < DATASTRUCT.PROP, etc; x++/x--) {
    // Do something...
}
```
### Read what a ```NULL ``` is and try to use it in one of the elements of the ```states``` array to see what it'll print.
Checking the man pages entry for NULL, the definition given is:

```
NAME
    null = the null device

DESCRIPTION
    The null device accepts and reads data as any ordinary (and willing) file - but throws it away. The length of the null device is always zero.
```

### See if you can assign an element from the ```states``` array to the ```argv``` array before printing both. Try the inverse.
In the first test (assigning to argv array), no errors were generated and the program ran with the expected result - the value of ```argv[1]``` was ```Gibson```.

In the second text (assigning to the guitars array), while no errors were thrown, I did receive the following curious output:
```
guitars 0: Fender
guitars 1: (null)
guitars 2: Rickenbacker
guitars 3: Ibanez
result of assignment to guitars (null)
Process finished with exit code 0
```