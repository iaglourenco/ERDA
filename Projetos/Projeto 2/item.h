#ifndef ITEM_H_
#define ITEM_H_
typedef struct Tipoitem item;

struct Tipoitem //struct para as matrizes, com nomes , dimensoes e valores---
{
	char chave[50];
	int frequencia;
};

item *alocaItem(char palavra[]);

void addFrequencia(item **pItem);

void printItem(item *pItem, int op);

int comparaItem(item *pItem, char palavra[]);

void salvaItem(item *pItem, FILE **arquivo);

#endif
