#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
void *malloc(size_t size) {
 void* p;
 p = sbrk(0);
 		 if (sbrk(size) == (void*)-1) return NULL;
 return p;
}
int main(int argc, char const * argv[]){
    void *p;
    p=malloc(sizeof(int));
    if(p){
        printf("Success");
        printf("\n");
    }
}