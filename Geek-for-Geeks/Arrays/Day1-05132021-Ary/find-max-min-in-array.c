#include <stdio.h>
#include <stdlib.h>


void find_min_max(int arr[], int* min, int* max, int arr_size){

	for(int i = 0; i < arr_size; i++){
		
		if (arr[i] > *max){
			*max = arr[i];
		}
		
		if (arr[i] < *min){
			*min = arr[i];
		}
	}
}


int main(){
	
	int arr[] = {1, 2, 4, -1};
	int min = 0, max = 0;
	
	int arr_size = sizeof(arr)/sizeof (arr[0]);

	find_min_max(arr, &min, &max, arr_size);

	printf("Min value is %d\n", min);
	printf("Max value is %d\n", max);

	return 0;	
}
