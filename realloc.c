#include <stdio.h>
#include <stdlib.h>
int main()
{
int n;
printf("Nhap size cua mang:");
scanf("%d",&n);
int *A = (int *)malloc(n*sizeof(int));
printf("Mang duoc cap phat voi malloc():");
for(int i=0;i<n;i++) printf("%d ",A[i]);
printf("\n");
int *B = (int *)calloc(n,sizeof(int));
printf("Mang duoc cap phat voi calloc():");
for(int i=0;i<n;i++) printf("%d ",B[i]);
printf("\n");
for(int i=0;i<n;i++) A[i]=i+1;//dat gia tri cho mang malloc
int *C = (int *)realloc(A,2*n*sizeof(int)); //Resize mang thanh mot mang 2n phan tu
printf("Mang duoc resize:");
for(int i=0;i<2*n;i++) printf("%d ",C[i]);
printf("\n");
free(A); // giai phong A
int *D = (int *)realloc(B,0);//giai phong B
}

