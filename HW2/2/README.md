# README.md for hw-2 / problem-2-
#Nicholas Chin

## The algorithm / steps for problem 2 of HW2
```
START
        Step 1: Use int to define minutes and hours
        Step 2: Ask user to Print number of minutes
        Step 3: Enter formula for hours
	Step 4: Enter formula for minutes
	Step 5: Print \n character for hours
        Step 6: Print \n character for minutes
STOP
```


##Pseudocode
```
To convert minutes to hours and minutes{

        int define variables for minutes and hours
	PRINT " "

        hours = min/60
	minutes = (min - 60*hours)


        PRINT hours\n
	PRINT minutes\n
}
```


## The Code
```c

#include <stdio.h>

int main() {
        int min, h, m;
        printf("Enter number of minutes");
                scanf("%d",&min);

        h = (min/60);

        m = (min - (60*h));

        printf("H hours - %d \n", h);
        printf("M minutes - %d \n", m);

        return(0);

        }
```
