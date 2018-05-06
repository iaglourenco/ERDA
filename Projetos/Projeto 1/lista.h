//lista.h
// Projeto 1 matrizes
// Iago Lourenço 15610116
// Bruno Camilo 16080293
#ifndef LISTA_H_
#define LISTA_H_

//declaração da struct
typedef struct no NO;

//declaração das funções
void criaVazia(NO **lista);
int inserirMatriz(NO **lista, float **ptM, char nome[], int m , int n);
int destruirMatriz(NO **lista, char nome[]);
void buscaMatriz(NO *lista, NO **lista2, char nome[]);
void imprimirMatriz(NO *lista, char nome[]);
int validaAtribui(NO *lista, char nome[], int *m, int *n, int linha, int coluna);
int validaAtribuiLinha(NO *lista, char nome[], int *m, int *n, int linha, int totalcoluna);
int validaAtribuiColuna(NO *lista, char nome[], int *m, int *n, int coluna, int totallinha);
int validaTranspoe(NO *lista, char nome[],char nomeRes[]);
int validaSoma(NO *lista,char nome[],char nome2[],char nomeRes[]);
int validaDiv1(NO *lista,char nome[],char nome2[],char nomeRes[]);
int validaMult1(NO *lista,char nome[],char nome2[],char nomeRes[]);



#endif
