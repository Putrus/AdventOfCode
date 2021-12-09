# AdventOfCode2021
Advent of code 2021 puzzles solutions.

To practice design patterns, I used the decorator design pattern to display the results of the puzzles.
Each puzzle has two parts and solutions are numbers. 

Displaying the results to the console looks like this :

![](https://github.com/Putrus/AdventOfCode2021/blob/main/Images/output.jpg?raw=true)

The decorator will work very nicely here, 
because we just need to list the tasks in the constructor of the Task object that we want to display 
and execute task.printResults() on our Task object(main.cpp).
For each advent task, there is a class that has the methods loadInput, getResultPart1 and getResultPart2.
the Decorator::printResultsArgs() method executes these methods and displays the result in a very nice format.
I think instead of written form it is better to look at the diagram which I created with StarUML:

![](https://github.com/Putrus/AdventOfCode2021/blob/main/Images/decorator.jpg?raw=true)

I hope you will like my solutions and the structure of this project. 
All the best! 
