# Exercise 5: The Structure Of A C Program
## Extra Credit
### For each line, write out the symbols you don't understand and see if you can guess what they mean. Write a little chart on paper with your guess that you can use to check later and see if you get it right.
Coming from a background in Python and Javascript, I am able to see syntactic similarities - or, more specifically, the syntactic origins of these and other languages.
As such, there hasn't been much that I have found too be unfamiliar; however, at this point I have been curious to better understand the arguments passed to the main function.

The first of these, a variable called 'argc' of the type int, can best be thought of as 'argument count' and contains the number of args passed to the program. The second, per the GNU docs, is a variable of type char which stands for 'argument vector.' A vector is a one-dimensional array, and our 'argv' is a one dimensional array of strings where each string is one of the arguments that we pass to our program (i.e., gcc -o myprog myprog.c, argv[gcc, -o, myprog, myprog.c]).
### Go back to the source code from the previous exercises and do a similar break-down to see if you're getting it. Write down what you don't know and can't explain to yourself.
So far, the syntax is coming together without too much confusion - more curiosity about convention than anything else, which has been opportunity to RTFM, as it were.