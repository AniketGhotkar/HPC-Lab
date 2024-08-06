#include<stdio.h>
#include<omp.h>

int main() 
{

printf("Sequential : \n");
for(int i = 0 ; i<5 ; i++)
{
printf("omp \n");
}

printf("\n");
printf("Parallel : \n");

#pragma omp parallel 

printf("qwerty \t %d \n",omp_get_thread_num());
return 0;
}
