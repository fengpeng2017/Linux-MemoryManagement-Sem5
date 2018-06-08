#ifdef USE_MAP_ANON
#define _BSD_SOURCE
#endif  
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
/*Là con trỏ đến một vùng bộ nhớ được chia sẻ trước đó*/    
int *addr;   

#ifdef USE_MAP_ANON      /*sử dụng MAP_ANONYMOUS*/           
 addr = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);     
 if (addr == MAP_FAILED) {     
     fprintf(stderr, "mmap() failed\n");     
     exit(EXIT_FAILURE);
 }      

#else        /*Map /dev/zero*/     
int fd;    
fd = open("/dev/zero", O_RDWR);      
if (fd == -1) {    
    fprintf(stderr, "open() failed\n");
    exit(EXIT_FAILURE);
}    

addr = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);    
if (addr == MAP_FAILED) {    
    fprintf(stderr, "mmap() failed\n");    
    exit(EXIT_FAILURE);    
}     

if (close(fd) == -1) {          
    fprintf(stderr, "close() failed\n");    
    exit(EXIT_FAILURE);    
}
#endif    
*addr = 1;      /*Khởi tạo một kiểu int trong vùng nhớ đó*/    

switch(fork()) {        /*Tiến trình cha con share ánh xạ cho nhau*/     
case -1:    
    fprintf(stderr, "fork() failed\n");
    exit(EXIT_FAILURE);    

case 0:         /*Tiến trình con tăng biến int và kết thúc*/     
    printf("Child started, value = %d\n", *addr);    
    (*addr)++;    

    if (munmap(addr, sizeof(int)) == -1) {    
        fprintf(stderr, "munmap()() failed\n");    
        exit(EXIT_FAILURE);    
    }     
    exit(EXIT_SUCCESS);     

default:        /*Tiến trình cha đợi con kết thúc*/      
    if (wait(NULL) == -1) {    
        fprintf(stderr, "wait() failed\n");    
        exit(EXIT_FAILURE);      
    }     

    printf("In parent, value = %d\n", *addr);         
    if (munmap(addr, sizeof(int)) == -1) {       
        fprintf(stderr, "munmap()() failed\n");      
        exit(EXIT_FAILURE);       
    }        
    exit(EXIT_SUCCESS);
}



