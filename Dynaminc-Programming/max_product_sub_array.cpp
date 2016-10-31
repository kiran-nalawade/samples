#include <stdio.h>
#include <limits.h>

int main(){

	int arr[] = {0,0,-1,0,-2,-3};
	//	{0,0,0,0};
	//{-2, -3, 0, -2, -40};
	//{6, -3, -10, 0, 2};
	//{-1, -3, -10, 0, 60};
	//{1,2,3,-4,-5};
	int neg = 1, pos = 1, last_neg = 1;
	int max_so_far = 1;
	bool shall_ans_be_zero = true;
	
	for(int i = 0; i<sizeof(arr)/sizeof(arr[0]); i++){
		if(arr[i] == 0){
			neg = 1; pos = 1; last_neg = 1;
		}
		if(arr[i] > 0){
			shall_ans_be_zero = false;
			pos = pos * arr[i];
		}else if(arr[i] < 0){
			int pchanged = 0;
			
			if(last_neg*arr[i] > pos){
				pos = last_neg*arr[i];
				pchanged=1;
			}
			
			if(neg*arr[i]>pos){
				pos = neg*arr[i];
				pchanged=1;
			}
			
			if(pchanged == 0){
				neg = pos * arr[i];
			}else neg = 1;
			
			last_neg = arr[i]; 
		}
		
		if(max_so_far < pos){
			max_so_far = pos;
			shall_ans_be_zero = false;
		}
	}
	
	if(shall_ans_be_zero == true){
		max_so_far = 0;
	}
	
	printf("%d", max_so_far);
}