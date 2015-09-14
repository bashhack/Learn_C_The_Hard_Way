# Exercise 7: More Variables, Some Math
## Extra Credit
### Make the number you assign to universe_of_defects various sizes until you get a warning from the compiler.
I was able to increase the long until I chose a multiplier value of 1,024,024,024. This resulted in the warning below:
```
[ 50%] Building C object CMakeFiles/Ex7.dir/Ex7/ex7.c.o
.../Development/Projects/LCTHW/Ex7/ex7.c:10:63: warning: overflow in expression; result is -3164216001973615104 with type 'long' [-Winteger-overflow]
    long universe_of_defects = 1L * 1024024024L * 1024024024L * 1024024024L;
                                                              ^
1 warning generated.
[100%] Linking C executable .../Development/Projects/LCTHW/builds/Debug/Ex7
[100%] Built target Ex7
```

After some research, I was able to dive deeper into the ```long``` data type, finding that it's value is constrained to a range, as are the other numeric data types.
The range for a long is: -2,147,483,648 to 2,147,483,647. After receiving the overflow in expression warning, I corrected my program by chaning the ```long``` to ```long long```
### What do these really huge numbers actually print out?
```
You have 100 bugs at the imaginary rate of 1.20.
The entire universe has -3164216001973615104 bugs.
You are expected to have 120.00 bugs.
That is only a -3.792409e-17 portion of the universe.
Which means you should care 0%.

Process finished with exit code 0
```
### Change long to unsigned long and try to find the number that makes that one too big.

### Go search online to find out what unsigned does.

### Try to explain to yourself (before I do in the next exercise) why you can multiply a char and an int.
