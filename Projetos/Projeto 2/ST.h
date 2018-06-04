#ifndef ST_H_
#define ST_H_
#include "item.h"
typedef struct TipoArv Arv;

struct TipoArv //struct para as matrizes, com nomes , dimensoes e valores
{
	item *Item;
	Arv *pai, *esq, *dir;
	
};

typedef struct Freq freq;

void criaLista(freq **pFreq);

void criaArv(Arv **pArv);

void insereArvore(Arv **pArv, char palavra[]);

void insereLista (freq **pFreq, char palavra[]);

void buscaPalavra(Arv *Arv, char palavra[], int nivel, struct timeval inicio);

void maisFrequente(freq **Freq);

void printfF(freq *Freq, int n);

void printArvore(Arv *Arv, int Max, int aux);

void salvaTabela(Arv *Arv, FILE **arquivo);

#endif
