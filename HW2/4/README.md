# README.md for hw-2 / problem-4-
#Nicholas Chin

## The algorithm / steps for problem 4 of HW2
```
START
	Step 1. Define the variables and the amount of cents each coin represents
	Step 2. Print what you want the user to do
	Step 3. Make input command to take some value from the user according to the given format specifier and stores it at a desired variable
	Step 4. Make an if statement to generate a conditional to determine number of quarters
	Step 5. If true, it will perform the formula entered to determine amount of quarters
	Step 6: Close if loop
	Step 7: Make an if statement to generate a conditional to determine number of dimes that can be obtained with the remaining cents
        Step 8: If true, it will perform the formula entered to determine amount of dimes
	Step 9: Close if loop
	Step 10: Make an if statement to generate a conditional to determine number of nickels that can be obtained with the remaining cents
        Step 11: If true, it will perform the formula entered to determine amount of nickels
        Step 12: Close if loop
	Step 13: Make an if statement to generate a conditional to determine number of pennies that can be obtained with the remaining cents
        Step 14: If true, it will perform the formula entered to determine amount of pennies
        Step 15: Close if loop
	Step 16: Print \n character after each if iteration
STOP
```


##Pseudocode
```
To determine least amount of coins given cents {
	define Quarter
	define Dime
	define Nickel
	define Penny

	PRINT " "
	SCANF " "

	if amount is greater than or equal to 25 DO
		Quarters = amount / Quarter
	END if

		if remaining amount is greater than or equal to 10 DO
			Dimes = amount / Dime
		END if

			if remaining amount is greater than or equal to 5 DO
				Nickels = amount / Nickel
			END if

				if remaining amount is greater than or equal to 1 DO
					Pennies = amount
				END if
	
	PRINT \n
}
```


## The Code
```c

#include <stdio.h>

#define Quarter 25
#define Dime 10
#define Nickel 5
#define Penny 1

int main() {

        int Quarters = 0;
        int Dimes = 0;
        int Nickels = 0;
        int Pennies = 0;
        int amount;

        printf("Enter the amount of US money in cents: "); /*user inputs amount of US cents*/
        scanf("%d", &amount);


        if(amount >= 25)
        {
                Quarters = (amount / Quarter);
                amount = (amount - (Quarters*25));
        }

                if(amount >= 10)
                {
                        Dimes = (amount / Dime);
                        amount = (amount - (Dimes*10));
                }

                        if(amount >= 5)
                        {
                                Nickels = (amount / Nickel);
                                amount = (amount - (Nickels*5));
                        }

                                if(amount >= 1)
                                {
                                        Pennies = amount;
                                }

        printf("Least amount of coins:\n %d Quarters\n %d Dimes\n %d Nickels\n %d Pennies\n", Quarters, Dimes, Nickels, Pennies);
}
```
