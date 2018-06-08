#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
int main (int argc, char const * argv[]){
    int *x, *y;
    x=malloc(5*sizeof(int));
    malloc_stats();
    if(!x) {
        perror ("malloc");
        return -1;
    }
    y=calloc(5,sizeof(int));
    if(!y){
        perror("calloc");
        return -1;
    }
}
