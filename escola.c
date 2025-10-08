#include <stdio.h>
#include <stdlib.h>

#define MAX_PESSOAS 100

// Enum para definir status
typedef enum{
    ALUNO,
    PROFESSOR
}TipoPessoa;

typedef struct {
    int matricula;
    char nome[50];
    int idade;
    char sexo[50];
    char CPF[11];
    TipoPessoa status;
}Pessoa;


void menuProcesso();
void cadastrarPessoa(Pessoa *pessoa, TipoPessoa tipo);
void listarAlunos();
void listarProfessores();
void cadastrarDisciplina();
void listarDisciplinas();
void menu();

int main(){
    
    Pessoa aluno[MAX_PESSOAS];
    Pessoa professor[MAX_PESSOAS];
    int qtdAlunos = 0;
    int qtdProfessores = 0;


    int opcao;
    int sair = 0;

    while (!sair) {
        menu();
        scanf("%d", &opcao);
        switch (opcao) {
            case 0:{
                sair = 1;
                printf("Finalizado");
                
                break;
            }
            case 1:{
                // Aqui voce pode adicionar a logica para listar Alunos
                if(opcao == 1){
                    printf("Modulo Aluno - Digite o número do processo:\n");
                    int opcao;
                    menuProcesso();
                    scanf("%d" , &opcao);
                    
                    switch(opcao){
                        case 1:{
                            Pessoa aluno;
                            cadastrarPessoa(&aluno, ALUNO);
                        }
                        case 2:{
                            
                        }
                        case 3:{

                        }
                        case 4:{       
                                          
                        }

                    }

                    break;
                }    

            }
            case 2:{
                // Aqui voce pode adicionar a logica para listar Professores
                printf("Módulo Professor:\n");
                
                break;
            }
            case 3:{
                // Aqui voce pode adicionar a logica para listar Disciplinas
                printf("Módulo Disciplinas:\n");
             
             
                break;
            }    
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    }


}

void menu(){
    
    printf("Menu:\n");
    printf("0. Sair\n");
    printf("1. Aluno\n");
    printf("2. Professor\n");
    printf("3. Disciplina\n");
    printf("Escolha uma opcao: ");

}


void menuProcesso(){
    printf("1-Cadastrar\n");
    printf("2-Inserir\n");
    printf("3-Atualizar\n");
    printf("4-Excluir\n");
}

void cadastrarPessoa(Pessoa *pessoa, TipoPessoa tipo){
    printf("Digite a matricula: ");
    scanf("%d", &pessoa->matricula);
    printf("Digite o nome: ");
    scanf("%s", pessoa->nome);
    printf("Digite a idade: ");
    scanf("%d", &pessoa->idade);
    printf("Digite o sexo: ");
    scanf("%s", pessoa->sexo);
    printf("Digite o CPF: ");
    scanf("%s", pessoa->CPF);
    pessoa->status = tipo;
}

void listarAlunos(){
    
}
// TESTE
