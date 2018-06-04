/*
Integrante 1 - Nome:Iago Jardim Lourenço RA: 15610116
Integrante 2 - Nome:Bruno Camilo Silvério RA: 16080293

Resultados obtidos: ____________________________________________________
Projeto básico: _____ % concluído - Obs: ___________________________________
( ) Opcional 1 - Obs: ____________________________________________________
( ) Opcional 2 - Obs: ____________________________________________________
( ) Opcional 3 - Obs: ____________________________________________________
( ) Opcional 4 - Obs: ____________________________________________________
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ST.h"
#include "Item.h"



int main(int argc,char *argv[]){

NO *raiz = NULL;
char op,carac,palavra[50];
int n=0,i=0;


if(argc > 1){
  for(i=1;i < argc;i++){
    op = argv[i][1];
    switch (op) {
      case 'n':
        n = atoi(&argv[i][2]);//transforma ASC em int
      break;



    }



  }
}else{
  printf("ARGUMENTOS INSUFICIENTES\n");
  exit(0);
}

if(n){
  i=0;
  carac = fgetc(stdin);//pega um caracter da stdin

  while(!feof(stdin)){
    if((carac > 64 && carac < 91) || (carac > 96 && carac < 123)){ // verificacao pra saber se o caracter pego eh uma letra
      palavra[i]= carac;
      i++;
    }else{
      palavra[i]='\0';

      if(strlen(palavra) > 0)
        inserir(&raiz,palavra);

    }
    carac = fgetc(stdin);
  }

}











}
