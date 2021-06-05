// @autor: Felipe Ucelli

#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

//Identificação do sistema operacional
#ifdef __unix__
    #include <stdlib.h>

#elif defined(_WIN32) || defined(WIN32)

   #define OS_Windows

#endif

void computed_vote(){
    //Função responsável por imprimir uma frase de sucesso
    printf("\n----------------\n");
    printf("Voto computado!\n");
    printf("----------------\n\n");
}

void screen_wipe(){
    //Fução responsável por limpar o console de acordo com o comando de cada sistema operacional
    #ifdef OS_Windows
        system("cls");
    #else
        system("clear");
    #endif
}

int main(){
    //Implementado vetores na armazenação de dados para melhor perfomace e organização
    int tot_vereador[4] = {0, 0, 0, 0};
    int tot_prefeito[3] = {0, 0, 0};
    bool main_loop = true;

    setlocale(LC_ALL, "portuguese");

    screen_wipe();

    char op_fun[2]; //As opções são obtidas como string para evitar conflito caso o usuário digite uma letra ou caracter especial
    while (main_loop == true){
        printf("[1] Votar\n");
        printf("[2] Apurar votação\n");
        printf("[3] Sair\n\n");

        printf("O que você deseja fazer? ");
        scanf("%s", &op_fun);
        fflush(stdin);

        screen_wipe();

        main_loop = true; //Reatribuição do estato do main_loop para evitar conflitos

        //A ultima posição dos vetorores verifica se não foi digitado outro valor depois de uma opção válida
        if (op_fun[0] == '1' && op_fun[1] == '\000'){
            char op_vereador[4]; //Atribuido uma posição a mais para identificar o ultimo caracter digitado

            printf("[111] João do Frete\n");
            printf("[222] Maria da Pamonha\n");
            printf("[333] Zé da Farmácia\n");
            printf("[444] Nulo\n\n");

            printf("Qual o seu voto para vereador? ");
            scanf("%s", &op_vereador);
            fflush(stdin);

            if (op_vereador[0] == '1' && op_vereador[1] == '1' && op_vereador[2] == '1' && op_vereador[3] == '\000'){
                tot_vereador[0] ++;
                computed_vote();

            }else if (op_vereador[0] == '2' && op_vereador[1] == '2' && op_vereador[2] == '2' && op_vereador[3] == '\000'){
                tot_vereador[1] ++;
                computed_vote();

            }else if (op_vereador[0] == '3' && op_vereador[1] == '3' && op_vereador[2] == '3' && op_vereador[3] == '\000'){
                tot_vereador[2] ++;
                computed_vote();

            }else if (op_vereador[0] == '4' && op_vereador[1] == '4' && op_vereador[2] == '4' && op_vereador[3] == '\000'){
                tot_vereador[3] ++;
                computed_vote();

            }else {
                printf("\n--------------------------------------------\n");
                printf("Opção inválida, seu voto não foi computado!\n");
                printf("--------------------------------------------\n\n");
            }

            char op_prefeito[3];

            printf("[11] Dr Zureta\n");
            printf("[22] Senhor Gomes\n");
            printf("[44] Nulo\n\n");

            printf("Qual o seu voto para prefeito? ");
            scanf("%s", &op_prefeito);
            fflush(stdin);

            if (op_prefeito[0] == '1' && op_prefeito[1] == '1' && op_prefeito[2] == '\000'){
                tot_prefeito[0] ++;
                computed_vote();

            }else if (op_prefeito[0] == '2' && op_prefeito[1] == '2' && op_prefeito[2] == '\000'){
                tot_prefeito[1] ++;
                computed_vote();

            }else if (op_prefeito[0] == '4' && op_prefeito[1] == '4' && op_prefeito[2] == '\000'){
                tot_prefeito[2] ++;
                computed_vote();

            }else{
                printf("\n--------------------------------------------\n");
                printf("Opção inválida, seu voto não foi computado!\n");
                printf("--------------------------------------------\n\n");
            }

        }else if (op_fun[0] == '2' && op_fun[1] == '\000'){
            printf("---------------------------------------\n");
            printf("Apuração Vereador Final:\n\n");
            printf("Vereador João do Frete: %d votos\n", tot_vereador[0]);
            printf("Vereadora Maria da Pamonha: %d votos\n", tot_vereador[1]);
            printf("Vereador Zé da Farmácia: %d votos\n", tot_vereador[2]);
            printf("Votos Nulos: %d votos\n\n", tot_vereador[3]);
            printf("----------------------------------------\n");
            printf("Apuração Prefeito Final:\n\n");
            printf("Prefeito Dr Zuereta: %d votos\n", tot_prefeito[0]);
            printf("Prefeito Senhor Gomes: %d votos\n", tot_prefeito[1]);
            printf("Votos Nulos: %d votos\n\n", tot_prefeito[2]);
            printf("----------------------------------------\n\n");


        }else if (op_fun[0] == '3' && op_fun[1] == '\000'){
            //Altera o estado do main_loop e sai da aplicação
            main_loop = false;


        }else{
            //Imprime uma mensagem de erro caso a opção escolida for inválida
            printf("----------------------------------\n");
            printf("Por favor, digite um opção v�lida!\n");
            printf("----------------------------------\n\n");
        }

    }

    printf("-----------------------------------\n");
    printf("OBRIGADO POR USAR ESTE SOFTWARE!!!\n");
    printf("-----------------------------------\n");

    return 0;
}
