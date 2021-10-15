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
