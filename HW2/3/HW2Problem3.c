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

	printf("Result is: %f %%d= %d\n", floatn, floatn);
	printf("Result is: %d %%f= %f\n", intn, intn);
	printf("Result is: %c %%d= %d\n", character, character);

	return(0);
}
