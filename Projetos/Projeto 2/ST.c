#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "ST.h"


struct no{

  char palavra[50];
  int count;
  NO *esq, *dir;
};

void criaVazia(NO **raiz){
  (*raiz) = NULL;
}

int verificaExistencia(NO *raiz,char palavra[]){
//verifica a existencia da palavra na arvore
//retorna 1 se for encontrada, 0 se contrário

  if(!raiz) return 0; //arvore vazia

  if(strcmp(raiz->palavra,palavra) == 0)  return 1;//achei a palavra

  if(strcmp(raiz->palavra,palavra)<0) return verificaExistencia(raiz->esq,palavra);//vou pra esq

  if(strcmp(raiz->palavra,palavra)>0) return verificaExistencia(raiz->dir,palavra);//vou pra dir

return verificaExistencia(raiz->esq,palavra) && verificaExistencia(raiz->dir,palavra);//verifica a arvore inteira

}




}
