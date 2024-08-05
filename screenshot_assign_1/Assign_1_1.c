#include<stdio.h>
#include<omp.h>

int main()
{
#pragma omp parallel
printf("Hii world\n");
return 0;
}
