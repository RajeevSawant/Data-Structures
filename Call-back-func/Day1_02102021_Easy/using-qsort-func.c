/*
 * Sort an integer array in the ascending
 * order by using the qsort func
 */



#include <stdio.h>


#define arr_size  10

int compare(const int* a, const int* b)
{
	return (*a - *b);
}

int main()
{
	int arr[arr_size] = {10, 9, 45, 36, 89, 0, 15, 98, 11, 5};
	
	qsort(arr, arr_size, sizeof(int), compare);
	

	int i = 0, counter = arr_size;
	while (--counter)
	{
		printf("%d ", arr[i++]);
	}
	printf("\n");
}



