#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ordena.h"

void ordenaDigitos (int **A, int n, int posicao){
    int B[10];
    for (int i = 0; i < 10; i++){
        B[i] = 0; // zera todos os valores de B
    }

    int digito;
    for (int i = 0; i < n; i++){
        digito = A[i][0]/posicao;
        digito = digito % 10; // seleciona o algarismo da posição desejada
        B[digito] = B[digito] + 1; // soma quantos números tem esse determinado algarismo
    }

    for (int i = 1; i < 10; i++){
        B[i] = B[i] + B[(i-1)];  // atribui o atual como a soma de si mais o anterior 
    }

    int C[n][2];

    for (int i = (n-1); i >= 0; i--){
        digito = A[i][0]/posicao;
        digito = digito % 10; // seleciona o algarismo da posição desejada
        B[digito] = B[digito] - 1; 
        C[B[digito]][0] = A[i][0]; // coloca na menor posição de uma matriz temporária o numero com dígito menor
        C[B[digito]][1] = A[i][1];
    }

    for (int i = 0; i < n; i++){
        A[i][0] = C[i][0]; // passa da matriz temporária para a matriz A
        A[i][1] = C[i][1];
    }
}

void ordenaNumeros(int **A, int n){
    int maior = A[0][0]; // atribui como se o maior já fosse o primeiro número
    for (int i = 1; i < n; i++){
        if (A[i][0] > maior){ // testa se o da posição atual é maior que o maior já achado
            maior = A[i][0];
        }
    }
    int posicao = 1;
    
    while(maior/posicao > 0){ // enquanto a posição não chega ao número com maior algarismos
        ordenaDigitos(A, n, posicao); 
        posicao = posicao * 10; // muda para a próxima posição
    }
}