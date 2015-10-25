# Exercise 12: If, Else-If, Else
## How to Break It
### Remove the else at the end and it won't catch the edge case.
Haivng removed the else, running the program as shown below:

```
➜  ./Ex12 one two three
```

...resulted in the following output (that is, the program ran as expected with no additional command line print statements):

```
... at MacBookPro in ~/Development/Projects/Learn_C_The_Hard_Way/builds/Debug on ex12*
 ➜  

```

### Change the && to a || so you get an "or" instead of "and" test and see how that works.
As expected, the ```||``` operator changes the behavior of our program, resulting in our ```else ``` block never being reached because the first part of our ```else if``` condition is always true (thus, printing our args to console) anytime any args in addition to the program itself are supplied.

```
 ➜  ./Ex12
There's only one argument.
... at MacBookPro in ~/Development/Projects/Learn_C_The_Hard_Way/builds/Debug on ex12*
 ➜  ./Ex12 one
Here's your arguments:
./Ex12 one
... at MacBookPro in ~/Development/Projects/Learn_C_The_Hard_Way/builds/Debug on ex12*
 ➜  ./Ex12 one two
Here's your arguments:
./Ex12 one two
... at MacBookPro in ~/Development/Projects/Learn_C_The_Hard_Way/builds/Debug on ex12*
 ➜  ./Ex12 one two three
Here's your arguments:
./Ex12 one two three
... at MacBookPro in ~/Development/Projects/Learn_C_The_Hard_Way/builds/Debug on ex12*
 ➜  ./Ex12 one two three four
Here's your arguments:
./Ex12 one two three four
```

## Extra Credit
### You were briefly introduced to &&, which does an "and" comparison, so go research online the different "boolean operators".
This was another welcome syntax lesson where I was able to draw on my day-to-day JavaScript experience, and see again its roots in C. Both languages share the same useful operators:

&& - 'and'

|| - 'or'

! - 'not'
### Write a few more test cases for this program to see what you can come up with.
Here, I'm checking whether the total argument count passed by the user is even or odd:

```
#include <stdio.h>

int main(int argc, char *argv[]) {

    int i = 0;

    if (argc == 1) {
        printf("There's only one argument.\n");
    } else if (argc > 1 && argc < 5) {
        if (argc % 2 == 0) {
            printf("You have an odd number of user-supplied args.\n");
        } else if (argc % 2 != 0) {
            printf("You have an even number of user-supplied args.\n");
        }
    } else {
        printf("You have too many arguments!\n");
        printf("Your last argument was %s.\n", argv[argc -1]);
    }

    return 0;
}
```
### Go back to Exercises 10 and 11, and use if-statements to make the loops exit early. You'll need the break statement to do that. Go read about it.
I wanted to accomplish two things in ```Ex10```, the first of which was using an if-else block combination and the second was utilizing a break statement.

Please see the file ```ex10_refactor.c``` for the full refactored code of Example 10.

Please see the file ```ex11_refactor.c``` for the full refactored code of Example 11.

The results after the insertion of the break statement is as follows (Ex10 and Ex11, respectively):
```
guitars 0: Fender
guitars 1: Gibson
```

```
band 0: Genesis
band 1: Yes
```
### Is the first test really saying the right thing? To you the "first argument" isn't the same first argument a user entered. Fix it.
No, it is not. I have written a more user-oriented refactoring of the program found in ```ex12_refactor.c```.

The output is below:

```
 ➜  ./Ex12_refactor
You've not supplied any arguments above and beyond the first (the program itself).
```
```
 ➜  ./Ex12_refactor one
You've only supplied one argument.
```
```
 ➜  ./Ex12_refactor one two three
Here's your arguments:
./Ex12 one two three
```
```
 ➜  ./Ex12_refactor one two three four
You have too many arguments!
```