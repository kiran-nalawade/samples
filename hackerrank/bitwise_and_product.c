#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    
    int T, tc;
    scanf("%d", &T);
    
    for(tc = 1; tc<=T; tc++){
        unsigned long long int ans = -1 , ans1 = -1, start, end, i;
        scanf("%llu %llu",&start, &end);
                
       while(end >= start){
           ans = ans & (start++);
           ans1 = ans1 & (end--);
       }
        
        printf("%llu\n", (ans&ans1));
    }
    

    return 0;
}