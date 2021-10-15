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
