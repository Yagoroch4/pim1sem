#include <stdio.h>
#include <ctype.h>
#include <locale.h>
#include <string.h>

typedef struct{
char nome[30], dia[3], mes[3], ano[5];
float valor;
}c_pagar;

typedef struct{
char nome[30], data[10];
float valor;
}c_receber;

int main(){

    setlocale (LC_ALL, "portuguese");
    int tam = 5, i = 0, cp = 0, op, retorno;
    char resposta;
    float total_desp = 0;
    c_pagar pagar[100];
    c_receber receber[100];


    do{
        printf("----------------------------------------------\n");
        printf("------CFA - CONTROLE DE FLUXO AUTOMOTIVO------\n");
        printf("----------------------------------------------\n\n");
        printf("\n---------------CADASTROS--------------------\n\n");
        printf("[1] CADASTRAR CONTAS A PAGAR\n");
        printf("[2] CONSULTAR CONTAS A PAGAR\n");
        printf("\nEscolha uma opção:");
        scanf("%d", &op);

        switch(op){
            case 1:     // o usuario cadastra contas a pagar do cliente
            printf("Olá, para efetuar um cadastro de contas a pagar digite os dados abaixo: \n");
            do{
                fflush(stdin);
                printf("Digite o nome da fornecedor: \n");
                gets(pagar[i].nome);
                fflush(stdin);
                printf("Insira o dia de vencimento da conta: \n");
                scanf("%s", &pagar[i].dia);
                fflush(stdin);
                printf("Insira mes de vencimento da conta: \n");
                scanf("%s", &pagar[i].mes);
                fflush(stdin);
                printf("Insira ano de vencimento da conta: \n");
                scanf("%s", &pagar[i].ano);
                fflush(stdin);
                printf("digite o valor da conta: \n");
                scanf("%f", &pagar[i].valor);
                fflush(stdin);
                printf("\nDeseja fazer outro cadastro (s/n)?: ");
                resposta = getche();
                resposta = tolower(resposta); // converte a resposta do usuário para um caractere minúsculo
                printf("\n\n");
                fflush(stdin);
                i++;
                cp++;

            }while(resposta == 's' && i < tam);
        break;

        case 2:{
        char mes[3], ano[5];
        int retorno2;

            if (cp == 0)
                printf("A empresa não possui contas a pagar\n");

            else{
                fflush(stdin);
                printf("\nInforme o mês: ");
                scanf("%s", &mes);
                fflush(stdin);
                printf("\nInforme o ano: ");
                scanf("%s", &ano);

                int existeConta = 0;
                for (i = 0; i < cp; i++){
                    retorno = strcmp(pagar[i].mes,mes); // compara a string e for igual resultado será 0
                    retorno2 = strcmp(pagar[i].ano,ano);
                    if (retorno == 0 && retorno2 == 0){
                        printf("\nFornecedor:%s \n", pagar[i].nome);
                        printf("Data da compra:%02s/%02s/%04s \n", pagar[i].dia, pagar[i].mes, pagar[i].ano);
                        printf("Valor da compra:%.2f \n", pagar[i].valor);
                        total_desp = total_desp + pagar[i].valor;
                        existeConta++;
                    }
                 }
                if (existeConta == 0)
                        printf("não possui despesas para o mes %s e ano %s \n", mes, ano);
             }
                if (total_desp > 0)
                    printf("O total de despesas para o mes %s é %.2f\n", mes, total_desp);
                total_desp = 0;
            break;
            }
        }

    }while (op != 0);

}
