#include <stdio.h>
#include <stdlib.h>
 
int main(){
    int r;
    int i;
    srand((int)time(0));
    for(i = 0; i < 5; ++i){
        r = rand();
        printf("Rand %d is %d\n",i, r);
    }    
}
 
