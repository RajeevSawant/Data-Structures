/*
 *	Define a calculate func that takes in an integer and an operation
 *	The func should return the result of the operation on the integer.
 */

#include <stdio.h>
typedef int (*func_t)(int, int);


int sum (int a, int b)
{	
	return (a + b);	
}

int calculate(int num, func_t func)
{
	return func(num, num);
}



int main()
{	
		
         int num = 0;
	 printf("Enter the value of num \n");
	 scanf("%d", &num);

	 printf("The result is %.2d \n", calculate(num, sum));
	
	return 0;
}


