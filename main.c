#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defines
#define MAX_LENGTH_LIST 10 // tamanho máximo de tarefas na lista

// structs - task

typedef struct {
    char name[50 + 1];
    int priority;
    int status;
} task;


// procedimentos de sistema
void clean_screen (); // limpar a tela do terminal
void ascii_windows (); // habilitar exibição de caracteres especiais no 'CMD'

void clean_buffer (); // limpando buffer do teclado


// procedimentos

void welcome (); // exibir mensagem de boas vindas ao usuário
void main_menu (); // exibindo menu de interação com o usuário
void byebye (); // exibindo mensagem de finalização do programa

void type_msg_error (); // exibindo mensagem de erro

// procedimentos - eventos

// listagem de tarefas
int valid_qtd_list (int register_task); // valida se existem tarefas na lista ou se vai ultrapassar o limite de tarefas
void list_task (task tsk[MAX_LENGTH_LIST], int qtd_task); // listar as tarefas


// adicionando tarefas

void add_task(task list_task[MAX_LENGTH_LIST], int qtd_task); // adicionando tarefa à lista de tarefas



// main
int main () {

    // variaveis
    int usr_options;
    task list[MAX_LENGTH_LIST];
    int task_qtd = 0; // quantidade de tarefas já criadas

    // mensagem inicial
    welcome();
    // solicitando o caractere 'New Line'
    printf("Por favor, pressione a tecla <ENTER> para iniciar...");
    while(getchar() != '\n');

    // limpando o terminal
    clean_screen();

    // iniciando to-do
    do {
        // capturando entrada do usuario
        main_menu();
        // capturando entrada do usuario e verificando tipos
        if (scanf("%d", &usr_options) != 1) {
           clean_buffer(); // limpando buffer
            type_msg_error(); // exibindo mensagem de erro
            continue;
        }

        // limpando o buffer
        clean_buffer();

        switch (usr_options) {
            case 1:
                // limpando terminal
                clean_screen();
                
                putchar('\n'); // pulando uma linha
                puts("========================================");
                puts("\tMINHAS TAREFAS\t");
                puts("========================================");

                // verificando se existem tarefas já criadas
                if (valid_qtd_list(task_qtd)) {
                    // listando tarefas
                    list_task(list, task_qtd);
                } else {
                    puts("Não existem tarefas para serem visualizadas!");
                }

                putchar('\n'); // pulando uma linha
                printf("Deseja voltar ao menu inicial (1- sim, 5- não)? ");
                // capturando entrada do user e verificando tipo
                if(scanf("%d", &usr_options) != 1) {
                    // limpando buffer
                    clean_buffer();
                    // limpando tela
                    clean_screen();
                    // exibindo mensagem de erro
                    type_msg_error();
                    // finalizando programa
                    byebye();
                    exit(1);
                } else if (usr_options != 1) {
                    // limpando tela
                    clean_screen();
                    // finalizando programa
                    byebye();
                    exit(1);
                } else {
                    // limpando buffer
                    clean_buffer();
                    continue;
                }

                
                break;
            case 2:

                // limpando terminal
                clean_screen();

                putchar('\n'); // pulando uma linha
                puts("========================================");
                puts("\tADICIONANDO TAREFAS\t");
                puts("========================================");
                putchar('\n'); // pulando uma linha

                if (task_qtd >= MAX_LENGTH_LIST) {
                    // limpando tela
                    clean_screen();

                    puts("Não é possível adicionar tarefa!\nNúmero de tarefas máximas atingido, retorne ao menu...");

                    continue;
                }

                add_task(list, task_qtd);
                clean_buffer();
                task_qtd++;

                putchar('\n'); // pulando uma linha
                printf("Deseja voltar ao menu inicial (1- sim, 5- não)? ");
                // capturando entrada do user e verificando tipo
                if(scanf("%d", &usr_options) != 1) {
                    // limpando buffer
                    clean_buffer();
                    // limpando tela
                    clean_screen();
                    // exibindo mensagem de erro
                    type_msg_error();
                    // finalizando programa
                    byebye();
                    exit(1);
                } else if (usr_options != 1) {
                    // limpando tela
                    clean_screen();
                    // finalizando programa
                    byebye();
                    exit(1);
                } else {
                    // limpando buffer
                    clean_buffer();
                    continue;
                }

                break;
            case 3:
                putchar('\n');
                puts("Ainda estamos construindo... aguarde!");
                exit(1); // retornando status 1
                break;
            case 4:
                putchar('\n');
                puts("Ainda estamos construindo... aguarde!");
                exit(1); // retornando status 1
                break;
            default:
                byebye(); // finalizando o programa
                exit(1); // retornando status 1
        }
    } while(1);

    return 0;
}



// procedimentos de sistema
void clean_screen () {

    /*
        Limpando a tela do terminal
    */

    #ifdef _WIN32 // verificando se o sistema operacional é windows
    system("cls");
    #else
    system("clear");
    #endif
}



void ascii_windows () {

    /*
        Habilitando a impressão de caracteres especiais no prompt de comando
    */

   #ifdef _WIN32 // verificando se o sistema operacional é windows
   system("chcp 65001");
   #endif

}



void clean_buffer () {

    /*
        Limpando buffer do teclado
    */

    while (getchar() != '\n');
}



// procedimentos 

void welcome () {

    /*
        Exibindo mensagem de boas vindas ao usuario
    */

    putchar('\n'); // pulando uma linha
    puts("Bem-vindo ao EasyTasker!");
    puts("O EasyTasker é um aplicativo simples e eficiente para\najudar você a organizar suas tarefas do dia a dia.");
    putchar('\n'); // pulando uma linha
}



void main_menu () {

    /*
        Exibindo menu de interação ao usuário
    */

    putchar('\n'); // pulando uma linha
    puts("========================================");
    puts("\tMENU PRINCIPAL\t");
    puts("========================================");
    puts("1. Ver Tarefas");
    puts("2. Adicionar Tarefa");
    puts("3. Marcar Tarefa como Concluída");
    puts("4. Excluir Tarefa");
    puts("5. Sair");
    puts("========================================");
    printf("Escolha uma opção (1-5):");

}



void byebye () {

    /*
        exibindo mensagem de finalização do programa
    */

   putchar('\n'); // pulando uma linha
   puts("==================================================");
   puts("EasyTask finalizado! Obrigado por utilizar...");
   puts("==================================================");
   putchar('\n'); // pulando uma linha
}



void type_msg_error () {

    /*
        Exibindo mensagem de erro (entrada de dados)
    */

    putchar('\n'); // pulando uma linha
    puts("========================================");
    puts("Entrada invalida...");
    puts("========================================");
    putchar('\n'); // pulando uma linha
}









// procedimentos - eventos

// listagem de tarefas
int valid_qtd_list (int register_task) {

    /*
        Fazendo a verificação da quantidade de tarefas
    */

   // verificando se existem 0 tarefas cadastradas ou se existem mais de 10
   if (register_task <= 0 || register_task > MAX_LENGTH_LIST) {
    return 0;
   }

   return 1;

}


void list_task (task tsk[MAX_LENGTH_LIST], int qtd_task) {

    /*
        Listando tarefas
    */

    for (int i = 0; i < qtd_task; i++) {
        printf("%d. [%c] %s - Prioridade: %d \n", i + 1, tsk[i].status == 0 ? ' ' : 'X', tsk[i].name, tsk[i].priority);
    }
}




// adicionando tarefas

void add_task(task list_task[MAX_LENGTH_LIST], int qtd_task) {

    /*
        Adicionando tarefa à lista
    */

    printf("Digite o nome da tarefa: "); fgets(list_task[ qtd_task == 0 ? 0 : qtd_task].name, sizeof(list_task[ qtd_task == 0 ? 0 : qtd_task].name), stdin);
    putchar('\n');
    printf("Digite a prioridade da tarefa: "); scanf("%d", &list_task[ qtd_task == 0 ? 0 : qtd_task].priority);
    list_task[ qtd_task == 0 ? 0 : qtd_task].status = 0;

    list_task[ qtd_task == 0 ? 0 : qtd_task].name[strcspn(list_task[ qtd_task == 0 ? 0 : qtd_task].name, "\n")] = '\0';
    
}