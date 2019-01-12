#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int RandomNum(int max){
    srand((unsigned int)time(0));
    return rand()%max;
}