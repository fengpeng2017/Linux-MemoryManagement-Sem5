#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
 pid_t pid1, pid2, pid3;
 pid1=0, pid2=0, pid3=0;
 pid1= fork(); /* A */
 if(pid1 == 0){
 /* Dưới đây là con của A */
 pid2=fork(); /* B */
 pid3=fork(); /* C */
 } else {
 /* Cha của A */
 /* B và C sẽ không đến được đây*/
 pid3=fork(); /* D */
 if(pid3==0) {
 /* Con của D được fork từ cha A*/
 pid2=fork(); /* E */
}
 if((pid1 == 0)&&(pid2 == 0)) {
 /* trường hợp này sẽ không xảy ra vì pid1 sẽ không bằng 0*/
 printf("Level 1\n");
 }
 if(pid1 !=0) {
 /* Trường hợp này luông đúng cho cha và con của E */
 printf("Level 2\n");
}
 if(pid2 !=0) {
/* Cha của E */
printf("Level 3\n");
 }
 if(pid3 !=0) {
/* Cha của D) */
printf("Level 4\n");
}
}
return 0;
}
