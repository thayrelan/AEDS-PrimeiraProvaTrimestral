#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*Reinicializa as variáveis do programa*/

void Reinicializa(_Bool *Estado, int *Total_Inseridos, int *Total_Retirados){
    int i;
    for(i  =0; i < 3; i++){
        Estado[i] = 0;
    }
    *Total_Inseridos = 0;
    *Total_Retirados = 0;
}

/*Verifica se é uma fila de prioridade observando se o primeiro elemento que foi retirado é o maior
  elemento, depois se o segundo retirado é o segundo maior e doravante. Ao final retorn true caso 
  tenham sido retirados atendendo esses requisitos e false caso contrário
*/

int Verifica_Fila_Prioridade(int *Entrada, int *Saida, int Total_Inseridos, int Total_Retirados){
    int *tempin = (int*) malloc (sizeof(int) * Total_Inseridos);
    int i, j, Maior, Verdadeiro = 0, Posicao, Estado;  

    for(i = 0; i < Total_Inseridos; i++){
        tempin[i] = Entrada[i];
    }
    for(i = 0; i < Total_Retirados; i++){
        Maior = 0;
        for(j = 0; j < Total_Inseridos; j++){       
            if(Maior < tempin[j]){
                Maior = tempin[j];
                Posicao = j;
            }          
        }
        if(Saida[i] == Maior){   
            Verdadeiro++;
        }
        tempin[Posicao] = 0;
    }
    if(Verdadeiro == Total_Retirados){
        Estado = true; 
    }
    else{
        Estado = false; 
    }
    free(tempin);
    return Estado;
}

/*
  Verifica se o primeiro elemento a ser inserido é o primeiro a ser retirado, o segundo a entrar é
  o segundo a sair e assim conscecutivamente, retorna true caso sim e false caso contrário. 
*/

int Verifica_Fila(int *Entrada, int *Saida, int Total_Inseridos, int Total_Retirados){
    int Estado = true, i;

    for(i = 0; i < Total_Inseridos; i++){     
        if(Entrada[i] != Saida[i]){
            Estado = false;
            break;        
        }
        Total_Retirados--;
    }
    return Estado; 
}

/*
  Verifica se o primeiro elemento a ser inserido é o pultimo a ser retirado, o segundo a entrar é
  o penúltimo a sair e assim conscecutivamente, retorna true caso sim e false caso contrário. 
*/

int Verifica_Pilha(int *Entrada, int *Saida, int Total_Inseridos, int Total_Retirados){
   int i, Estado = true;

   for(i = 0; i < Total_Inseridos; i++){    
        if(Entrada[Total_Retirados-1] != Saida[i]){ 
            Estado = false; 
            break;   
        }
        Total_Retirados--;
    } 
    return Estado; 
}

    /*  
    Tendo a variavel do tipo _Bool armazenando os estados das funções acima, seremos capazes
    de determinar com qual tipo de estrutura estamos lidando. Sendo essa, tendo seus espaços
    organizados da seguinte forma. 

        Estado[0]: Reservado ao resultado de Verifica_Pilha
        Estado[1]: Reservado ao resultado de Verifica_Fila
        Estado[2]: Reservado ao resultado de Verifica_Fila_Prioridade

    */

void Imprime_Tipo(_Bool *Estado){
    int i, Verdadeiro = 0; 

    for(i = 0; i < 3; i++){
        Verdadeiro = (int)Estado[i] + Verdadeiro;
    }  
    if(Verdadeiro > 1){
        printf("not sure\n");
    }
    else if (Estado[2] == true){
        printf("priority queue\n");
    }
    else if (Estado[1] == true){
        printf("queue\n");
    }
    else if (Estado[0] == true){
        printf("stack\n");
    }
    else{
        printf("impossible\n");
    }
}