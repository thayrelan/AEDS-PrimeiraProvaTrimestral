#include <stdio.h>
#include <stdlib.h>

/*Funcao verify priority verifica se trata-se de uma fila de prioridade
  caso assim seja, retorna 0, caso contrário, retorna 1.*/

int verify_priority(int temp_int_in, int temp_int_out, int *vin, int *vout){
    int i, j, higher = 0, condition = 0, change;
    
    int tempout[100], tempin[100];
    for(i = 0; i < temp_int_out; i++){
        tempout[i] = vout[i];
        
    }
    for(i = 0; i < temp_int_in; i++){
        
        tempin[i] = vin[i];
        
    }
    
    for(i = 0; i < temp_int_out; i++){
        
        for(j = 0; j < temp_int_in; j++){
            
            if(higher < tempin[j]){
                higher = tempin[j];
                change = j;
                
            }          
        }
        
        
        if(vout[i] == higher){
            
            condition++;
        }
        tempin[change] = 0;
        higher = 0;
    }
    if(condition == temp_int_out){
        return 0;
    }
    else{
        return 1;
    }
}


int main(){

    /*
    vet[0] == 1 == queue
    vet[1] == 6 == stack
    vet[2] == 2 == priority queue
    */

    int vet_out[1000], vet_in[1000], vet[3] = {1, 6, 2}; //Variáveis necessárias para o funcionamento do programa 
    int numero_comandos, comando, valor; //Variáveis referentes aos dados usados
    int temp_int_in = 0, temp_int_out = 0, temp, i; //Variáveis de caráter temporário; 
    FILE *input; 
    char temp_char;
    input = fopen("input.txt", "r");
    /*Função recebe dados, o total de comandos bem como os dados a serem usados
    usados*/
    
    while(!feof(input)){
       
        do{ 
            fscanf(input, "%d", &numero_comandos);
            
        }while(numero_comandos > 1000 || numero_comandos < 1);
       
    
    temp_int_in = 0, temp_int_out = 0; 
    i = 0, temp = 0;
    vet[0] = 1;
    vet[1] = 6;
    vet[2] = 2;


    while(numero_comandos != 0 ){
        
        fscanf(input, "%d", &comando);
        fscanf(input, "%d", &valor);
       
        if(comando != 1 && comando != 2){
           
            printf("program terminated: unexpected error\n");
            return 0;
        }
        if(valor > 100 || valor < 0){
          
            printf("program terminated: unexpected error\n");
            return 0;
        }
        if(comando == 1){
            vet_in[temp_int_in] = valor;
            temp_int_in++;
        }
        else if(comando = 2){
            vet_out[temp_int_out] = valor; 
            temp_int_out++;
        }
        else{
        }
        numero_comandos--;
    }

    /*Caso não seja uma filha de prioridade, o vetor vet[2] será 0, esse valor 
      sera futuramente usado para o calculo de qual tipo de estrutura se trata*/

    temp = verify_priority(temp_int_in, temp_int_out, vet_in, vet_out);
    if(temp != 0){
        //printf("it's not a priority queue\n");
        vet[2] = 0;
    }

    /*Verifica se os últimos elementos a entrarem serao os primeiros a sairem
      caso não seja, zera o vetor vet[1], o valor será usado para o calculo 
      futuramente*/

    for(i = 0; i < temp_int_in; i++){
        
        if(vet_in[temp_int_out-1] != vet_out[i]){
            //printf("not a stack\n");
            vet[1] = 0;
            break;   
        }
        temp_int_out--;
    } 

    /*Verifica se o primeiro a entrar é o primeiro a sair, caso não seja, zera
      o vetor vet[0], será usado para o calculo futuramente.*/

    for(i = 0; i < temp_int_in; i++){     
        if(vet_in[i] != vet_out[i]){
            //printf("not a queue\n");
            vet[0] = 0;
            break;        
        }
        temp_int_out--;
    } 

    /*Após tudo isso iremos agora matematicamente descobrir que tipo de estrutura é
      como exemplificado anteriormente, cada tipo de estrutura possui um número que 
      o representa 1 = queue, 6 = stack e 2 = priority stack, esses valores estão 
      armazenados respectivamente em vet[0], vet[1] e vet[2]. Através do programa
      conseguimos saber quais não são, portanto, caso não seja uma das determinadas
      estruturas, o valor contido em vet[n] será zerado*/

    /*O valor resultante da soma após os testes será igual ao tipo de estrutura que
      estamos lidando, por exemplo, caso se trate de uma stack, vet[0] e vet[2] será
      zerado, e ao efetuarmos a soma de vet[0] + vet[1] + vet[2] teremos o valor 6
      ,valor que corresponde ao tipo de estrutura stack, analogamente, caso somente
      vet[1] fosse zerado a resultante seria 3, indicando que a estrutura possa ser
      ou do tipo queue ou priority queue, o mesmo vale caso seja superior a 6*/
      
    temp = 0;
    for(i = 0; i < 3; i++){
        temp = temp + vet[i];   
    }
    if(temp > 6 || temp == 3){
        printf("not sure\n");
    }
    else if (temp == 2){
        printf("priority queue\n");
    }
    else if (temp == 6){
        printf("stack\n");
    }
    else if (temp == 1){
        printf("queue\n");
    }
    else{
        printf("impossible\n");
    }
    };
    fclose(input);
    return 0;
}