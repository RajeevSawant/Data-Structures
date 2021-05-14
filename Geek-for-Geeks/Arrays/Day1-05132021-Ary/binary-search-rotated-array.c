#include <stdio.h>
#include <stdlib.h>


int binary_search_rotated_array(int arr[], int target, int arr_size){

	int lo = 0, hi = arr_size - 1, mid = 0;

	while(lo < hi){
	
		mid = lo + (hi - lo)/2;

		if ((arr[0] < target) ^ (arr[0] < arr[mid]) ^ (arr[mid] < target))
			lo = mid + 1;
		else
			hi = mid;

	}

	return ((lo == hi && arr[lo] == target)? lo : -1);
}
