# Exercise 13: Switch Statement
## How to Break It
### Forget a ```break``` and it'll run two or more blocks of code you don't want it to run.
### Forget a ```default``` and have it silently ignore values you forgot.
### Accidentally put in variable into the ```switch``` that evaluates to something unexpected, like an ```int``` that becomes weird values.
### Use uninitialized values in the ```switch```.
## Extra Credit
### Write another program that uses math on the letter to convert it to lowercase, and then remove all the extraneous uppercase letters in the switch.
### Use the ```','``` (comma) to initialize ```letter``` in the ```for-loop```.
### Make it handle all of the arguments you pass it with yet another ```for-loop```.
### Convert this ```switch-statement``` to an ```if-statement```. Which do you like better?
### In the case for 'Y' I have the break outside the ```if-statement```. What's the impact of this and what happens if you move it inside the ```if-statement```. Prove to yourself that you're right.