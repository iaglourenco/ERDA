#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Item.h"


//qualquer manipulacao dos nós da arvore eh feita por esta biblioteca


int addNovoItem(NO **node,char item[]){
//adiciona novo item ao no da arvore e inicia sua frequencia

  (*node) = (NO *) malloc(sizeof(NO));

  if(!(*node)) return 0; //Heap Overflow

  strcpy((*no)->palavra,item);
  (*node)->count=1;
  (*node)->esq = (*node)->dir = NULL;
  return 1;
}

void incrementaFreq(NO **node){ (*node)->count++; }//o nome a diz tudo :)
