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

int inserir(NO **raiz,char palavra[]){
//insere palavra na arvore, retorna 1 se OK, 0 se não
  if(!(*raiz)){
    (*raiz) = (NO *) malloc(sizeof(NO));

    if(!(*raiz)) return 0; //Heap Overflow

    if(addItem(&(*raiz),palavra))
      return 1; //OK
    else
      return 0;//ERRO
  }

  if(strcmp((*raiz)->palavra,palavra)==0)//iguais
  {
    if(incrementaFreq(&(*raiz)))//frequencia++
      return 1;//OK
    else
      return 0;//ERRO
  }
  if(strcmp((*raiz)->palavra,palavra)<0)//vou pra esq
    return inserir(&(*raiz)->esq,palavra);

  if(strcmp((*raiz)->palavra,palavra)>0)//vou pra dir
    return inserir(&(*raiz)->dir,palavra);
}

int verificaExistencia(NO *raiz,char palavra[]){
//verifica a existencia da palavra na arvore
//retorna 1 se for encontrada, 0 se contrário

  if(!raiz) return 0; //arvore vazia

  if(strcmp(raiz->palavra,palavra) == 0)  return 1;//achei a palavra

return verificaExistencia(raiz->esq,palavra) || verificaExistencia(raiz->dir,palavra);//verifica a arvore inteira

}
