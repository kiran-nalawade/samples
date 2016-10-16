#include <stdio.h>

unsigned long long int find_damaged_cells(int n){

  unsigned long long int cells = 1, counter;

  cells += 6.0 * n*(n+1)/2.0;

  return cells;
}

int main(){
  
  unsigned long long int n, ans;
 
  while(scanf("%llu",&n)!=EOF){

  	ans = find_damaged_cells(n);
 	printf("%llu\n", ans);
   }

  return 0;
}