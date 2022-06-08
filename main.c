#include <stdio.h>
#include <stdlib.h>
#include "ordena.h"

int main(){
    int n;
    scanf("%d", &n);
    int **A;
    A = malloc (n * sizeof(int*));

    for (int i = 0; i < n; i++){
        A[i] = malloc (2 * sizeof(int));
        scanf("%d %d", &A[i][0], &A[i][1]);
    }
    
    ordenaNumeros(A, n);
    
    for (int i = 0; i < n; i++){
        printf("%d %d\n", A[i][0], A[i][1]);
        free(A[i]);
    }
    free(A);
}