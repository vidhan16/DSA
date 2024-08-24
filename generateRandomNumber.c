#include <stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    srand(time(NULL));//To start randomgenerator (Seed, only one time in life of program.)
    for(int i = 0 ; i < 3 ; i++){
        printf("%d\n",rand());
    }
    return 0;
}