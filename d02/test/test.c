#include <stdio.h>
#include <unistd.h>

int main()
{
	int number1 = 1;
	int number2 = number1++;
	printf("Number 1: %d, Number 2: %d\n", number1, number2);
	
	write(1, "Hello world", 25);
	return(0);
