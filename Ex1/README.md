# Exercise 1: Dust Off That Compiler
## Extra Credit
### Open the ex1 file in your text editor and change or delete random parts. Try running it and see what happens.
Here are some examples:

1. Change `int main` to `main`
```
➜  make ex1
cc     ex1.c   -o ex1
ex1.c:3:1: warning: type specifier missing, defaults to 'int' [-Wimplicit-int]
main(int argc, char *argv[]) {
^
1 warning generated.
```
2. Remove the `#include` statement
```
 ➜  CFLAGS="-Wall -Werror" make ex1
cc -Wall -Werror    ex1.c   -o ex1
ex1.c:5:5: error: implicit declaration of function 'puts' is invalid in C99 [-Werror,-Wimplicit-function-declaration]
    puts("Hello World!\n");
    ^
1 error generated.
make: *** [ex1] Error 1
```
3. Type `put` instead of `puts`
```
 ➜  CFLAGS="-Wall -Werror" make ex1
cc -Wall -Werror    ex1.c   -o ex1
ex1.c:5:5: error: implicit declaration of function 'put' is invalid in C99 [-Werror,-Wimplicit-function-declaration]
    put("Hello World!\n");
    ^
1 error generated.
make: *** [ex1] Error 1
```
4. Remove closing `}`
```
 ➜  CFLAGS="-Wall -Werror" make ex1
cc -Wall -Werror    ex1.c   -o ex1
ex1.c:7:14: error: expected '}'
    return 0;
             ^
ex1.c:3:34: note: to match this '{'
int main(int argc, char *argv[]) {
                                 ^
1 error generated.
make: *** [ex1] Error 1
```
### Print out 5 more lines of text or something more complex than hello world.
```
#include <stdio.h>

/* Start of Main func */
int main(int argc, char *argv[]) {

    puts("Hello World!\n");
    puts("I'm a lumberjack and I'm okay.\n");
    puts("Well, there's egg and bacon, egg sausage and bacon, egg and spam, egg bacon and spam, "
                 "egg bacon sausage and spam, spam bacon sausage and spam, spam egg spam spam bacon and spam, "
                 "spam sausage spam spam bacon spam tomato and spam\n");
    puts("Always look on the bright side of life.\n");
    puts("We are no longer the knights who say ni!\n"
                 "We are now the knights who say ekki-ekki-ekki-pitang-zoom-boing!\n");
    puts("Nobody expects the Spanish Inquisition!");

    return 0;
}
```
### Run man 3 puts and read about this function and many others.
> The function puts() writes the string s, and a terminating newline character, to the stream stdout.
The functions fputs() and puts() return a nonnegative integer on success and EOF on error.

