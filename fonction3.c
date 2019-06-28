#include"TP2.h"
#include <time.h>
#include <stdlib.h>


int factorielle( int a  )
{


    if (a==0 ||a==1)
    {
        return 1;
    }
    return (a*factorielle(a-1));
}

int fact1(int a)
{
    int f=1;
    while(a!=0)
    {
        f*=a--;

    }
    return f;
}


int ** allocation( int n) /* lit une matrice (au clavier) */
{

    int **m=malloc(n*sizeof(int*));

    for (int i=0; i<n; i++)
    {
        int aleatoire=rand()%20;
//t[l][c]=aleatoire;
        m[i]=malloc(n*sizeof(int));


    }
    return m;
}

void desallocation(int **m,int n)
{
    for (int i=0; i<n; i++)
    {
        free (m[i]);
    }
    free (**m);
}

void remplir (int **m,int n)
{
    srand(time(NULL));
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {

            int aleatoire=rand()%10;
            m[i][j]=aleatoire;
            printf("%d  ",m[i][j]);
        }
        printf("\n");
    }




}


int **extraire_mat(int **m,int n,int l,int c)
{
    int **sous_mat=allocation(n-1);
    int i,j,i1,j1;
    for (i=0; i<n,i!=l,j!=l; i++)
    {
        for (j=0; j<n; j++)
        {
            sous_mat[i1][j1]=m[i][j];
            j1++;


        }
        i1++;
    }

}

int determinant(int **m,int n)
{
    if (n==1)return m[0][0];
    int det=0;
    int c=0,i;
    int signe=1;
    int**sous_m;
    sous_m=extraire_mat(m,n,i,c);
    for (i=0; i<n; i++)
    {
        det+=m[i][c]*signe;
        determinant(sous_m,n-1);
        desallocation(sous_m,n-1);
        signe*=-1;
    }



  int fibo1(int n) {
  if (n == 0) { return 0; }
  if (n == 1) { return 1; }
  return fibo1(n - 2) + fibo1(n - 1);
}

    int fibo2(int n)
    {
        if (n==0||n==1)
        {
            return n;
        }
        if(n%2 !=0)
        {
            int tem1=fibo2(n/2);
            int tem2=fibo2(n/2+1);
            return tem1*tem2+tem2*tem2;
        }
        else
        {
            int term=fibo2(n/2);
            return term*term+2*term*fibo2(n/2-1);

        }


    }


