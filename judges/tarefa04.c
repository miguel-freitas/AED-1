#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INICIO 0
#define MAXTAM 1000

typedef struct {
    char nome[20];
    
} TItem;

typedef struct {
    TItem Item[MAXTAM];
    int Primeiro, Ultimo;
    int tamanho;
} TLista;


void TLista_Inicia(TLista *pLista)
{
pLista->Primeiro = INICIO;
pLista->Ultimo = pLista->Primeiro;
pLista->tamanho = 0;
} /* TLista_Inicia */


int TLista_EhVazia(TLista *pLista)
{
return (pLista->Primeiro == pLista->Ultimo);
} /* TLista_EhVazia */


int TLista_Tamanho(TLista *pLista)
{
return (pLista->Ultimo - pLista->Primeiro);
} /* TLista_Tamanho */


int TLista_Insere(TLista *pLista, int p, TItem x)
{
int q;
if ((pLista->Ultimo == MAXTAM) || (p < pLista->Primeiro) || (p > pLista->Ultimo))
return 0;
for (q = pLista->Ultimo-1; q >= p; q--)
pLista->Item[q+1] = pLista->Item[q];
pLista->Item[p] = x;
pLista->Ultimo++;
pLista->tamanho++;
return 1;
} /* TLista_Insere */


int TLista_Retira(TLista *pLista, int p, TItem *pX)
{
int q;
if (TLista_EhVazia(pLista) || (p < pLista->Primeiro) || (p >= pLista->Ultimo)){
return 0;
}
*pX = pLista->Item[p];
for (q = p+1; q < pLista->Ultimo; q++){
pLista->Item[q-1] = pLista->Item[q];
}
pLista->Ultimo--;
pLista->tamanho--;
return 1;
} /* TLista_Retira */

int main(){
    int i=0, n, k, K, aux;
    char nome[20];
    TLista lista;
    TLista_Inicia(&lista);
    scanf("%d", &n);
    scanf("%d", &k);
    TItem crianca;
    K = k;
    for(i=0; i<n; i++){
        
        scanf("%s", nome);
        strcpy(crianca.nome, nome);
        TLista_Insere(&lista, i, crianca);
    }
    int divisao;
    int Tamanho = lista.tamanho;
    while (lista.tamanho > 0){
        divisao = k / Tamanho;
        k = k - (divisao * Tamanho);
        TLista_Retira(&lista, k, &crianca);
        aux = k + K;
        k = aux;
        Tamanho = Tamanho - 1;
        printf("%s\n", crianca.nome);
    }
}

