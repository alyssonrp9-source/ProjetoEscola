#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define max_pessoas 100
#define max_disciplinas 100

typedef enum {
    ALUNO, PROFESSOR
} TipoPessoa;

typedef struct{
    int matricula;
    char nome[50];
    char sexo;
    char dataDeNascimento[11];
    char CPF[11];
    TipoPessoa status;
}Pessoa;

//Funcoes
void menuPrincipal();
void menuAluno();
void menuListar();
void limparBuffer();
Pessoa cadastrar(Pessoa pessoa, TipoPessoa tipo);
void listar(Pessoa pessoa[], TipoPessoa tipo, int qtd_pessoas);
void atualizar(Pessoa pessoa[], TipoPessoa tipo, int qtd_pessoas);
Pessoa excluir(Pessoa pessoa, int tamLista, TipoPessoa tipo);

int main(){

    //variavel para guardar o registro das pessoas;
    Pessoa vetorPessoa[max_pessoas];
    //variavel para percorrer o vetor;
    int qtd_pessoas = 0;
    
    int opcao;
    int sair = 0;
    while(!sair){ 
        menuPrincipal();
        scanf("%d", &opcao);
        switch(opcao){


            //Modulo Aluno - 1

            case 1:{

                int opcaoAluno;
                menuAluno();
                scanf("%d", &opcaoAluno);
                void limparBuffer();

                int sairAluno = 0;
                
                switch(opcaoAluno){
                    // Cadastro
                    case 1:{
                        vetorPessoa[qtd_pessoas] = cadastrar(vetorPessoa[qtd_pessoas], ALUNO);
                        qtd_pessoas++;
                        break;
                    }
                            
                    // Listar
                    case 2:{
                        listar(vetorPessoa, PROFESSOR, qtd_pessoas);
                        break;
                    }
                                                     
                    //Atualizar
                    case 3:{
                        atualizar(vetorPessoa, ALUNO, qtd_pessoas);
                        break;
                    }
                                
                                //Deletar
                   
                            
                }          
            }
            
            case 2:

            break;
            case 3:
                        
            break;
            default:{
                printf("Sistema Finalizado\n");
                sair = 1;
            }

                        
            break;
        }
    }
    return 0;
}

void menuPrincipal(){
    printf("----Módulos Escolares----\n");
    printf("1 - Módulo Aluno\n");
    printf("2 - Módulo Professor\n");
    printf("3 - Módulo Disciplina\n");
    printf("0 - Finalizar Sistema\n");
    printf("Digite uma opcao: ");
}

void menuAluno(){
    printf("----Menu Aluno----\n");
    printf("1 - Cadastrar Aluno\n");
    printf("2 - Listar Aluno\n");
    printf("3 - Atualizar Aluno\n");
    printf("4 - Deletar Aluno\n");
    printf("0 - Sair\n");
    printf("Escolha uma opção: ");
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void removerQuebraLinha(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';
}


Pessoa cadastrar(Pessoa pessoa, TipoPessoa tipo){
        limparBuffer();
    
    if(tipo == ALUNO){

        pessoa.status = ALUNO;

        printf("Digite a matrícula: ");
        scanf("%d" , &pessoa.matricula);
        limparBuffer();
        
        printf("Digite o nome do Aluno: ");
        fgets(pessoa.nome, sizeof(pessoa.nome), stdin);
        pessoa.nome[strcspn(pessoa.nome, "\n")] = '\0';
        
        printf("Digite o sexo (M/F): ");
        scanf("%c",&pessoa.sexo);
        limparBuffer();
        
        printf("Digite a data de nascimento: ");
        fgets(pessoa.dataDeNascimento, sizeof(pessoa.dataDeNascimento), stdin);
        pessoa.dataDeNascimento[strcspn(pessoa.dataDeNascimento, "\n")] = '\0';
        
        getchar();
        printf("Digite o CPF: ");
        scanf("%[^\n]s", pessoa.CPF);
        limparBuffer();

        printf("Cadastro realizado!\n");
        
    }
    
    else if(tipo == PROFESSOR){

        pessoa.status = PROFESSOR;

        printf("Digite a matrícula: ");
        scanf("%d" , &pessoa.matricula);
        limparBuffer();
            
        printf("Digite o nome do Aluno: ");
        fgets(pessoa.nome, sizeof(pessoa.nome), stdin);
        pessoa.nome[strcspn(pessoa.nome, "\n")] = '\0';
        
        printf("Digite o sexo (M/F): ");
        scanf("%c",&pessoa.sexo);
        limparBuffer();
        
        printf("Digite a data de nascimento: ");
        fgets(pessoa.dataDeNascimento, sizeof(pessoa.dataDeNascimento), stdin);
        pessoa.dataDeNascimento[strcspn(pessoa.dataDeNascimento, "\n")] = '\0';
        
        printf("Digite o CPF: ");
        scanf("%[^\n]s", pessoa.CPF);
        limparBuffer();

        printf("Cadastro realizado! Pressione Enter...");
        getchar();
        
    }
    
    return pessoa;
    
}

void menuListar(){
    printf("\n------------ Menu Aluno --------------\n");
    printf("1 - Listar por matrícula\n");
    printf("2 - Listar por Nome\n");
    printf("3 - Listar por CPF\n");
    printf("4 - Listar por Sexo\n");
    printf("5 - Listar Data de Nascimento\n");
    printf("0 - Finalizar Operação\n");
    printf("Digite a opção: ");
}

void menuAtualizar(){
    printf("\n------------ Menu Aluno --------------\n");
    printf("1 - Atualizar matrícula\n");
    printf("2 - Atualizar Nome\n");
    printf("3 - Atualizar CPF\n");
    printf("4 - Atualizar Sexo\n");
    printf("5 - Atualizar Data de Nascimento\n");
    printf("0 - Finalizar Operação\n");
    printf("Digite a opção: ");
}

void listar(Pessoa pessoa[], TipoPessoa tipo, int qtd_pessoas){
    int opcaoMenuListar;
    int sair = 0;
    
    //Esse While serve para executar o switch sempre que o digito não for 0.
    while(!sair){
        menuListar();
        scanf("%d" , &opcaoMenuListar);
        getchar();
        
        if(tipo == ALUNO || tipo == PROFESSOR){
            switch(opcaoMenuListar){
                case 1:{
                    for(int i = 0; i < qtd_pessoas; i++){
                        printf("-------------------------------------------------------------------\n");
                        printf("| %d | %s | %s | %c | %s |\n" , pessoa[i].matricula , pessoa[i].nome , pessoa[i].CPF, pessoa[i].sexo, pessoa[i].dataDeNascimento);
                    
                    }
                    break;
                }
                case 2:{
                    for(int i = 0; i < qtd_pessoas; i++){
                        printf("-------------------------------------------------------------------\n");
                        printf("%s\n" , pessoa[i].nome);
                    }
                    break;
                }
                case 3:{
                    for(int i = 0; i < qtd_pessoas; i++){
                        printf("-------------------------------------------------------------------\n");
                        printf("%s\n" , pessoa[i].CPF);
                    }
                    break;
                }
                case 4:{
                    for(int i = 0; i < qtd_pessoas; i++){
                        printf("-------------------------------------------------------------------\n");
                        printf("%c\n" , pessoa[i].sexo);
                    }
                    break;
                }
                case 5:{
                    for(int i = 0; i < qtd_pessoas; i++){
                        printf("-------------------------------------------------------------------\n");
                        printf("%s\n" , pessoa[i].dataDeNascimento);
                    }
                    break;
                }
                case 0:{
                    printf("Operação Finalizada!\n");
                    sair = 1;
                    break;
                }
                default:{ 
                    printf("Opção Inválida, tente novamente ou Pressione 0 para anular a operação\n");
                    break;
                }
            }
        }
    }
}

void atualizar(Pessoa pessoa[], TipoPessoa tipo, int qtd_pessoas){

    int opcao;
    int sair = 0;

    while(!sair){
        menuAtualizar();
        scanf("%d" , &opcao);
        getchar();
        
        switch(opcao){
            case 1:{
                for(int i = 0; i < qtd_pessoas; i++){
                    int aux_matricula;
                    printf("Digite a matrícula que deseja alterar: ");
                    scanf("%d" , &aux_matricula);
                    getchar();

                    if(pessoa[i].matricula == aux_matricula){
                        printf("Digite a nova Matrícula: ");
                        scanf("%d" , &pessoa[i].matricula);
                        getchar();
                    }
                    else{
                        printf("Matrícula inválida. \n");
                    }
                    
                }    
                break;
            }
            case 2:{
                int aux;
                //matricula para identificação do aluno

                printf("Digite a matrícula: \n");
                scanf("%d" , &aux);

                for(int i = 0; i < qtd_pessoas; i++){
                    char aux_nome[50];
                    printf("Digite o nome que deseja alterar: ");
                    fgets(aux_nome, sizeof(aux_nome), stdin);
                    aux_nome[strcspn(aux_nome, "\n")] = '\0';

                    if(strcmp(pessoa[i].nome , aux_nome) == 0){
                        printf("Digite a novo nome: ");
                        fgets(pessoa[i].nome, sizeof(pessoa[i].nome), stdin);
                        pessoa[i].nome[strcspn(pessoa[i].nome, "\n")] = '\0';   
                    }
                    else{
                        printf("Nome inválido. \n");
                    }
                    
                }
                break;
            }
            case 3:{
                for(int i = 0; i < qtd_pessoas; i++){
                    char aux_cpf[50];
                    printf("Digite o CPF que deseja alterar: ");
                    fgets(aux_cpf, sizeof(aux_cpf), stdin);
                    aux_cpf[strcspn(aux_cpf, "\n")] = '\0';
                    getchar();

                    if(strcmp(pessoa[i].CPF , aux_cpf) == 0){
                        printf("Digite a novo CPF: ");
                        fgets(pessoa[i].CPF, sizeof(pessoa[i].CPF), stdin);
                        pessoa[i].CPF[strcspn(pessoa[i].CPF, "\n")] = '\0';   
                    }
                    else{
                        printf("CPF inválido. \n");
                    }
                    
                }
                break;
            }
            case 4:{
                for(int i = 0; i < qtd_pessoas; i++){
                    char aux_sexo;
                    printf("Digite o SEXO que deseja alterar: ");
                    scanf("%[^\n]s", aux_sexo);
                    limparBuffer();

                    if(pessoa[i].sexo == aux_sexo){
                        printf("Digite a novo Sexo: ");
                        scanf("%[^\n]s", aux_sexo);
                        limparBuffer();
                    }
                    else{
                        printf("Sexo inválido. \n");
                    }
                }
                break;
            }
            case 5:{
                for(int i = 0; i < qtd_pessoas; i++){
                    char aux_data[50];
                    printf("Digite a data que deseja alterar: ");
                    fgets(aux_data, sizeof(aux_data), stdin);
                    aux_data[strcspn(aux_data, "\n")] = '\0';

                    if(strcmp(pessoa[i].dataDeNascimento , aux_data) == 0){
                        printf("Digite a nova Data: ");
                        fgets(pessoa[i].dataDeNascimento, sizeof(pessoa[i].dataDeNascimento), stdin);
                        pessoa[i].dataDeNascimento[strcspn(pessoa[i].dataDeNascimento, "\n")] = '\0';   
                    }
                    else{
                        printf("CPF inválido. \n");
                    }
                    
                }
                break;
            }
            default:{
                printf("Operação Finalizada\n");
                sair = 1;
            }
            
        }
    }


}