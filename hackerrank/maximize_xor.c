#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

int maxXor(int l, int r) {
    int max = INT_MIN;
    int xor ;
    for(int i = l; i<=r; i++){
        for(int j = l; j<=r; j++){
            xor = i ^j;
            if(xor > max) max = xor;
        }
    }
    
    return max;
}
int main() {
    int res;
    int _l;
    scanf("%d", &_l);
    
    int _r;
    scanf("%d", &_r);
    
    res = maxXor(_l, _r);
    printf("%d", res);
    
    return 0;
}
