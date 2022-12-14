
#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

#define SIZE 1000

int A[10][10] = {   {2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
                    {2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
                    {2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
                    {2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
                    {2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
                    {2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
                    {2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
                    {2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
                    {2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
                    {2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
                };

int B[10][10] = {   {10, 10, 10, 10, 10, 10, 10, 10, 10, 10},
                    {10, 10, 10, 10, 10, 10, 10, 10, 10, 10},
                    {10, 10, 10, 10, 10, 10, 10, 10, 10, 10},
                    {10, 10, 10, 10, 10, 10, 10, 10, 10, 10},
                    {10, 10, 10, 10, 10, 10, 10, 10, 10, 10},
                    {10, 10, 10, 10, 10, 10, 10, 10, 10, 10},
                    {10, 10, 10, 10, 10, 10, 10, 10, 10, 10},
                    {10, 10, 10, 10, 10, 10, 10, 10, 10, 10},
                    {10, 10, 10, 10, 10, 10, 10, 10, 10, 10},
                    {10, 10, 10, 10, 10, 10, 10, 10, 10, 10},
                };

int C[10][10];




int main(int argc, char *argv[])
{
    int N=10;
    for ( int i = 0; i < N; i++ ){
        for ( int j = 0; j < N; j++ ) {
            C[i][j] = 0.0;
            for ( int k = 0; k < N; k++ ){
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }


    for (int i = 0; i < 10; i++){
        for (int j=0; j<10; j++){
		    printf("%d ", C[i][j]);
        }
        printf("\n");
    }
        
}