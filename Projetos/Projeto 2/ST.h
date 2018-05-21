#ifndef ST_H_
#define ST_H_


typedef struct no NO;
struct no{

  char palavra[50];
  int count;
  NO *esq, *dir;
};

void criaVazia(NO **raiz);
int verificaExistencia(NO *raiz,char palavra[]);//verifica a existencia da palavra na arvore
int inserir(NO **raiz,char palavra[]);//faz o que o nome diz :)





#endif
