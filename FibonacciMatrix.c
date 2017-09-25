#include <stdio.h>

void multiply(int F[2][2], int M[2][2]);

void power( int F[2][2], int n);

/* function that returns nth Fibonacci number */
 int fib( int n){
    int F[2][2] = {{1,1},{1,0}};
    if (n == 0)
        return 0;
    power(F, n-1);
    return F[1][0];
}

void power( int F[2][2],int n) {
     int M[2][2] = {{1,1},{1,0}};
    while(n>0) {

        if (n % 2 != 0)
            multiply(M, F);

        multiply(F, F);
        n=n/2;
    }
    for (int k = 0; k <2 ; ++k) {
        for (int l = 0; l < 2; ++l) {
            F[k][l] = M[k][l];
        }
    }
}

void multiply( int F[2][2], int M[2][2]) {
    int x =  (F[0][0]*M[0][0])%1000;
    int x1 = (F[0][1]*M[1][0])%1000;
    int y =  (F[0][0]*M[0][1])%1000;
    int y1 = (F[0][1]*M[1][1])%1000;
    int z =  (F[1][0]*M[0][0])%1000;
    int z1= (F[1][1]*M[1][0])%1000;
    int w =  (F[1][0]*M[0][1])%1000;
    int w1 = (F[1][1]*M[1][1])%1000;

    F[0][0] = (x+x1)%1000;
    F[0][1] = (y+y1)%1000;
    F[1][0] = (z+z1)%1000;
    F[1][1] = (w+w1)%1000;
}

/* Driver program to test above function */
int main()
{
    int n = 23456;
    printf("%ld", fib(n));
    return 0;
}
