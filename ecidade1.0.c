#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função pede um Nome para criação do cadastro do Aluno
void CriarAluno(char nome[]);

char alunos[30][100];

int main(void)
{
    bool running = true;

    do{
        if(get_char("O que deseja?\n1.Cadastrar Aluno\n2.Sair\n\n ") == '1'){
            printf("\n\n\n");
            CriarAluno(get_string("Qual o nome da criança? "));
        }else {
            running = false;
        }
    }while(running == true);

}















// deve criar uma função que caminhe pela lista da 0 até um espaço vazio
// se espaço vaio for igual TRUE, então preenche o campo com o valor do parametro
void CriarAluno(char nome[])
{
    bool livre = false;

    for (int i = 0; livre == false; i++)
    {
        if (alunos[i][0] == '\0')
        {
            strcpy(alunos[i], nome);
            printf("Aluno: %i %s\n\n\n", i, alunos[i]);
            livre = true;
        }
    }
}
