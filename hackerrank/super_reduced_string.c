#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char input[100];
    
    scanf("%s", &input);
    
    int size = strlen(input), found = 1;
    
    while(found == 1){
        found = 0;
        char prev = input[0], o = 0;
        int last_index;
        for(int i = 0; i<size; i++){
            if(input[i] == '*')  continue;
          
            if(prev == input[i]) 
            {
                o++;
                if(o == 1) last_index = i;
                if(o == 2){
                    found = 1;
                    prev = '*';
                    input[i] = '*';
                    input[last_index] = '*';
                }
            }else{
                o = 1; prev = input[i];last_index = i;
            }
            
        }
        
    }
    
    int printed = 0;
    
    for(int i = 0; i<size; i++){
        if(input[i] != '*'){
            printed++;
            printf("%c",input[i]);
        }
    }
    
    if(printed == 0) printf("Empty String");
    
    return 0;
    
}
