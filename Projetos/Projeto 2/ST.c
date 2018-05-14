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
