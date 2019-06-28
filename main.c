#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TP2.h"
int fibonacci(int n) {
  if (n == 0) { return 0; }
  if (n == 1) { return 1; }
  return fibonacci(n - 2) + fibonacci(n - 1);
}
int main()

{int d,c,n=5;
   /*d =factorielle(10);
   //printf("%d \n",d);
   c=fact1(10);
   //printf("%d",c);
   printf("donnez n : \n");
   scanf("%d",&n);
   int ** mat;
   mat=allocation(n);
   remplir(mat,n);
   desallocation(mat,n);
   //remplir(mat,n);
  //printf("det de notre matrice =%d",determinant(mat,n));
   //desallocation(matrice,n);*/

clock_t s1,e1,s2,e2;
double elapsed1,elapsed2;
s1=clock();
d=fibonacci(6);
printf("%d",d);
//printf("fibo n =%d",fibo1(n));
e1=clock();
elapsed1=(double)(e1-s1)/CLOCKS_PER_SEC;
printf("time=%f \n",elapsed1);




}
