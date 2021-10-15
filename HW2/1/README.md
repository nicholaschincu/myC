# README.md for hw-2 / problem-1-
#Nicholas Chin

## The algorithm / steps for problem 1 of HW2
```
START
        Step 1: float the height, width, and perimeter so that any value (including decimals) are calculated for
        Step 2: Ask user to Print a height
        Step 3: Make input command to take that value from the user according to the given format specifier and stores it at a desired variable
        Step 4: Ask user to Print a width
        Step 5: Make input command to take that value from the user according ot the given format specifier and stores it at a desired variable
        Step 6: Enter formula for perimeter. perimeter = 2*height + 2*width
        Step 7: Print \n character for the perimeter 
STOP
```


##Pseudocode
```
To find Perimeter of a rectangle{
        
	float height, width, perimeter

        PRINT "height"
        SCANF " "
	PRINT "width"
	SCANF " "

	perimeter = 2*height + 2*width
        PRINT perimeter\n
}
```


## The Code
```c

#include <stdio.h>

int main(){

        float height, width, perimeter;

        /*Enter the height and width of rectangle from the user in inches*/

        printf("Enter the height of the rectangle: ");
        scanf("%e", &height);
        printf("Enter the width of the rectangle: ");
        scanf("%e", &width);

        /*Calculate perimeter of rectangle*/

        perimeter = 2*height + 2*width;
        printf("Perimeter of rectangle = %finches\n", perimeter);

        return (0);
}
```
