#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Item.h"


//qualquer manipulacao dos nós da arvore eh feita por esta biblioteca


void addNovoItem(NO **no,char item[]){
//adiciona novo item ao no da arvore e inicia sua frequencia
  strcpy((*no)->palavra,item);
  (*no)->count=1;
  (*no)->esq = (*no)->dir = NULL;
}

void incrementaFreq(NO **no){ (*no)->count++; }//o nome a diz tudo :)
