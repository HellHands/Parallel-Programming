/* Description of the content of the file and important remarks. *
 * File: <exercise02.c>                Author:  <Prithvi Raj Moorani>
 * Date: <20 October 2017>                     Version: <01>
 */

#include <stdio.h>
#include <time.h>

/**
 * Iterative implementation for nth fibonacci number
 * 
 * @param n
 * @return
 */

long fibonacciIterative (int n) {
	clock_t start, end, total;
	start = clock();
	if(n <= 1) {
		return n;
	}
	int fib = 1;
	int prevFib = 1;
	
	for(int i = 2; i < n; i++) {
		int temp = fib;
		fib += prevFib;
		prevFib = temp;
	}
	end = clock();
	return total = (double)(end - start) / CLOCKS_PER_SEC;
}

/**
 * Recursive implementation for nth fibonacci number
 * 
 * @param n
 * @return
 */
long fibonacciRecursive (int n) {
	clock_t end, start, total;
	int sum;
	start = clock();
	if(n <= 1) {
		return n;
	}
	sum = fibonacciRecursive (n - 1) + fibonacciRecursive ( n - 2);
	end = clock();
	return total = (double)(end - start) / CLOCKS_PER_SEC; 
}

int main (void) 
{

	printf("Iterative version: \n");
	printf("Total time with n=35: %ld\n", fibonacciIterative(35));
	printf("Total time with n=45: %ld\n", fibonacciIterative(45));
	
	printf("\n");

	printf("Recursive version: \n");
	printf("Total time with n=35: %ld\n", fibonacciRecursive(35));
	printf("Total time with n=45: %ld\n", fibonacciRecursive(45));

	printf("\n");

	return 0;
}