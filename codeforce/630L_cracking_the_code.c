#include <stdio.h>

int power_mod(unsigned long long int x, int p, unsigned long long int mod){

  unsigned long long int ans = 1;
  while(p>0){
    
   if(p & 1)
	ans = (x*ans)%mod;

   x = (x*x)%mod;

   p = p>>1;
 }
 
  return ans;
}

int shuffle_no(int no){
   int temp = (no/10000) *10000;
   temp += ((no/100)%10) *1000;
   temp += ((no)%10) *100;
   temp += ((no/10)%10) *10;
   temp += ((no/1000)%10);

   return temp;
}

int main(){

  int n, code;
  while(scanf("%d", &n) != EOF){
    code = shuffle_no(n);
    code = power_mod(code,5,100000);

    printf("%05d\n", code);
  }
  return 0;
}