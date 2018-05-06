//matriz.h
// Projeto 1 matrizes
// Iago Lourenço 15610116
// Bruno Camilo 16080293
#ifndef MATRIZ_H_
#define MATRIZ_H_

//declaração da struct
typedef struct no NO;

//declaração das funções
float **alocarMatriz(int m, int n);
float **transporMatriz(NO *l1,int **l,int **c);
void atribuiElemento(NO **lista,int linha, int coluna,float valor);
void atribuiElementoLinha(NO **lista, int linha, int totalcoluna,float vl[]);
void atribuiElementoColuna(NO **lista, int coluna, int totallinha,float vl[]);
float **somaMatriz(NO *l1, NO *l2,int **l, int **c);
float **divideElemento(NO *l1, NO *l2,int **l, int **c);
float **multiplicaMatriz(NO *l1, NO *l2,int **l, int **c);
float **multiplicaElemento(NO *l1, NO *l2,int **l, int **c);


#endif
