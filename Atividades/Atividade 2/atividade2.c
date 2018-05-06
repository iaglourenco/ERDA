//Atividade#2
//Bruno Camilo Silverio - RA: 16080293
//Iago Jardim Lourenço - RA:15610116

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TipoAluno //struct do aluno
{
  int RA;
  char nome[50];
  float nota;
}Taluno;

typedef struct Gerenciar //gerenciar struct do aluno
{
  Taluno aluno[50]; //quantidade de aluno
  int numAluno; //numero de aluno
}Tgerencia;

Tgerencia cadastrar(Tgerencia gerencia);
Tgerencia removerCadastro(Tgerencia gerencia);
Tgerencia buscarRA(Tgerencia gerenciaRA);
Tgerencia buscarNome(Tgerencia gerenciaNome);
Tgerencia exibirAluno(Tgerencia gerenciaAluno);

int main(){
  int op, i;
  char op2;

  Tgerencia gerencia;
  gerencia.numAluno = 0; //começa com zero alunos

  system("clear");

  do {
    /* code */
    printf("1. Inserir o cadastro de um Aluno\n");
    printf("2. Remover o cadastro de um aluno\n");
    printf("3. Buscar aluno por RA\n");
    printf("4. Buscar aluno por Nome\n");
    printf("5. Exibir dados de todos os alunos cadastrados\n");
    printf("0. Sair\n");
    printf("Opcao: ");
    scanf("%i", &op);

    switch (op) {
      case 1:
      {
        do {
          /* code */
          system("clear");
          printf("<Cadastro de Aluno>\n");
          gerencia = cadastrar(gerencia);
          printf("\nRealizar outro cadastro? (s - n)\n");
          getchar();
          scanf("%c", &op2);
        } while(op2=='s');
        break;
      }

      case 2:
      {
        do {
          /* code */
          system("clear");
          printf("<Remover cadastro de Aluno>\n");
          gerencia = removerCadastro(gerencia);
          printf("\nRemover outro cadastro? (s - n)\n");
          getchar();
          scanf("%c", &op2);
        } while(op2=='s');
        break;
      }

      case 3:
      {
        do {
          /* code */
          system("clear");
          printf("<Buscar aluno por RA>\n");
          gerencia = buscarRA(gerencia);
          printf("\nBuscar outro cadastro? (s - n)\n");
          getchar();
          scanf("%c", &op2);
        } while(op2=='s');
        break;
      }

      case 4:
      {
        do {
          /* code */
          system("clear");
          printf("<Buscar Aluno por Nome>\n");
          gerencia = buscarNome(gerencia);
          printf("\nBuscar outro cadastro? (s - n)\n");
          getchar();
          scanf("%c", &op2);
        } while(op2=='s');
        break;
      }

      case 5:
      {
        do {
          /* code */
          system("clear");
          printf("<Exibir Alunos cadastrados>\n");
          gerencia = exibirAluno(gerencia);
          printf("\nExibir outro cadastro? (s - n)\n");
          getchar();
          scanf("%c", &op2);
        } while(op2=='s');
        break;
      }

      case 0:
      {
        system("clear");
        printf("<Volte sempre>\n\n");
        break;
      }
    }
  } while(op!=0);
  return 0;
}

Tgerencia cadastrar(Tgerencia gerencia)
{
  int raCadastrado = 0, ra, i;

  printf("\nDigite o RA do Aluno: ");
  scanf("%i", &ra);

  for (i = 0; i < gerencia.numAluno; i++) {
    /* code */
    if (ra == gerencia.aluno[i].RA) {
      /* code */
      raCadastrado = 1;
      break;
    }
    else
    {
      raCadastrado = 0;
    }
  }

  if(raCadastrado == 0)
  {
    gerencia.aluno[gerencia.numAluno].RA = ra;
    printf("\nDigite o Nome do Aluno: ");
    getchar();
    fgets(gerencia.aluno[gerencia.numAluno].nome, 50, stdin);
    printf("\nDigite a Nota do Aluno: ");
    scanf("%f", &gerencia.aluno[gerencia.numAluno].nota);
    printf("\n< Cadastro realizado com sucesso !!!>\n");
  }
  else
  {
    printf("\n< RA cadastrado !!!>");
    gerencia.numAluno--;
  }
  gerencia.numAluno++;
  return gerencia;
}

Tgerencia removerCadastro(Tgerencia gerencia)
{
  int raCadastrado = 0, ra, i, j;
  char opp;

  Tgerencia limpa;

  printf("\nDigite o RA do Aluno: ");
  scanf("%i", &ra);

  for (i = 0; i < gerencia.numAluno; i++) {
    /* code */
    if (ra == gerencia.aluno[i].RA) {
      /* code */
      raCadastrado = 1;
      break;
    }
    else
    {
      raCadastrado = 0;
    }
  }

  if(raCadastrado == 0)
  {
    printf("\n< RA nao cadastrado !!!>\n");
  }
  else
  {
    for (j = i; j < gerencia.numAluno; j++) {
      /* code */
      limpa.aluno[0] = gerencia.aluno[j];
      gerencia.aluno[j] = gerencia.aluno[j + 1];
      gerencia.aluno[j + 1] = limpa.aluno[0];
    }
    gerencia.numAluno--;
  }
  return gerencia;
}

Tgerencia buscarRA(Tgerencia gerenciaRA)
{
  int raCadastrado = 0, ra, i;

  printf("\nDigite o RA do Aluno: ");
  scanf("%i", &ra);

  for (i = 0; i < gerenciaRA.numAluno; i++) {
    /* code */
    if (ra == gerenciaRA.aluno[i].RA) {
      /* code */
      raCadastrado = 1;
      break;
    }
    else
    {
      raCadastrado = 0;
    }
  }

  if(raCadastrado == 1)
  {
    printf("\nRA <CADASTRADO>\n");
    printf("\nNome: %s", gerenciaRA.aluno[i].nome);
    printf("RA: %i\n", gerenciaRA.aluno[i].RA);
    printf("Nota: %.2f\n", gerenciaRA.aluno[i].nota);
  }
  else
  {
    printf("\n< RA nao cadastrado !!!>\n");
  }
  return gerenciaRA;
}

Tgerencia buscarNome(Tgerencia gerenciaNome)
{
  int nomeCadastrado = 0, i;
  char nome[50];

  printf("\nDigite o Nome do Aluno: ");
  getchar();
  fgets(nome, 50, stdin);

  for (i = 0; i < gerenciaNome.numAluno; i++) {
    /* code */
    if (strcmp(nome, gerenciaNome.aluno[i].nome) == 0) {
      /* code */
      nomeCadastrado = 1;
      break;
    }
    else
    {
      nomeCadastrado = 0;
    }
  }

  if(nomeCadastrado == 1)
  {
    printf("\nNome <CADASTRADO>\n");
    printf("\nNome: %s", gerenciaNome.aluno[i].nome);
    printf("RA: %i\n", gerenciaNome.aluno[i].RA);
    printf("Nota: %.2f\n", gerenciaNome.aluno[i].nota);
  }
  else
  {
    printf("\n< Nome nao cadastrado !!!>\n");
  }
  return gerenciaNome;
}

Tgerencia exibirAluno(Tgerencia gerenciaAluno)
{
  int i;
  printf("\nAlunos <CADASTRADOS>\n\n");
  for (i = 0; i < gerenciaAluno.numAluno; i++) {
    /* code */
    printf("\nNome: %s", gerenciaAluno.aluno[i].nome);
    printf("RA: %i\n", gerenciaAluno.aluno[i].RA);
    printf("Nota: %.2f\n", gerenciaAluno.aluno[i].nota);
  }
  return gerenciaAluno;
}
