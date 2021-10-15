# README.md for hw-2 / problem-3-
#Nicholas Chin

## The algorithm / steps for problem 3 of HW2
```
START
        Step 1: Define variable for float (for float-point number), int (for an integer), and char (for a character)
        Step 2: Assign/declare a number for float
        Step 3: Assign/declare an integer for int
        Step 4: Assign/declare a letter for char
        Step 5: Print using %d conversion \n character for float
        Step 6: Print using %f conversion \n character for int
	Step 7: Print using %d conversion \n character for char
	Step 8: Return
STOP
```


##Pseudocode
```
{
	DEFINE float
	DEFINE int
	DEFINE char

	DECLARE float = 
	DECLARE int =
	DECLARE char =
	
        PRINT "%d conversion" float
        PRINT "%f conversion" int
	PRINT "%d conversion" char
}
```


## The Code
```

#include <stdio.h>

/*floating-point number*/
float floatn;

/*integer*/
int intn;

/*character*/
char character;

int main() {
        floatn = 2.0;
        intn = 1;
        character = 'N';

        printf("%f as %%d: %f\n", floatn, floatn);
        printf("%d as %%f: %d\n", intn, intn);
        printf("%c as %%d: %d\n", character, character);

        return(0);
}

```
