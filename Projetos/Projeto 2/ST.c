#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "ST.h"
#include <time.h>
#include <sys/time.h>

struct Freq //struct para as matrizes, com nomes , dimensoes e valores---
{
	char chave[50];
	int frequencia;
	freq *prox;
};

void criaLista(freq **pFreq)//cria lista ligada freq 
{
	*pFreq = NULL;
}

void criaArv(Arv **pArv)//cria a arvore binaria
{
	*pArv = NULL;
}

void insereArvore(Arv **pArv, char palavra[])//insere na arvore as informacoes passadas
{
	if((*pArv) == NULL)
	{
		*pArv=(Arv *)malloc(sizeof(Arv));
		(*pArv)->Item =alocaItem(palavra);
		(*pArv)->esq = NULL;
		(*pArv)->dir = NULL;
		
	}
	else if(comparaItem((*pArv)->Item, palavra) == 0)
	{
		addFrequencia(&(*pArv)->Item);
	}
	else if(comparaItem((*pArv)->Item, palavra) == -1)
	{
		insereArvore(&(*pArv)->esq, palavra);
	}
	else if(comparaItem((*pArv)->Item, palavra) == 1)
	{
		insereArvore(&(*pArv)->dir, palavra);
	}
}

void insereLista (freq **pFreq, char palavra[])
{
		int i = 0;
		freq *aux, *insere;
		insere = (freq *)malloc(sizeof (freq));
		strcpy(insere->chave, palavra);
		insere->frequencia = 1;
		insere->prox = NULL;
		if(*pFreq)// caso aluno seja null ira retornar 0 , logo e falso e nao entra no if
		{
			aux = *pFreq;// passa o endenreco que aluno aponta para aux, com isso aux aponta pro mesmo endereco que aluno
			while(aux->prox)// caso aux -> prox seja null ira retornar 0 , logo e falso e quebra o loop
			{
				if(strcmp(aux->chave,palavra) == 0)
				{
					aux->frequencia = aux->frequencia + 1;
					i = 1;
					break;
				}
				aux = aux->prox;//percorre toda a lista ate o fim
			}
			//printf("%s ", aux->chave);
			if(i == 0) aux->prox = insere;
		}
		else
		{
			*pFreq = insere;
		}	
}


void maisFrequente(freq **Freq)//ordena a lista ligada de acorda com a frequencia das palavras
{
	freq *aux, *aux2, *aux3, *aux4;
	if(*Freq)
	{
		aux = *Freq;
		while(aux)
		{
			aux2 = *Freq;
			aux4 = *Freq;
			aux2 = aux2->prox;
			while(aux2)
			{
				if(aux4->frequencia < aux2->frequencia)//verifica se a palavra atual tem menor frequencia que a anterior se sim troca de posicao e continua comparando ate o fim da lista
				{	
					aux3->frequencia = aux4->frequencia;
					aux4->frequencia = aux2->frequencia;
					aux2->frequencia = aux3->frequencia;
					strcpy(aux3->chave,aux4->chave);
					strcpy(aux4->chave,aux2->chave);
					strcpy(aux2->chave,aux3->chave);
				}
				else
				{
					if(aux4->frequencia == aux2->frequencia)//caso a frequencia de ambas as palavras sejam iguais ele compara se ela procede ou nao gramaticalmente a proxima palavra, se nao se mantem
					{	
						if(strcmp(aux4->chave, aux2->chave) > 0)
						{	
							aux3->frequencia = aux4->frequencia;
							aux4->frequencia = aux2->frequencia;
							aux2->frequencia = aux3->frequencia;
							strcpy(aux3->chave,aux4->chave);
							strcpy(aux4->chave,aux2->chave);
							strcpy(aux2->chave,aux3->chave);
						}
					}
				}
				aux4 = aux4->prox;
				aux2 = aux2->prox;
			}
			aux = aux->prox;
		}
	}
	
}

void printfF(freq *Freq , int n)//printa a frequencia das palavras mais frequentes e sua respectiva palavra
{
	int i = 0;
	freq *aux;
	aux = Freq;
	while(Freq && (i != n))//printa a frequencia e o codigo das palavras
	{	
		printf("%i %s\n",Freq->frequencia ,Freq->chave);
		Freq = Freq->prox;
		i++;
	}	
	
}

void buscaPalavra(Arv *Arv, char palavra[], int nivel, struct timeval  inicio)
{
	struct timeval  fim;
	if(Arv == NULL)
	{
		return;
	}
	else if(comparaItem(Arv->Item, palavra) == 0)//caso uma palavra bate com a requisitada pelo usuario ele ira printa ela o nivel e o tempo que levou para achar
	{
		gettimeofday(&fim,NULL);
		printItem(Arv->Item,1);
		printf("%i %lf\n", nivel,(double)(fim.tv_sec - inicio.tv_sec)/1000000);
	}
	else if(comparaItem(Arv->Item, palavra) == -1)
	{
		buscaPalavra(Arv->esq, palavra, nivel + 1, inicio);
	}
	else if(comparaItem(Arv->Item, palavra) == 1)
	{
		buscaPalavra(Arv->dir, palavra, nivel + 1, inicio);
	}
}

void printArvore(Arv *Arv, int Max, int aux)// printa a arvores no formato pedido
{
	int i = 0;
	
		if((Max + 1) == aux) return;//caso a arvore binaria chegue no nivel maximo passado pelo usuario o programa retorna pra main
		if(aux == 1)
		{
			if(Arv != NULL)  printItem(Arv->Item,2); 
		}
		else
	  	{  
			if(aux != 2)
			{
				printf("|");
				for(i = 1;i<aux;i++)//printa espacos de acordo com o nivel da arvore
				{
					printf(" ");
				}
			}
			printf("|");
			printf("-");
			if(Arv != NULL) printItem(Arv->Item,2);
		}	
	if(Arv != NULL) //percorre a arvore binaria
	{	
		printArvore(Arv->esq,Max,aux + 1);         /* imprime no esquerdo */
		printArvore(Arv->dir,Max, aux + 1);         /* imprime no direito */
	}
	else
	{
		printf("NULL\n");
	}
}
void salvaTabela(Arv *Arv, FILE **arquivo)
{
	if(Arv != NULL) // percorre a arvore recursiva mente e salvando no arquivo a cada no
	{
		salvaItem(Arv->Item, &(*arquivo));
		salvaTabela(Arv->esq, &(*arquivo));
		salvaTabela(Arv->dir, &(*arquivo));
	}	
}
