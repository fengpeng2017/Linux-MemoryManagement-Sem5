#include <stdio.h>
#include <stdlib.h>

#define A_MB (1024 * 1024)
int main(int argc, char const *argv[])
{
char(*mem_to_all);
int megaB = A_MB;
int exit_code = EXIT_FAILURE;
mem_to_all = (char *)malloc(megaB);
if (mem_to_all != NULL)
{
sprintf(mem_to_all, "Vung nho da duoc cap phat\n");
printf("%s", mem_to_all);
malloc_stats();
exit_code = EXIT_SUCCESS;
}
exit(exit_code);
}
