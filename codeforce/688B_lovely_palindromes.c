#include <stdio.h>

int main(){
 
  unsigned long long int l, i;
  char out[100000];

  scanf("%s", out);

  for(i=0; out[i] != '\0'; i++){
    printf("%c", out[i]);
    l++;
 }

 for(i = l; i>0; i--) printf("%c", out[i-1]);

 printf("\n");
  return 0;
}