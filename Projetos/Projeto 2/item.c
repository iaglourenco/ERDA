#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"


item *alocaItem(char palavra[50])// aloca o item 
{
	item *pItem = (item *)malloc(sizeof(item));
	strcpy(pItem->chave,palavra);
	pItem->frequencia = 1;
	return pItem;
}

int comparaItem(item *pItem, char palavra[])//faz as comparacoes para ver se a palavra precede a outra ou nao
{
	if(strcmp(palavra, pItem->chave) == 0)
	{	
		return 0;
	}	
	else if(strcmp(palavra, pItem->chave) > 0)
	{	
		return 1;
	}
	else if(strcmp(palavra, pItem->chave) < 0)
	{	
		return -1;
	}
}

void addFrequencia(item **pItem)
{
	(*pItem)->frequencia = (*pItem)->frequencia + 1;//incrementa a frequencia em 1
}

void printItem( item *pItem, int op)//printa as informacoes do item
{
	if(op == 1)//printa ambos nome e frequencia
	{
		printf("%s ", pItem->chave);
		printf("%i ", pItem->frequencia);
	}
	if(op == 2)//printa somente o nome
	{
		printf("%s\n", pItem->chave);
	}
}

void salvaItem(item *pItem, FILE **arquivo)
{
	fprintf(*arquivo, "%s %i/", pItem->chave, pItem->frequencia);// escreve no arquivo a ser criado
}
