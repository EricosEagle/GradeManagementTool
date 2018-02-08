## Features

* Rounded average of grades
* Prints highest grade
* Prints lowest grade
* Prints the median grade
* Prints all grades greater than a certain grade
* Prints all the grades below a certain grade
* Prints how many extra points the students will need to pass the course

### Command guide

* V - Rounded average
* X - Maximum
* I - Minimum
* M - Median
* A (Grade) - Prints how many grades are above the entered grade
* B (Grade) - Prints how many grades are below the entered grade
* F (Passing Grade) (Percent of class) - Prints the factor you need to add to each student's grades to have all of the students pass

## Usage

```

> Enter your grades ending with '-1':
> No grades above 100 or below 0 are counted
100 90 0 0 70 -1
> Enter your command:
V
> 52
> Enter your command:
X
> 100
> Enter your command:
I
> 0
> Enter your command:
M
> 70
> Enter your command:
A
> Enter lower bound:
90
> 1
> Enter your command:
A
> Enter lower bound:
89
> 2
> Enter a command:
B
> Enter upper bound:
100
> 4
> Enter a command:
F
> Enter passing grade and what percentage of the class needs to pass:
60 60
> 0
> Enter a command:
F
> Enter passing grade and what percentage of the class needs to pass:
95 40
> 5
> Enter a command:
F
> Enter passing grade and what percentage of the class needs to pass:
100 100
> 100
> Enter a command:
F
> Enter passing grade and what percentage of the class needs to pass:
90 105
> 0
> Enter a command:
F 90 **Bad input**
> Enter a command:
F B **Bad input**
> Enter a command:
G
> This command is currently not supported by the system.
> Enter a command:
A
> Enter upper bound:
-5
> 5
```
