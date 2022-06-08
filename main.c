#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "trimestral.h"

int main(){

    /*Declaração de variáveis:

        Estado[0]: Reservado à pilha
        Estado[1]: Reservado à fila
        Estado[2]: Reservado à fila de prioridade

    */
    FILE *input;
    _Bool Estado[3]; 
    int Saida[MAXIMO], Entrada[MAXIMO]; 
    int Total_Comandos, Comandos, Valor; 
    int Total_Inseridos, Total_Retirados;  

    /*
    Obtenção dos valores contidos no arquivo "input.txt"
    */
    input = fopen("input.txt", "r");
    while(!feof(input)){
     
        Reinicializa(Estado, &Total_Inseridos, &Total_Retirados); 
        
        do{ 
            fscanf(input, "%d", &Total_Comandos);
        }while(Total_Comandos > MAXIMO || Total_Comandos < 1);
       
        while(Total_Comandos != 0 ){
            fscanf(input, "%d", &Comandos);
            fscanf(input, "%d", &Valor);
            if(Comandos != 1 && Comandos != 2){
                printf("program terminated: unexpected error\n");
                return 0;
            }
            if(Valor > 100 || Valor < 0){
                printf("program terminated: unexpected error\n");
                return 0;
            }
            if(Comandos == 1){
                Entrada[Total_Inseridos] = Valor;
                Total_Inseridos++;
            }
            else if(Comandos == 2){
                Saida[Total_Retirados] = Valor; 
                Total_Retirados++;
            }
            else{
            }
            Total_Comandos--;
        }
        /*Processo de verificação de estado e impressão do tipo de estrutura que está sendo lidada:
            false: 0
            true: 1
        */
        Estado[0] = Verifica_Pilha(Entrada, Saida, Total_Inseridos, Total_Retirados);
        Estado[1] = Verifica_Fila(Entrada, Saida, Total_Inseridos, Total_Retirados);
        Estado[2] = Verifica_Fila_Prioridade(Entrada, Saida, Total_Inseridos, Total_Retirados);
        Imprime_Tipo(Estado);
    }
    fclose(input);
    
    return 0;
}