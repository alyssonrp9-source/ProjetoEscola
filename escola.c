#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PESSOAS 100
#define MAX_DISCIPLINAS 50
#define MAX_ALUNO_POR_DISC 100

// Enum para definir status
typedef enum{
    ALUNO,
    PROFESSOR
}TipoPessoa;

// Struct de pessoa
typedef struct {
    int matricula; // ID (Matricula é unica)
    char nome[50];
    char dataNascimento[15];
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
    int listaAluno[MAX_ALUNO_POR_DISC];
    int qtdAlunosDisciplina;
}Disciplina;

// Funcoes
void menu();
void menuProcesso();
void menuAtualizar();
void menuListar();
void cadastrarPessoa(Pessoa *pessoa, TipoPessoa tipo);
void listar(Pessoa *pessoa, int *tamLista ,TipoPessoa tipo);
void Atualizar(Pessoa *pessoa, int tamLista, TipoPessoa tipo);
<<<<<<< HEAD
void excluir(Pessoa *pessoa , int *tamLista, TipoPessoa tipo);
void cadastrarDisciplina();
void listarDisciplinas();
=======
void excluir();
void cadastrarDisciplina(Disciplina*);
int listarDisciplinas(Disciplina*, int);
void atualizarDisciplina(Disciplina*);
void menuAtualizarDisciplina();
Disciplina* procurarDisciplinaPorCodigo(Disciplina lista[], int tam, int codDisc);
>>>>>>> c633dc4781e7c38e734d048ab112a4d04e9dfda3

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
                            printf("---Listar Aluno---\n");
                            listar(pessoa,&qtdPessoas, ALUNO);
                            
                            break;
                        }

                        // Atualizar Professor
                        case 3:{
                            printf("---Atualizar Cadastro de Aluno---\n");
                            Atualizar(pessoa, qtdPessoas, ALUNO);
                            break;
                        }
                        
                        // Excluir Professor
                        case 4:{
                            printf("---Excluir Cadastro de Aluno---\n");
                            excluir(pessoa, &qtdPessoas, ALUNO);
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
                    menuProcesso("PROFESSOR");
                    scanf("%d" , &opcaoProcesso);
                    switch(opcaoProcesso){
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
                            listar(pessoa,&qtdPessoas, PROFESSOR);
                            
                            break;
                        }

                        // Atualizar Professor
                        case 3:{
                            printf("---Atualizar Cadastro de Professor---\n");
                            Atualizar(pessoa, qtdPessoas, PROFESSOR);
                            break;
                        }
                        
                        // Excluir Professor
                        case 4:{
                            printf("---Excluir Cadastro de Professor---\n");
                            excluir(pessoa, &qtdPessoas, PROFESSOR);
                            break; 
                        }

                        
                    }    
                }
                break;
            }
            
            // Módulo Disciplinas
            case 3:{
                // Aqui voce pode adicionar a logica para listar Disciplinas
                printf("Módulo Disciplinas - Digite o número do processo:\n");
                menuProcesso("Disciplinas");
                scanf("%d", &opcaoProcesso);
                
                switch(opcaoProcesso) {
                    // Cadastra disciplinas
                    case 1: {
                        if (qtdDisciplinas >= MAX_DISCIPLINAS) {
                            printf("Tamanho máximo de disciplinas cadastradas!");
                            break;
                        }
                        cadastrarDisciplina(&disciplina[qtdDisciplinas]);
                        qtdDisciplinas++;
                        break;
                    }
                    case 2:{
                        
                    }
                    
                    // Lista disciplinas
                    case 2: {
                        listarDisciplinas(disciplina, qtdDisciplinas);
                        break;
                    }
                    
                    // Atualiza disciplinas
                    case 3: {
                        int codDisc;
                        printf("Digite o código da disciplina que deseja modificar: ");
                        scanf("%i", &codDisc);
                        
                        atualizarDisciplina(procurarDisciplinaPorCodigo(disciplina, qtdDisciplinas, codDisc));
                        break;
                    }
                    
                    // Exclui disciplinas
                    case 4:{

                        break;
                    }
                }
                
                
                
                break;
            }    
            default:{ 
                printf("Opcao invalida. Tente novamente.\n");
            }
        }
    }
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

void menu(){
    printf("\n");
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

void menuAtualizar(){
    printf("Digite o tópico a se atualizar: \n");
    printf("1 - Matrícula\n");
    printf("2 - Nome\n");
    printf("3 - Data de Nascimento\n");
    printf("4 - Sexo\n");
    printf("5 - CPF\n");
}

void menuListar(){
    printf("Digite o tópico a se atualizar: \n");
    printf("1 - Listar Todos\n");
    printf("2 - Listar por Nome\n");
    printf("3 - Listar por Data de Nascimento\n");
    printf("4 - Listar por Sexo\n");
    printf("Digite a opcão de listagem: ");
}

void cadastrarPessoa(Pessoa *pessoa, TipoPessoa tipo) {
    limparBuffer(); // para evitar ler '\n' anterior

    printf("Digite a matrícula: ");
    scanf("%d", &pessoa->matricula);
    limparBuffer();

    printf("Digite o nome: ");
    fgets(pessoa->nome, sizeof(pessoa->nome), stdin);
    removerQuebraLinha(pessoa->nome);

    printf("Digite a data de nascimento (dd/mm/aaaa): ");
    fgets(pessoa->dataNascimento, sizeof(pessoa->dataNascimento), stdin);
    removerQuebraLinha(pessoa->dataNascimento);

    printf("Digite o sexo (M/F): ");
    fgets(pessoa->sexo, sizeof(pessoa->sexo), stdin);
    removerQuebraLinha(pessoa->sexo);

    printf("Digite o CPF: ");
    fgets(pessoa->CPF, sizeof(pessoa->CPF), stdin);
    removerQuebraLinha(pessoa->CPF);

    pessoa->status = tipo;
}

<<<<<<< HEAD

void listar(Pessoa* pessoa, int *tamLista, TipoPessoa tipo){
    int opcaolistar;
    menuListar();
    scanf("%d" , &opcaolistar);
    limparBuffer();

    if (tamLista == 0) {
        printf("Nenhum registro encontrado\n");
        return;
=======
void listar(Pessoa* pessoa, int tamLista, TipoPessoa tipo){
    
    
    for(int i = 0; i < tamLista; i++){
        if(pessoa[i].status == tipo){
            printf("--------------------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("| Matrícula: %d | Nome: %s | idade: %d | Sexo: %s | CPF: %s |\n" , pessoa[i].matricula , pessoa[i].nome, pessoa[i].idade, pessoa[i].sexo, pessoa[i].CPF);
        }
>>>>>>> c633dc4781e7c38e734d048ab112a4d04e9dfda3
    }

    
                       
    switch(opcaolistar){
        case 1:{
            printf("--------------------------------------------------------------------------------------------------------------------------------------------------\n");
            for (int i = 0; i < *tamLista; i++) {
                if (pessoa[i].status == tipo) {
                    printf("| Matrícula: %d | Nome: %s | Data de Nascimento: %s | Sexo: %s | CPF: %s |\n",
                           pessoa[i].matricula, pessoa[i].nome, pessoa[i].dataNascimento,
                           pessoa[i].sexo, pessoa[i].CPF);
                }
            }
            printf("--------------------------------------------------------------------------------------------------------------------------------------------------\n");
            break;
        }
        case 2:{
            //Listar por Nome
            char nomeBusca[50];
            int encontrou = 0;

            printf("Digite o nome (ou parte dele) que deseja buscar: ");
            scanf("%[^\n]", nomeBusca);
            limparBuffer();

            printf("\nResultados da busca por \"%s\":\n", nomeBusca);
            printf("--------------------------------------------------------------------------------------------------------------------------------------------------\n");

            for (int i = 0; i < *tamLista; i++) {
                if (pessoa[i].status == tipo && strstr(pessoa[i].nome, nomeBusca) != NULL) {
                    printf("| Matrícula: %d | Nome: %s | Data de Nascimento: %s | Sexo: %s | CPF: %s |\n",
                           pessoa[i].matricula, pessoa[i].nome, pessoa[i].dataNascimento,
                           pessoa[i].sexo, pessoa[i].CPF);
                    encontrou = 1;
                }
            }

            if (!encontrou)
                printf("Nenhum registro encontrado com o nome \"%s\".\n", nomeBusca);

            printf("--------------------------------------------------------------------------------------------------------------------------------------------------\n");
            break;
        }
        
        case 3: { // Listar por data de nascimento
            char dataBusca[15];
            int encontrou = 0;

            printf("Digite a data de nascimento (no formato dd/mm/aaaa): ");
            scanf("%[^\n]", dataBusca);
            limparBuffer();

            printf("\nResultados para data de nascimento \"%s\":\n", dataBusca);
            printf("--------------------------------------------------------------------------------------------------------------------------------------------------\n");

            for (int i = 0; i < *tamLista; i++) {
                if (pessoa[i].status == tipo && strcmp(pessoa[i].dataNascimento, dataBusca) == 0) {
                    printf("| Matrícula: %d | Nome: %s | Data de Nascimento: %s | Sexo: %s | CPF: %s |\n",
                    pessoa[i].matricula, pessoa[i].nome, pessoa[i].dataNascimento,
                    pessoa[i].sexo, pessoa[i].CPF);
                    encontrou = 1;
                }
            }

            if (!encontrou)
            printf("Nenhum registro encontrado para a data \"%s\".\n", dataBusca);

            printf("--------------------------------------------------------------------------------------------------------------------------------------------------\n");
            break;
        }
        case 4:{
            char sexo1;
            printf("Defina o Sexo das pessoas que quer listar: ");
            scanf("%c", &sexo1);
            limparBuffer();

            for (int i = 0; i < *tamLista; i++) {
                if (pessoa[i].status == tipo) {
                    if ((strcmp(pessoa[i].sexo, "M") == 0 || strcmp(pessoa[i].sexo, "m") == 0) &&
                        (sexo1 == 'M' || sexo1 == 'm')) {

                        printf("| %-9d | %-24s | %-5d | %-4s | %-12s |\n",
                        pessoa[i].matricula, pessoa[i].nome, pessoa[i].dataNascimento,
                        pessoa[i].sexo, pessoa[i].CPF);
                    } 
                    else if ((strcmp(pessoa[i].sexo, "F") == 0 || strcmp(pessoa[i].sexo, "f") == 0) &&
                                            (sexo1 == 'F' || sexo1 == 'f')) {
                        printf("| %-9d | %-24s | %-5d | %-4s | %-12s |\n",
                            pessoa[i].matricula, pessoa[i].nome, pessoa[i].dataNascimento,
                            pessoa[i].sexo, pessoa[i].CPF);
                    }
                }
                
            }
        }
        default:{
            printf("Opção inválida!\n");
        }   
    }    
}

void Atualizar(Pessoa *pessoa , int tamLista, TipoPessoa tipo){
    int mat_auxiliar;

    printf("Digite a Matrícula que deseja atualizar informações: ");
    scanf("%d" , &mat_auxiliar);
    
    for(int i = 0; i < tamLista; i++){
        if(pessoa[i].status == tipo && pessoa[i].matricula == mat_auxiliar){
                
            int n;  
            menuAtualizar();
            scanf("%d", &n);
            limparBuffer(); // limpa o '\n' deixado no buffer pelo scanf

            switch(n){
                
                case 1:{
                    printf("Digite a nova matricula: ");
                    scanf("%d" , &pessoa[i].matricula);
                    limparBuffer(); // limpa o '\n' deixado no buffer pelo scanf
                    break;
                }

                case 2:{
                    printf("Digite o novo nome: ");
                    fgets(pessoa[i].nome, sizeof(pessoa[i].nome), stdin);
                    removerQuebraLinha(pessoa[i].nome);
                    break;
                }

                case 3:{ 
                    printf("Digite a nova data de nascimento (dd/mm/aaaa): ");
                    fgets(pessoa[i].dataNascimento, sizeof(pessoa[i].dataNascimento), stdin);
                    removerQuebraLinha(pessoa[i].dataNascimento);
                    break;
                }
                
                case 4:{
                    printf("Digite a novo sexo: ");
                    fgets(pessoa[i].sexo, sizeof(pessoa[i].sexo), stdin);
                    removerQuebraLinha(pessoa[i].sexo);
                    break;
                }

                case 5:{
                    printf("Digite a nova CPF: ");
                    fgets(pessoa[i].nome, sizeof(pessoa[i].CPF), stdin);
                    removerQuebraLinha(pessoa[i].CPF);
                    break;
                }

                default:{
                    printf("Opção inválida.\n");
                    break;
                }

            }
            printf("Atualização Realizada com Sucesso");
        }
    }
    if(tamLista == 0){
        printf("Nenhum Registro Encontrado");
    }
}

<<<<<<< HEAD
void excluir(Pessoa *pessoa , int *tamLista, TipoPessoa tipo){
    int mat_remover;

    printf("Digite a Matrícula que deseja remover: ");
    scanf("%d" , &mat_remover);
    
    for(int i = 0; i < *tamLista; i++){
        if(pessoa[i].matricula == mat_remover && pessoa[i].status == tipo){     
            for(int j = i; j < *tamLista - 1; j++){
                pessoa[j] = pessoa[j + 1];
            }
            (*tamLista)--; //Diminui o total de registros                break;    
            printf("Matrícula da pessoa %d foi excluída com sucesso", mat_remover);
            break;
        }
        else{
            printf("Matrícula não encontrada");
        }    
    }
    
    

}

void cadastrarDisciplina(Disciplina* disciplina, int tamLista) {
    
    return;
}
=======
// Colocar funcao excluir

void cadastrarDisciplina(Disciplina* disciplina) {
    printf("Digite o nome da disciplina:\n");
    scanf("%s", disciplina->nome);
    printf("Digite o código da disciplina:\n");
    scanf("%i", &disciplina->codigo);
    printf("Digite o semestre da disciplina:\n");
    scanf("%i", &disciplina->semestre);
    printf("Digite a matrícula do professor da disciplina:\n");
    scanf("%i", &disciplina->professor);
    disciplina->qtdAlunosDisciplina = 0;
    
    return;
}


int listarDisciplinas(Disciplina disciplina[], int tam){
    if (!tam) {
        printf("Sem disciplinas cadastradas\n");
        return tam; // Vai retornar 0
    } 
    
    int qtdTracos = 15;
    char buffer[qtdTracos + 1];
    for (int i = 0; i < qtdTracos; i++) {
        buffer[i] = '-';
    }
    buffer[qtdTracos] = 0;
    
    printf("%sDISCIPLINAS:%s\n", buffer, buffer);

    for (int i = 0; i < tam; i++) {
        printf("[%i] Nome: %s | Matricula Professor (mudar depois): %i | Semestre: %i | Quantidade de alunos: %i\n", (i + 1), disciplina[i].nome, disciplina[i].professor, disciplina[i].semestre, disciplina[i].qtdAlunosDisciplina);
    }

    return tam;
}

void menuAtualizarDisciplina() {
    printf("O que deseja modificar?\n[1] Nome\n[2] Semestre\n[3] Professor\n");
}


Disciplina* procurarDisciplinaPorCodigo(Disciplina lista[], int tam, int codDisc) {
    for (int i = 0; i < tam; i++) {
        if (lista[i].codigo == codDisc)
            return &(lista[i]);
    }
    return NULL;
}



void atualizarDisciplina(Disciplina* discSelec) {
    int opcao;
    
    if (discSelec == NULL) {
        printf("Disciplina não encontrada!\n");
        return;
    }
        
    menuAtualizarDisciplina();
    scanf("%i", &opcao);
    
    switch (opcao) {
        // Nome da disciplina
        case 1:
            printf("Digite o novo nome da disciplina:\n");
            scanf("%s", &discSelec->nome);
            break;
            
        // Semestre
        case 2:
            printf("Digite o novo semestre da disciplina:\n");
            scanf("%i", &discSelec->semestre);
            break;
            
        // Professor
        case 3:
            printf("Digite a matrícula do professor da disciplina:\n");
            scanf("%i", &discSelec->professor);
            break;
        default:
            printf("Opção inválida!\n");
            return;
    }
    printf("Atualizado!");
    return;
}

// TODO: implementar cadastro alunos em uma disciplina



>>>>>>> c633dc4781e7c38e734d048ab112a4d04e9dfda3
