#ifndef ITEM_H_
#define ITEM_H_

typedef struct no NO;
struct no{

  char palavra[50];
  int count;
  NO *esq, *dir;
};



int addNovoItem(NO **node,char item[]);//adiciona novo item ao no
void incrementaFreq(NO **node);//o nome ja diz tudo :)




#endif
