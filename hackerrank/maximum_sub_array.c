#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int find_max_subarray_sum(int arr[], int n){
	
	int max_ending_here = 0, max = INT_MIN;
	
	for(int i = 0; i<n; i++){
		if((max_ending_here+arr[i]) > arr[i]){
			max_ending_here = max_ending_here + arr[i];
		}else{
			max_ending_here = arr[i];
		}
		
		if(max_ending_here > max){
			max = max_ending_here;
		}
	}
	
	return max;
}

int find_max_subsequence_sum(int arr[], int n){
	
	int sum = 0 , max = INT_MIN;
	
	for(int i = 0; i<n; i++){
		
		if(arr[i]>0){
			sum += arr[i];
		}
		
		if(max < arr[i]){
			max = arr[i];
		}
	}
	
	if(sum == 0 && max < 0 ){
		sum = max;
	}
	
	return sum;
}

int main(){

	int test_case, size;
	int *arr;
	
	scanf("%d", &test_case);
	
	for(int i = 1; i<=test_case; i++){
		int sum;
		
		scanf("%d", &size);

		arr = (int*)malloc(sizeof(int)*size);
		
		for(int c = 0; c<size; c++) scanf("%d", &arr[c]);
		
		sum = find_max_subarray_sum(arr, size);
		printf("%d ", sum);
		sum = find_max_subsequence_sum(arr, size);		
		printf("%d\n", sum);
		
		free(arr);
	}
	
}