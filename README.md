LoadedDice
==========

Write a program using C++ to do the following

Simulate the rolling of two 6-sided dice.  Each dice will be loaded so that one side comes up more frequently than the others.  

The program will need to:

1.  Open a file and read key, values pairs (i.e. key=value)
    a. the keys will be, number of rolls to execute, the die identifier, which side of the dice is loaded and by how much that side is loaded.
2.  Execute each throw of the dice and print out each die's result.
3.  Summarize the results of each dice and the percentages that each side came up.

So as an example the parameter file might look like this.

NumRolls=100
Dice=Die1
LoadedSide=3
LoadAmount=2
Dice=Die2
LoadedSide=6
LoadAmount=10

The LoadAmount would be the factor that that side is likely to occur so Die1, Side 3
would be twice as likely as the other sides to appear and Die2, Side 6 would be 10 times as likely.

And the results would show each throw

Throw 1: Die1 rolled a 3, Die2 rolled a 6
Throw 2: Die1 rolled a 2, Die2 rolled a 2
Throw 3: Die1 rolled a 3, Die2 rolled a 6
Throw 4: Die1 rolled a 1, Die2 rolled a 6
Throw 5: Die1 rolled a 6, Die2 rolled a 6
.
.
.

And then at the end a summary

Die1 Statistics for 100 rolls:
Side 1: 13%
Side 2: 15%
Side 3: 30%
Side 4: 14%
Side 5: 16%
Side 6: 12%

Die2 Statistics for 100 rolls:
Side 1: 8%
Side 2: 6%
Side 3: 6%
Side 4: 7%
Side 5: 9%
Side 6: 64%


How to build:
>> cd build
>> ./bootstrap.sh

NOTE: To enable debug logs - pass "-DDEBUG=ON" to boostrap script

-- This will install the program to build/debug/bin
run LoadedDice <Configuration File> to see the output

NOTE : Example configuration files are located in ConfigurationFiles directory



