#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função pede um Nome para criação do cadastro do Aluno
void CriarAluno(char nome[]);
// Função exibe uma lista de alunos com seus nomes e ids
void ListarAlunos();
// Função pede id, e pede confirmação para deletar
void DeletarAluno(int id);
// Função receber char, se y ou Y retorna true, qualquer outra coisa retorna false
bool YESORNOHANDLER(char answer[]);

char alunos[30][100];

int main(void)
{
    bool running = true;

    do
    {
        char opção = get_char(
            "O que deseja?\n1.Cadastrar Aluno\n2.Deletar Aluno\n3.Listar Alunos\n4.Sair\n\n ");
        system("clear");
        if (opção == '1')
        {
            printf("\n\n\n");
            CriarAluno(get_string("Qual o nome da criança? "));
        }
        else if (opção == '2')
        {
            int idaluno = get_int("Digite o id do aluno ");
            if (YESORNOHANDLER(get_string("Deseja realmente deletar %s", alunos[idaluno])) == true)
            {
                DeletarAluno(idaluno);
            }
            else
            {
                printf("Remoção cancelada, voltando ao menu");
            }
        }
        else if (opção == '3')
        {
            ListarAlunos();
        }
        else
        {
            running = false;
        }
    }
    while (running == true);
}

bool YESORNOHANDLER(char answer[])
{
    if (answer[0] == 'y' || answer[0] == 'Y')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void DeletarAluno(int id)
{
    memset(alunos[id], '\0', 100);
}

void ListarAlunos()
{
    for (int i = 0; alunos[i][0] != '\0'; i++)
    {
        printf("Id: %i   Nome: %s\n", i, alunos[i]);
    }
}

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
