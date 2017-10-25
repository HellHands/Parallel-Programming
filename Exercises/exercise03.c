/** 
 * Description of the content of the file and important remarks. *
 * File: <exercise03.c>                Author:  <Prithvi Raj Moorani>
 * Date: <25 October 2017>                     Version: <01>
 */

#include <stdio.h>			//importing standard IO header file
#include <time.h>			//importing time header file
#include <stdlib.h>			//importing standard libary header file
#include <stdbool.h>		//importing boolean library header file
#include <stdint.h>			//for uint64 definition */

#define SIZE_OF_A 50000
#define SIZE_OF_B 100000
#define BILLION 1000000000L


double bubbleSort (int *arrayToSort, int sizeOfArray) 	//BubbleSort Function
{
	int temp;
	bool swapped = false;
	clock_t start, end;
	double cpu_time_used;

	start = clock();

	for (int i = 0; i < sizeOfArray; i++)
	{
		swapped = false;
		for (int j = 0; j < sizeOfArray-i; j++)
		{
			if (arrayToSort[j] > arrayToSort[j+1])
			{
				// printf("%d and %d\n", arrayToSort[j], arrayToSort[j+1]);
				temp = arrayToSort[j];
				arrayToSort[j] = arrayToSort[j + 1];
				arrayToSort[j + 1] = temp;
				swapped = true;
			}
		}
		
		if (!swapped)
		{
			break;
		}	
	}
	
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

	return cpu_time_used;
}

int main(void) 						//Main function
{
	int A[SIZE_OF_A], 				//Array A with 50000 elements
		B[SIZE_OF_B];				//Array B with 100000 elements
	double 	BubbleSort_cpu_time_used_by_A, 
			BubbleSort_cpu_time_used_by_B;
	struct timespec start, end;
	uint64_t BubbleSort_A_diff, BubbleSort_B_diff;
	
	//srand((unsigned)time(0)); 

	for(int i=0; i < SIZE_OF_A; i++)
	{
		A[i] = (rand() % 50000) + 1;
	}

	for(int i=0; i < SIZE_OF_B; i++)
	{
		B[i] = (rand() % 100000) + 1;
	}

	clock_gettime(CLOCK_MONOTONIC, &start);		/* mark start time */
	BubbleSort_cpu_time_used_by_A = bubbleSort(A, SIZE_OF_A);
	clock_gettime(CLOCK_MONOTONIC, &end);		/* mark the end time */
	BubbleSort_A_diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
	//printf("elapsed time = %llu seconds\n", (long long unsigned int) BubbleSort_A_diff/1000000000);

	clock_gettime(CLOCK_MONOTONIC, &start);		/* mark start time */
	BubbleSort_cpu_time_used_by_B = bubbleSort(B, SIZE_OF_B);
	clock_gettime(CLOCK_MONOTONIC, &end);		/* mark the end time */

	BubbleSort_B_diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
	//printf("elapsed time = %llu seconds\n", (long long unsigned int) BubbleSort_B_diff/1000000000);

	printf("\nAlgorithm\t\t\t\tarray size\t\t\t\tCPU Time(in seconds)\t\t\t\tElapsed Time(in seconds)\n");
	printf("=====================================================================================================================================\n");
	printf("BUBBLESORT\t\t\t\t %d\t\t\t\t\t %f \t\t\t\t\t\t %llu \n", SIZE_OF_A, BubbleSort_cpu_time_used_by_A, BubbleSort_A_diff/1000000000);
	printf("BUBBLESORT\t\t\t\t %d\t\t\t\t\t %f \t\t\t\t\t\t %llu \n", SIZE_OF_B, BubbleSort_cpu_time_used_by_B, BubbleSort_B_diff/1000000000);
	

	return 0;
}