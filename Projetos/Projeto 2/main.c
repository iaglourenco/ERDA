/*
Integrante 1 - Nome:Bruno Camilo  ___________________________ RA:16080293
Integrante 2 - Iago Lourenço ________________________________ RA:15610116
Resultados obtidos: Com a resolucao do projeto obtivemos os resultados proposto pelo professor, conseguindo atraves de um programa inicializado junto ao programa obter as n palavras mais frequentes, procurar por uma palavra pedida pelo usuario , criar um arquivo em formato .txt com a tabela de codigos, e por fim com seguimos printar na tela a arvore binaria numa configuracao pedida pelo professor (modo arvore).
Projeto básico: 100 % concluído - Obs: ____________________________________
(X) Opcional 1 - Obs: A funcao opcional so cria um novo arquivo e caso o usuario digite -r e -w so faz o -w, nao le um arquivo ja existente.
(X) Opcional 2 - Obs: _____________________________________________________
( ) Opcional 3 - Obs: _____________________________________________________
(X) Opcional 4 - Obs: A arvore printada nao esta completamente igual a do exemplo nos slides.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "ST.h"
#include <sys/time.h>

int main(int argc, char *argv[])
{
	int nPalavra = 0, tamN = 0, i = 2, j = 0, k = 0, nivel = 1, numbuscaPalavraero = 0, aux = 0;
	struct timeval  inicio;

	char num[50], palavra[50], ch, op, narquivo[50],tipo , tipo2;
	freq *Freq;
	Arv *ArvItem;
	FILE *Arquivo;

	op = argv[1][1];//pega a operacao requesitada pelo usuario
	criaArv(&ArvItem);
	criaLista(&Freq);

	if(op == 'n' && argc == 2)//printa as n palavras mais frequentes
	{
		while(argv[1][i] != '\0')//pega o numero de palavra que irao se repetir
		{
			num[j] = argv[1][i];
			i++;
			j++;
		}
		num[j] = '\0';
		tamN = atoi(num);

		scanf("%c", &ch);
		while(!feof(stdin))//vai retirando os caracteres do buffer e formando as palavras
		{
			if((ch > 64 && ch <91) || (ch >96 && ch < 123))
			{
					palavra[k] = ch;
					k++;
			}
			else
			{
				palavra[k] = '\0';
				k = 0;
				if(strlen(palavra) > 0)// evita de entrar \0 na arvore e na lista
				{
					insereArvore(&ArvItem, palavra);//insere a palvra na arvore
					insereLista(&Freq, palavra);//insere a palavra na lista
				}
			}
			scanf("%c", &ch);
			if(ch == EOF)//pega a ultima palavra do buffer
			{
				palavra[k] = '\0';
				k = 0;
			}
		}
		maisFrequente(&Freq);//ordena a lista
		printfF(Freq, tamN);//printa as n palavras mais frequentes
	}

	else if(argc >= 3)
	{
		if(argc == 3)
		{
			if(op == 'n')//printa as n palavras mais frequentes
			{
				while(argv[1][i] != '\0')//pega o numero de palavra que irao se repetir
				{
					num[j] = argv[1][i];
					i++;
					j++;
				}
				num[j] = '\0';
				tamN = atoi(num);
				tipo = argv[2][1];//ve se e r ou w
				if(tipo == 'w')
				{
					i = 2;
					j = 0;
					while(argv[2][i] != '\0')//pega o nome do arquivo a ser salvo
					{
						narquivo[j] = argv[2][i];
						i++;
						j++;
					}
					strcat(narquivo,".txt");
					scanf("%c", &ch);
					while(!feof(stdin))//vai retirando os charcters do buffer e formando as palavras
					{
						if((ch > 64 && ch <91) || (ch >96 && ch < 123))
						{
							palavra[k] = ch;
							k++;
						}
						else
						{
							palavra[k] = '\0';
							k = 0;
							if(strlen(palavra) > 0)// evita de entrar \0 na arvore e na lista
							{
								insereArvore(&ArvItem, palavra);//insere a palvra na arvore
								insereLista(&Freq, palavra);//insere a palavra na lista
							}
						}
						scanf("%c", &ch);
						if(ch == EOF)//pega a ultima palavra do buffer
						{
							palavra[k] = '\0';
							k = 0;
						}
					}
					maisFrequente(&Freq);//ordena a lista
					printfF(Freq, tamN);//printa as n palavras mais frequentes
					Arquivo = fopen(narquivo, "w");
					if(Arquivo == NULL)
					{
						printf("Nao foi possivel criar o arquivo\n");
					}
					else
					{
						salvaTabela(ArvItem, &Arquivo);//escreve a arvore binaria no arquivo;
					}
					fclose(Arquivo);
				}
			}
		}
		if(argc == 4)
		{
			if(op == 'n')//printa as n palavras mais frequentes
			{
				while(argv[1][i] != '\0')//pega o numero de palavra que irao se repetir
				{
					num[j] = argv[1][i];
					i++;
					j++;
				}
				num[j] = '\0';
				tamN = atoi(num);
				tipo = argv[2][1];//ve se e r ou w
				tipo2 = argv[3][1];//ve se e r ou w
				if(tipo == 'w' || tipo2 == 'w')
				{
					if(tipo == 'w' ) aux = 2;
					else aux = 3;
					i = 2;
					j = 0;
					while(argv[aux][i] != '\0')//pega o nome do arquivo a ser salvo
					{
						narquivo[j] = argv[aux][i];
						i++;
						j++;
					}
					strcat(narquivo,".txt");
					scanf("%c", &ch);
					while(!feof(stdin))//vai retirando os charcters do buffer e formando as palavras
					{
						if((ch > 64 && ch <91) || (ch >96 && ch < 123))
						{
							palavra[k] = ch;
							k++;
						}
						else
						{
							palavra[k] = '\0';
							k = 0;
							if(strlen(palavra) > 0)// evita de entrar \0 na arvore e na lista
							{
								insereArvore(&ArvItem, palavra);//insere a palvra na arvore
								insereLista(&Freq, palavra);//insere a palavra na lista
							}
						}
						scanf("%c", &ch);
						if(ch == EOF)//pega a ultima palavra do buffer
						{
							palavra[k] = '\0';
							k = 0;
						}
					}
					maisFrequente(&Freq);//ordena a lista
					printfF(Freq, tamN);//printa as n palavras mais frequentes
					Arquivo = fopen(narquivo, "w");
					if(Arquivo == NULL)
					{
						printf("Nao foi possivel criar o arquivo\n");
					}
					else
					{
						salvaTabela(ArvItem, &Arquivo);//escreve a arvore binaria no arquivo;
					}
					fclose(Arquivo);
				}
			}
		}
	}

	else if(op == 's' && argc == 2)//printa uma palavra procurada
	{
		scanf("%c", &ch);
		while(!feof(stdin))//vai retirando os charcters do buffer e formando as palavras
		{
			if((ch > 64 && ch <91) || (ch >96 && ch < 123))
			{
					palavra[k] = ch;
					k++;
			}
			else
			{
				palavra[k] = '\0';
				k = 0;
				if(strlen(palavra) > 0)// evita de entrar \0 na arvore e na lista
				{
					insereArvore(&ArvItem, palavra);//insere a palvra na arvore
				}
			}
			scanf("%c", &ch);
			if(ch == EOF)//pega a ultima palavra do buffer
			{
				palavra[k] = '\0';
				k = 0;
			}
		}
		while(argv[1][i] != '\0')//pega a palavra que o usuario deseja consultar
		{
			num[j] = argv[1][i];
			i++;
			j++;
		}
		num[j] = '\0';

		gettimeofday(&inicio,NULL);
		buscaPalavra(ArvItem, num, nivel, inicio);
	}

	else if (op == 'p')
	{
		while(argv[1][i] != '\0')//pega o numero de palavra que irao se repetir
		{
			num[j] = argv[1][i];
			i++;
			j++;
		}
		num[j] = '\0';
		scanf("%c", &ch);
		while(!feof(stdin))//vai retirando os charcters do buffer e formando as palavras
		{
			if((ch > 64 && ch <91) || (ch >96 && ch < 123))
			{
					palavra[k] = ch;
					k++;
			}
			else
			{
				palavra[k] = '\0';
				k = 0;
				if(strlen(palavra) > 0)// evita de entrar \0 na arvore e na lista
				{
					insereArvore(&ArvItem, palavra);//insere a palvra na arvore
				}
			}
			scanf("%c", &ch);
			if(ch == EOF)//pega a ultima palavra do buffer
			{
				palavra[k] = '\0';
				k = 0;
			}
		}
		tamN = atoi(num);
		printArvore(ArvItem, tamN, nivel);
	}
	return 0;
}
