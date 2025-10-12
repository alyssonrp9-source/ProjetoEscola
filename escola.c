#include <stdio.h>
#include <stdlib.h>

#define MAX_PESSOAS 100
#define MAX_DISCIPLINAS 50

// Enum para definir status
typedef enum{
    ALUNO,
    PROFESSOR
}TipoPessoa;

// Struct de pessoa
typedef struct {
    int matricula; // ID (Matricula é unica)
    char nome[50];
    int idade;
    char sexo[50];
    char CPF[11]; // Também é único (mas não vou usar para ser ID) 
    TipoPessoa status;
}Pessoa;

// Struct de disciplina
typedef struct {
    char nome[50];
    int codigo; // ID
    int semestre;
    int professor;
    int listaAluno[100];
}Disciplina;

// Funcoes
void menu();
void menuProcesso();
void cadastrarPessoa(Pessoa *pessoa, TipoPessoa tipo);
void listar(Pessoa *pessoa, int tamLista ,TipoPessoa tipo);
void Atualizar(Pessoa *pessoa, int tamLista, TipoPessoa tipo);
// Fazer Funcao Excluir
void cadastrarDisciplina();
void listarDisciplinas();

int main(){
    
    // Pessoa aluno[MAX_PESSOAS];
    // Pessoa professor[MAX_PESSOAS];
    // int qtdAlunos = 0;
    // int qtdProfessores = 0;

    Pessoa pessoa[MAX_PESSOAS];
    int qtdPessoas = 0;
    Disciplina disciplina[MAX_DISCIPLINAS];
    int qtdDisciplinas = 0;

    int opcao;
    int sair = 0;

    while (!sair) {
        menu();
        scanf("%d", &opcao);
        int opcaoProcesso;
        switch (opcao) {
            case 0:{
                sair = 1;
                printf("Finalizado\n");
                
                break;
            }
            //Módulo Aluno
            case 1:{
                // Aqui voce pode adicionar a logica para listar Alunos
                if(opcao == 1){
                    printf("Modulo Aluno - Digite o número do processo:\n");
                    menuProcesso("Aluno");
                    scanf("%d" , &opcaoProcesso);
                    
                    switch(opcaoProcesso){
                        
                        // Cadastrar Aluno
                        case 1:{
                            if (qtdPessoas >= MAX_PESSOAS)
                            {
                                printf("Tamanho máximo de pessoas cadastradas!\n");
                                break;
                            }
                            else
                            { 
                                printf("---Cadastro de Aluno---\n");
                                cadastrarPessoa(&pessoa[qtdPessoas], ALUNO);
                                qtdPessoas++;
                            }
                            break;
                        }
                        
                        // Listar Alunos
                        case 2:{
                            printf("---Listar Alunos---\n");
                            listar(pessoa,qtdPessoas,ALUNO);
                            
                            break;
                        }

                        // Atualizar Aluno
                        case 3:{
                            printf("---Atualizar Cadastro de Alunos---\n");

                            break;
                        }
                        
                        // Excluir Aluno
                        case 4:{
                            printf("---Excluir Cadastro de Alunos---\n");

                            break;        
                        }

                    }

                    break;
                }    

            }
            // Módulo Professor
            case 2:{

               if(opcao == 2){
                    printf("Modulo Professor - Digite o número do processo:\n");
                    int opcao;
                    menuProcesso();
                    scanf("%d" , &opcao);
                    
                    // Cadastrar Professor
                    case 1:{
                        if (qtdPessoas >= MAX_PESSOAS)
                        {
                            printf("Tamanho máximo de pessoas cadastradas!\n");
                            break;
                        }
                        else
                        { 
                            printf("---Cadastro de Professor---\n");
                            cadastrarPessoa(&pessoa[qtdPessoas], PROFESSOR);
                            qtdPessoas++;
                        }
                        break;
                    }
                    
                    // Listar Professor
                    case 2:{
                        printf("---Listar Professor---\n");
                        listar(pessoa,qtdPessoas, PROFESSOR);
                        
                        break;
                    }

                    // Atualizar Professor
                    case 3:{
                        printf("---Atualizar Cadastro de Professor---\n");

                        break;
                    }
                    
                    // Excluir Professor
                    case 4:{
                        printf("---Excluir Cadastro de Professor---\n");
                        break;        
                    }
                }
                break;
            }
            
            // Módulo Disciplinas
            case 3:{
                // Aqui voce pode adicionar a logica para listar Disciplinas
                printf("Módulo Disciplinas:\n");
                menuProcesso("Disciplinas");
                scanf("%d", &opcaoProcesso);
                
                switch(opcaoProcesso) {
                    case 1: {
                        cadastrarDisciplina(disciplina, qtdDisciplinas);
                        
                        break;   
                    }
                    
                    
                }
                
                
                
                break;
            }    
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    }
}


void menu(){
    
    printf("----Menu:----\n");
    printf("0. Sair\n");
    printf("1. Aluno\n");
    printf("2. Professor\n");
    printf("3. Disciplina\n");
    printf("Escolha uma opcao: ");

}


void menuProcesso(char* str){
    printf("1-Cadastrar %s\n", str);
    printf("2-Listar %s\n", str);
    printf("3-Atualizar %s\n", str);
    printf("4-Excluir %s\n", str);
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

void listar(Pessoa* pessoa, int tamLista, TipoPessoa tipo){
    for(int i = 0; i < tamLista; i++){
        if(pessoa[i].status == tipo){
            printf("Matrícula: %d - Nome: %s \n" , pessoa[i].matricula , pessoa[i].nome);
        }
    }

    if(tamLista == 0) printf("Nenhum registro encontrado\n");
}

// void Atualizar(Pessoa *pessoa , int tamLista, TipoPessoa tipo){
    
//     for(int i = 0; i < tamLista; i++){
//         if(pessoa[i].status == tipo){
            
//         }
//     }

// }


// Colocar funcao excluir


void cadastrarDisciplina(Disciplina* disciplina, int tamLista) {
    
    
    
    return;
}



