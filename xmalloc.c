#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
// malloc có thể trả về NULL nhưng xmalloc thì không
void * xmalloc(size_t size) {
    void *p;
    p=malloc(size);
    malloc_stats();
    if (!p) {
        perror("xmalloc");
        exit (EXIT_FAILURE);
    }
    return p;
}
int main(int argc, char const *argv[]){
// cố tình set tham số sai để xem lỗi được in ra
    xmalloc(-1);
}
