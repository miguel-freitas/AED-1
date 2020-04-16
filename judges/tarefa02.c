#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTAM 100

    typedef struct {
        float Item[MAXTAM];
        int Topo;
    }TPilha;

    //inicia a pilha
    void TPilha_Inicia (TPilha *pPilha){
    pPilha->Topo = 0;
    }

    //verifica pilha vazia
    float TPilha_EhVazia(TPilha *pPilha){
    return (pPilha->Topo == 0);
    } 

    //insere na pilha
    float TPilha_Empilha(TPilha *pPilha, float x)
    {
    if (pPilha->Topo == MAXTAM)
        return 0; /* pilha cheia */
    pPilha->Item[pPilha->Topo] = x;
    pPilha->Topo++;
    return 1;
    }

    //retira na pilha
    float TPilha_Desempilha(TPilha *pPilha)
    {
    if (TPilha_EhVazia(pPilha))
        return 0;
    float aux;
    pPilha->Topo--;
    aux = pPilha->Item[pPilha->Topo];
    return aux;
    }

    //tamanho pilha
    float TPilha_Tamanho(TPilha *pPilha)
    {
    return (pPilha->Topo);
    }




int main(){
    int i=0;
    float j=0, k=0, l=0;
    TPilha *pPilha = (TPilha*)malloc(sizeof(TPilha));
    TPilha_Inicia(pPilha);
    
    char expressao[50];
    scanf("%s", expressao); //recebe a expressao
    
    
    for (i=0; i<strlen(expressao); i++){ //laco de tamnho "i" caracteres para avaliar os caracteres da expressao
        switch (expressao[i]){ //switch case para os casos "/", "*", "+", "-" ou caracter letra
            
            case '/':  //para cada caso "/", "*", "+","-" desempilha os ultimos dois valores da pilha realiza a devida operacao e empilha o resultado
                j = TPilha_Desempilha(pPilha);
                k = TPilha_Desempilha(pPilha);
                l = k / j;
                TPilha_Empilha(pPilha, l);
                break;

            case '*': 
                j = TPilha_Desempilha(pPilha);
                k = TPilha_Desempilha(pPilha);
                l = k * j;
                TPilha_Empilha(pPilha, l);
                break;
    
            case '+': 
                j = TPilha_Desempilha(pPilha);
                k = TPilha_Desempilha(pPilha);
                l = k + j;
                TPilha_Empilha(pPilha, l);
                break;

            case '-': 
                j = TPilha_Desempilha(pPilha);
                k = TPilha_Desempilha(pPilha);
                l = k - j;
                TPilha_Empilha(pPilha, l);
                break;


            default: // no caso de nao ser um caracter "/", "*", "+" ou "-" recebe um valor que e empilhado
                scanf("%f", &l);
                TPilha_Empilha(pPilha, l);
                break;
        }
    }
    
    j = TPilha_Desempilha(pPilha);
    printf("%f", j);  //printa o resultado da expressao

    return 0;
}
