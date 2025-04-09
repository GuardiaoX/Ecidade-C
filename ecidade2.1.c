#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

    long id;
    bool matric;
    string nome;
    string tel;
    string ender;

}pessoa;

// Função pede um Nome para criação do cadastro do Aluno
void CriarAluno(string nome, string tel, string ender);
// Função exibe uma lista de alunos com seus nomes e ids
void ListarAlunos();
// Função pede id, e pede confirmação para deletar
void DeletaAluno(long id);
// Função printa todos os dados do aluno no terminal
void PrintarAluno(pessoa aluno);
// Função busca por id o aluno e retorna ele
pessoa BuscaAluno(long id);

#define TDALISTA 20

pessoa alunos[TDALISTA];

int main(void)
{
    while(true){

        char opc = get_char("1. Criar Aluno\n2.Listar Alunos\n3.Deletar Aluno\n");
        if(opc == '1')
        {
            CriarAluno("Ethan", "555 444 333", "Rua da Monica 69");
            CriarAluno("Ashley", "555 444 333", "Rua da Monica 69");
            CriarAluno("Madeline", "555 444 333", "Rua da Monica 69");
            CriarAluno("Hana", "555 444 333", "Rua da Monica 69");
            CriarAluno("Naomi", "555 444 333", "Rua da Monica 69");
        }
        else if(opc == '2')
        {
            ListarAlunos();
        }
        else if(opc == '3')
        {
            printf("Aluno: %s\n", BuscaAluno(3).nome);
            DeletaAluno(3);
        }
        else
        {
            break;
        }
    }
}

void CriarAluno(string nome, string tel, string ender){
    for(int i = 0; i < TDALISTA; i++)
    {
        if(alunos[i].id == 0)
        {
            printf("Vazio\n");
            alunos[i].id = i+1;
            alunos[i].matric = true;
            alunos[i].nome = nome;
            alunos[i].tel = tel;
            alunos[i].ender = ender;
            PrintarAluno(alunos[i]);
            break;
            return;
        }else if(i == TDALISTA - 1){
            printf("Cabou os espaços");
        }
    }
}

void PrintarAluno(pessoa aluno){
        printf(" Id: %ld\n Matriculado: %d\n Nome: %s\n Telefone: %s\n Endereço: %s\n", aluno.id, aluno.matric, aluno.nome, aluno.tel, aluno.ender);
}

void ListarAlunos(){
    for(int i = 0; alunos[i].id != 0; i++){
        PrintarAluno(alunos[i]);
        printf("\n\n");
    }
}

pessoa BuscaAluno(long id){
    for(int i = 0; i < TDALISTA; i++)
    {
        if(alunos[i].id == id)
        {
            return alunos[i];
        }
    }
    pessoa vazio = {0, false, NULL, NULL, NULL};
    return vazio;
}

void DeletaAluno(long id){
    alunos[id - 1].matric = false;
}
