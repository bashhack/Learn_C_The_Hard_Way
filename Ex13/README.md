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
argc count was: 2
2: r is not a vowel
3: c is not a vowel
```
### Use uninitialized values in the ```switch```.

## Extra Credit
### Write another program that uses math on the letter to convert it to lowercase, and then remove all the extraneous uppercase letters in the switch.

### Use the ```','``` (comma) to initialize ```letter``` in the ```for-loop```.

### Make it handle all of the arguments you pass it with yet another ```for-loop```.

### Convert this ```switch-statement``` to an ```if-statement```. Which do you like better?

### In the case for 'Y' I have the break outside the ```if-statement```. What's the impact of this and what happens if you move it inside the ```if-statement```. Prove to yourself that you're right.
