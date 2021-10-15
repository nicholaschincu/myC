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
