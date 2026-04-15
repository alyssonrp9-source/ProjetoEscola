#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define max_pessoas 500
#define max_disciplinas 500
#define max_matriculas 500 

typedef struct {
    int matriculaAluno;      // Chave do aluno
    int codigoDisciplina;    // Chave da disciplina
    float nota;              // Opcional: para futura gestão de notas
    int ativo;               // 1 = matriculado, 0 = cancelado (para exclusão lógica)
} Matricula;

typedef enum {
    ALUNO, PROFESSOR
} TipoPessoa;

typedef struct{
    int matricula;
    char nome[50];
    char sexo;
    char dataDeNascimento[13];
    char CPF[13];
    TipoPessoa status;
}Pessoa;

typedef struct{
    int codigo;
    char titulo[50];
    int semestre;
    char nomeProfessor[50];
    
}Disciplina;

//Funcoes Simples
void menuPrincipal();
void menuAluno();
void menuListar();
void menuDisciplina();
void menuListarDisciplina();
void limparBuffer();
void menuProfessor();
// Funções de Cadastro de Pessoas
Pessoa cadastrar(Pessoa pessoa, TipoPessoa tipo);
void listar(Pessoa pessoa[], TipoPessoa tipo, int qtd_pessoas);
void atualizar(Pessoa pessoa[], TipoPessoa tipo, int qtd_pessoas);
void deletar(Pessoa pessoa[], TipoPessoa tipo, int qtd_pessoas);
//Funções de Cadastro de Disciplinas
Disciplina cadastrarDisciplina(Disciplina disciplina);
void listarDisciplina(Disciplina disciplina[], int qtd_disciplinas);
void atualizarDisciplina(Disciplina pessoa[], int qtd_disciplinas);
void deletarDisciplina(Disciplina pessoa[], int qtd_disciplinas);
//Funções para Matrícula
// Matrículas
Matricula cadastrarMatricula(Matricula m, Pessoa alunos[], int qtd_alunos, Disciplina disciplinas[], int qtd_disciplinas);
void listarMatriculasPorAluno(Matricula matriculas[], int qtd_matriculas, int matriculaAluno);
void listarAlunosPorDisciplina(Matricula matriculas[], int qtd_matriculas, Pessoa alunos[], int qtd_alunos, int codigoDisciplina);
void excluirMatricula(Matricula matriculas[], int *qtd_matriculas, int matriculaAluno, int codigoDisciplina);

int main(){

    //variavel para guardar o registro das pessoas;
    Pessoa vetorPessoa[max_pessoas];
    int qtd_pessoas = 0;
    //variavel para percorrer o vetor;
    
    Disciplina vetorDisciplina[max_disciplinas];
    int qtd_disciplinas = 0;

    Matricula vetorMatriculas[max_matriculas];
    int qtd_matriculas = 0;
    
    int opcao;
    int sair = 0;
    while(!sair){ 
        menuPrincipal();
        scanf("%d", &opcao);
        limparBuffer();
        switch(opcao){

            //Modulo Aluno - 1

            case 1:{

                int opcaoAluno;
                menuAluno();
                scanf("%d", &opcaoAluno);
                limparBuffer();

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
                        listar(vetorPessoa, ALUNO, qtd_pessoas);
                        break;
                    }
                                                     
                    //Atualizar
                    case 3:{
                        atualizar(vetorPessoa, ALUNO, qtd_pessoas);
                        break;
                    }
                                
                                //Deletar
                    case 4:{
                        deletar(vetorPessoa, ALUNO, qtd_pessoas);
                        qtd_pessoas--;
                        break;
                    }
                            
                }        
                break;  
            }
            
            //Modulo Professor
            case 2:{

                int opcaoProfessor;
                menuProfessor();
                scanf("%d", &opcaoProfessor);
                limparBuffer();

                int sairAluno = 0;
                
                switch(opcaoProfessor){
                    // Cadastro
                    case 1:{
                        vetorPessoa[qtd_pessoas] = cadastrar(vetorPessoa[qtd_pessoas], PROFESSOR);
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
                        atualizar(vetorPessoa, PROFESSOR, qtd_pessoas);
                        break;
                    }
                                
                                //Deletar
                    case 4:{
                        // EM DÚVIDA!! Algoritmo Copiado e não está muito claro.
                        deletar(vetorPessoa, PROFESSOR, qtd_pessoas);
                        qtd_pessoas--;
                        break;
                    }
                            
                }          
                break;
            }

            //Modulo Disciplina
            case 3:{
                int opcaoDisciplina;
                menuDisciplina();
                scanf("%d" , &opcaoDisciplina);
                limparBuffer();

                switch(opcaoDisciplina){
                    // Cadastrar
                    case 1:{ 
                        vetorDisciplina[qtd_disciplinas] = cadastrarDisciplina(vetorDisciplina[qtd_disciplinas]);
                        qtd_disciplinas++;
                        break;
                    }
                    // Listar
                    case 2:{
                        listarDisciplina(vetorDisciplina, qtd_disciplinas);
                        break;
                    }
                    // Atualizar
                    case 3:{
                        atualizarDisciplina(vetorDisciplina, qtd_disciplinas);
                        break;
                    }
                    // Deletar
                    case 4:{
                        deletarDisciplina(vetorDisciplina, qtd_disciplinas);
                        qtd_disciplinas--;
                        break;
                    }
                }

                break;
            }
            //Modulo matricula
            case 4:{
                int opcaoMatricula;
                printf("--- Menu Matrícula ---\n");
                printf("1 - Matricular Aluno em Disciplina\n");
                printf("2 - Listar Disciplinas de um Aluno\n");
                printf("3 - Listar Alunos de uma Disciplina\n");
                printf("4 - Excluir Matrícula\n");
                printf("0 - Voltar\n");
                printf("Escolha: ");
                scanf("%d", &opcaoMatricula);
                limparBuffer();

                switch(opcaoMatricula) {
                    case 1:{
                         if (qtd_pessoas == 0 || qtd_disciplinas == 0) {
                         printf("É necessário ter alunos e disciplinas cadastrados.\n");
                        } else {
                            vetorMatriculas[qtd_matriculas] = cadastrarMatricula(vetorMatriculas[qtd_matriculas], vetorPessoa, qtd_pessoas, vetorDisciplina, qtd_disciplinas);
                            if (vetorMatriculas[qtd_matriculas].ativo)
                                qtd_matriculas++;
                        }
                        break;
                    }    
                    case 2: {
                        int matAluno;
                        printf("Digite a matrícula do aluno: ");
                        scanf("%d", &matAluno);
                        limparBuffer();
                        listarMatriculasPorAluno(vetorMatriculas, qtd_matriculas, matAluno);
                        break;
                    }
                    case 3: {
                        int codDisc;
                        printf("Digite o código da disciplina: ");
                        scanf("%d", &codDisc);
                        limparBuffer();
                        listarAlunosPorDisciplina(vetorMatriculas, qtd_matriculas, vetorPessoa, qtd_pessoas, codDisc);
                        break;
                    }
                    case 4: {
                        int matAluno, codDisc;
                        printf("Digite a matrícula do aluno: ");
                        scanf("%d", &matAluno);
                        printf("Digite o código da disciplina: ");
                        scanf("%d", &codDisc);
                        limparBuffer();
                        excluirMatricula(vetorMatriculas, &qtd_matriculas, matAluno, codDisc);
                        break;
                    }
                    case 0:{ 
                        break;
                    }
                    default:{ 
                        printf("Opção inválida.\n");
                        break;
                    }
                    break;
                }
            
               
            }  
            default:{
                printf("Sistema Finalizado\n");
                sair = 1;
                break;
            }
            
                        
        

        }
    }
    return 0;
}

void menuPrincipal(){
    printf("----Módulos Escolares----\n");
    printf("1 - Módulo Aluno\n");
    printf("2 - Módulo Professor\n");
    printf("3 - Módulo Disciplina\n");
    printf("4 - Módulo Matrícula\n");
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

void menuDisciplina(){
    printf("------ Menu Disciplina ------\n");
    printf("1 - Cadastrar Disciplina\n");
    printf("2 - Listar Disciplina\n");
    printf("3 - Atualizar Disciplina\n");
    printf("4 - Deletar Disciplina\n");
    printf("0 - Finalizar Operação\n");
    printf("Digite uma opção: ");
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
        
        printf("Digite o CPF: ");
        fgets(pessoa.CPF, sizeof(pessoa.CPF), stdin);
        pessoa.CPF[strcspn(pessoa.CPF, "\n")] = '\0';
        
        printf("Cadastro realizado!\n");
        
        
    }
    
    else if(tipo == PROFESSOR){

        pessoa.status = PROFESSOR;

        printf("Digite a matrícula: ");
        scanf("%d" , &pessoa.matricula);
        limparBuffer();
            
        printf("Digite o nome do Professor: ");
        fgets(pessoa.nome, sizeof(pessoa.nome), stdin);
        pessoa.nome[strcspn(pessoa.nome, "\n")] = '\0';
        
        printf("Digite o sexo (M/F): ");
        scanf("%c",&pessoa.sexo);
        limparBuffer();
        
        printf("Digite a data de nascimento: ");
        fgets(pessoa.dataDeNascimento, sizeof(pessoa.dataDeNascimento), stdin);
        pessoa.dataDeNascimento[strcspn(pessoa.dataDeNascimento, "\n")] = '\0';
        
        printf("Digite o CPF: ");
        fgets(pessoa.CPF, sizeof(pessoa.CPF), stdin);
        pessoa.CPF[strcspn(pessoa.CPF, "\n")] = '\0';

        printf("Cadastro realizado!\n");
        
        
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

void menuProfessor(){
    printf("----Menu Professor----\n");
    printf("1 - Cadastrar Professor\n");
    printf("2 - Listar Professor\n");
    printf("3 - Atualizar Professor\n");
    printf("4 - Deletar Professor\n");
    printf("0 - Sair\n");
    printf("Escolha uma opção: ");
}

void menuAtualizarDisciplina(){
    printf("\n------------ Atualizar Disciplina --------------\n");
    printf("1 - Atualizar Código\n");
    printf("2 - Atualizar Titulo\n");
    printf("3 - Atualizar Semestre\n");
    printf("4 - Atualizar Professor\n");
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

void menuListarDisciplina(){
    printf("------------ Listar Disciplina --------------\n");
    printf("1 - Listar Código\n");
    printf("2 - Listar Titulo\n");
    printf("3 - Listar Semestre\n");
    printf("4 - Listar Professor\n");
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
        limparBuffer();
        
        if(tipo == ALUNO | tipo == PROFESSOR){
            switch(opcaoMenuListar){
                case 1:{
                    for(int i = 0; i < qtd_pessoas; i++){
                        if(pessoa[i].status == tipo){
                            printf("-------------------------------------------------------------------\n");
                            printf("| %d | %s | %s | %c | %s |\n" , pessoa[i].matricula , pessoa[i].nome , pessoa[i].CPF, pessoa[i].sexo, pessoa[i].dataDeNascimento);
                        }
                    }
                    break;
                }
                case 2:{
                    for(int i = 0; i < qtd_pessoas; i++){
                        if(pessoa[i].status == tipo){
                            printf("-------------------------------------------------------------------\n");
                            printf("%s\n" , pessoa[i].nome);
                        }
                    }
                    break;
                }
                case 3:{
                    for(int i = 0; i < qtd_pessoas; i++){
                        if(pessoa[i].status == tipo){
                            printf("-------------------------------------------------------------------\n");
                            printf("%s\n" , pessoa[i].CPF);
                        }
                    }
                    break;
                }
                case 4:{
                    for(int i = 0; i < qtd_pessoas; i++){
                        if(pessoa[i].status == tipo){
                            printf("-------------------------------------------------------------------\n");
                            printf(" %c\n" , pessoa[i].sexo);
                        }
                    }
                    break;
                }
                case 5:{
                    for(int i = 0; i < qtd_pessoas; i++){
                        if(pessoa[i].status == tipo){
                            printf("-------------------------------------------------------------------\n");
                            printf("%s\n" , pessoa[i].dataDeNascimento);
                        }    
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
    int aux_matri;

    printf("Digite a Matrícula da pessoa a ser atualizada: ");
    scanf("%d" , &aux_matri);
    limparBuffer();

    for(int i = 0; i < qtd_pessoas; i++){
        if(pessoa[i].status == tipo && aux_matri == pessoa[i].matricula){
            
            menuAtualizar();
            scanf("%d" , &opcao);
            limparBuffer();
                
            switch(opcao){

                case 1:{
                    printf("Digite a nova Matrícula: ");
                    scanf("%d" , &pessoa[i].matricula);
                    limparBuffer();
                            
                    break;
                }

                case 2:{
                    printf("Digite a novo nome: ");
                    fgets(pessoa[i].nome, sizeof(pessoa[i].nome), stdin);
                    pessoa[i].nome[strcspn(pessoa[i].nome, "\n")] = '\0';   
                           
                    break;
                }

                case 3:{
                    printf("Digite a novo CPF: ");
                    fgets(pessoa[i].CPF, sizeof(pessoa[i].CPF), stdin);
                    pessoa[i].CPF[strcspn(pessoa[i].CPF, "\n")] = '\0';   
                    
                    break;
                }

                case 4:{
                    printf("Digite a novo Sexo: ");
                    scanf(" %c", pessoa[i].sexo);
                    limparBuffer();
                        
                    break;
                }
                case 5:{
                    printf("Digite a nova Data: ");
                    fgets(pessoa[i].dataDeNascimento, sizeof(pessoa[i].dataDeNascimento), stdin);
                    pessoa[i].dataDeNascimento[strcspn(pessoa[i].dataDeNascimento, "\n")] = '\0';   
                        
                    break;
                }
                default:{
                    printf("Operação Finalizada\n");
                    
                }
            }
            printf("Atualização Feita com sucesso!\n");
        }
    }
    
    if(qtd_pessoas == 0){
        printf("Não foram encontrados registros");
    }
        
}

void deletar(Pessoa pessoa[] ,TipoPessoa tipo, int qtd_pessoas){
    int aux_matri;

    printf("Digite a Matrícula da pessoa a ser deletada: ");
    scanf("%d" , &aux_matri);
    limparBuffer();

    for(int i = 0; i < qtd_pessoas; i++){
        if(pessoa[i].status == tipo && aux_matri == pessoa[i].matricula){

            for(int j = i; j < qtd_pessoas - 1; j++){
                pessoa[j] = pessoa[j + 1];
            }   

        }    
        (qtd_pessoas)--;

    }
    if(qtd_pessoas == 0){
        printf("Não existem pessoas cadastradas.\n");
    }
}

Disciplina cadastrarDisciplina(Disciplina disciplina){
    
    printf("Digite o código da disciplina: \n");
    scanf("%d" , &disciplina.codigo);
    limparBuffer();

    printf("Digite o titulo da disciplina: \n");
    fgets(disciplina.titulo, sizeof(disciplina.titulo) , stdin);
    disciplina.titulo[strcspn(disciplina.titulo, "\n")] = '\0';
    
    printf("Digite o semestre da Disciplina: \n");
    scanf("%d" , &disciplina.semestre);
    limparBuffer();

    printf("Digite o nome do professor da Disciplina: \n");
    fgets(disciplina.nomeProfessor, sizeof(disciplina.nomeProfessor), stdin);
    disciplina.nomeProfessor[strcspn(disciplina.nomeProfessor, "\n")] = '\0';
    
    printf("Cadastro Realizado\n");

    return disciplina;
}

void atualizarDisciplina(Disciplina disciplina[], int qtd_disciplinas){
    int opcao;
    int aux_codigo;

    printf("Digite o código da disciplina a ser atualizada: ");
    scanf("%d" , &aux_codigo);
    limparBuffer();

    for(int i = 0; i < qtd_disciplinas; i++){
        if(aux_codigo == disciplina[i].codigo){
            
            menuAtualizarDisciplina();
            scanf("%d" , &opcao);
            limparBuffer();
            
            switch(opcao){
                // 1 - Código
                case 1:{
                    printf("Digite o novo código: ");
                    scanf("%d" , &disciplina[i].codigo);
                    limparBuffer();

                    break;
                }
                // 2 - titulo
                case 2:{
                    printf("Digite o novo titulo: ");
                    fgets(disciplina[i].titulo, sizeof(disciplina[i].titulo), stdin);
                    disciplina[i].titulo[strcspn(disciplina[i].titulo, "\n")] = '\0';

                    break;
                }
                // 3 - semestre
                case 3:{
                    printf("Digite o novo semestre: ");
                    scanf("%d" , &disciplina[i].semestre);
                    limparBuffer();

                    break;
                }
                // 4 - professor
                case 4:{
                    printf("Digite o nome do novo professor: ");
                    fgets(disciplina[i].nomeProfessor, sizeof(disciplina[i].nomeProfessor), stdin);
                    disciplina[i].nomeProfessor[strcspn(disciplina[i].nomeProfessor, "\n")] = '\0';

                    break;
                }
                // 0 - Sair
                default:{
                    printf("Operação Finalizada");
                    
                }
            }
        }        
    }
}    

void listarDisciplina(Disciplina disciplina[], int qtd_disciplinas){
    int opcao;
    int aux_codigo;
    int sair = 0;

    printf("Digite o código da disciplina a ser listada: ");
    scanf("%d" , &aux_codigo);
    limparBuffer();

    while(!sair){
        menuListarDisciplina();
        scanf("%d" , &opcao);
        limparBuffer();
        
            switch(opcao){
                case 1:{
                    for(int i = 0; i < qtd_disciplinas; i++){
                        printf("-------------------------------------------------------------------\n");
                        printf("| %d | %s | %d | %s |\n" , disciplina[i].codigo , disciplina[i].titulo , disciplina[i].semestre, disciplina[i].nomeProfessor);
                    
                    }
                    break;
                }
                case 2:{
                    for(int i = 0; i < qtd_disciplinas; i++){
                        printf("-------------------------------------------------------------------\n");
                        printf("%s\n" , disciplina[i].titulo);
                    }
                    break;
                }
                case 3:{
                    for(int i = 0; i < qtd_disciplinas; i++){
                        printf("-------------------------------------------------------------------\n");
                        printf("%d\n" , disciplina[i].semestre);
                    }
                    break;
                }
                case 4:{
                    for(int i = 0; i < qtd_disciplinas; i++){
                        printf("-------------------------------------------------------------------\n");
                        printf("%s\n" , disciplina[i].nomeProfessor);
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

void deletarDisciplina(Disciplina disciplina[], int qtd_disciplinas){
     int aux_codigo;

    printf("Digite o Código da Disciplina a ser deletada: ");
    scanf("%d" , &aux_codigo);
    limparBuffer();

    for(int i = 0; i < qtd_disciplinas; i++){
        if(aux_codigo == disciplina[i].codigo){

            for(int j = i; j < qtd_disciplinas - 1; j++){
                disciplina[j] = disciplina[j + 1];
            }   
            
        }    
        (qtd_disciplinas)--;

    }
    if(qtd_disciplinas == 0){
        printf("Não existem disciplinas cadastradas.\n");
    }
}

Matricula cadastrarMatricula(Matricula m, Pessoa alunos[], int qtd_alunos, Disciplina disciplinas[], int qtd_disciplinas) {
    int alunoExiste = 0, disciplinaExiste = 0;

    printf("Digite a matrícula do aluno: ");
    scanf("%d", &m.matriculaAluno);
    limparBuffer();

    // Verifica se o aluno existe e é do tipo ALUNO
    for (int i = 0; i < qtd_alunos; i++) {
        if (alunos[i].status == ALUNO && alunos[i].matricula == m.matriculaAluno) {
            alunoExiste = 1;
            break;
        }
    }

    if (!alunoExiste) {
        printf("Aluno não encontrado. Matrícula cancelada.\n");
        m.ativo = 0;
        return m;
    }

    printf("Digite o código da disciplina: ");
    scanf("%d", &m.codigoDisciplina);
    limparBuffer();

    // Verifica se a disciplina existe
    for (int i = 0; i < qtd_disciplinas; i++) {
        if (disciplinas[i].codigo == m.codigoDisciplina) {
            disciplinaExiste = 1;
            break;
        }
    }

    if (!disciplinaExiste) {
        printf("Disciplina não encontrada. Matrícula cancelada.\n");
        m.ativo = 0;
        return m;
    }

    m.ativo = 1;
    m.nota = 0.0;
    printf("Matrícula realizada com sucesso!\n");
    return m;
}

void listarMatriculasPorAluno(Matricula matriculas[], int qtd_matriculas, int matriculaAluno) {
    printf("\n--- Disciplinas do Aluno (Matrícula: %d) ---\n", matriculaAluno);
    int encontrou = 0;
    for (int i = 0; i < qtd_matriculas; i++) {
        if (matriculas[i].ativo && matriculas[i].matriculaAluno == matriculaAluno) {
            printf("Código da Disciplina: %d\n", matriculas[i].codigoDisciplina);
            encontrou = 1;
        }
    }
    if (!encontrou) {
        printf("Nenhuma matrícula encontrada para este aluno.\n");
    }
}

void listarAlunosPorDisciplina(Matricula matriculas[], int qtd_matriculas, Pessoa alunos[], int qtd_alunos, int codigoDisciplina) {
    printf("\n--- Alunos Matriculados na Disciplina (Código: %d) ---\n", codigoDisciplina);
    int encontrou = 0;
    for (int i = 0; i < qtd_matriculas; i++) {
        if (matriculas[i].ativo && matriculas[i].codigoDisciplina == codigoDisciplina) {
            // Busca o nome do aluno correspondente
            for (int j = 0; j < qtd_alunos; j++) {
                if (alunos[j].status == ALUNO && alunos[j].matricula == matriculas[i].matriculaAluno) {
                    printf("Matrícula: %d | Nome: %s\n", alunos[j].matricula, alunos[j].nome);
                    encontrou = 1;
                    break;
                }
            }
        }
    }
    if (!encontrou) {
        printf("Nenhum aluno matriculado nesta disciplina.\n");
    }
}

void excluirMatricula(Matricula matriculas[], int *qtd_matriculas, int matriculaAluno, int codigoDisciplina) {
    for (int i = 0; i < *qtd_matriculas; i++) {
        if (matriculas[i].ativo && matriculas[i].matriculaAluno == matriculaAluno && matriculas[i].codigoDisciplina == codigoDisciplina) {
            matriculas[i].ativo = 0;
            printf("Matrícula excluída com sucesso.\n");
            return;
        }
    }
    printf("Matrícula não encontrada.\n");
}