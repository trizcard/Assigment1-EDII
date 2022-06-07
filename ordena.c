#include <stdio.h>
#include <math.h>

int ordenaDigitos (int **A, int n, int posicao){
    int B[10];
    int digito;
    for (int i = 0; i < n; i++){
        digito = A[i][0]/posicao;
        digito = digito % 10;
        B[digito] = B[digito] + 1;
    }

    for (int i = 1; i < 10; i++){
        B[i] = B[i] + B[i-1];
    }

    int C[n][2];

    for (int i = n-1; i >= 0; i--){
        digito = A[i][0]/posicao;
        digito = digito % 10;
        B[digito] = B[digito] - 1;
        C[B[digito]][0] = A[i][0];
        C[B[digito]][1] = A[i][1];
    }

    for (int i = 0; i < n; i++){
        A[i][0] = C[i][0];
        A[i][1] = C[i][1];
    }
}
