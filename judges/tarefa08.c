#include <stdio.h>
#include <stdlib.h>

struct NO{
    int info;
    struct NO *esq;
    struct NO *dir;
};

typedef struct NO* ArvBin;
 
ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}
 
 
int insere_ArvBin(ArvBin* raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo == NULL)
        return 0;
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;
 
    if(*raiz == NULL)
        *raiz = novo;
    else{
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(valor == atual->info){
                free(novo);
                return 0;//elemento já existe
            }
 
            if(valor > atual->info)
                atual = atual->dir;
            else
                atual = atual->esq;
        }
        if(valor > ant->info)
            ant->dir = novo;
        else
            ant->esq = novo;
    }
    return 1;
}
 
 
 void posOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        posOrdem_ArvBin(&((*raiz)->esq));
        posOrdem_ArvBin(&((*raiz)->dir));
        printf("%d\n",(*raiz)->info);
    }
}

int main()
{
    int T, n, i=0;
    scanf("%d", &T);
    ArvBin* raiz = cria_ArvBin();
    for(i=0; i<T; i++){
        scanf("%d", &n);
        insere_ArvBin(raiz, n);
    }
    for(i=0; i<T; i++)
        scanf("%d", &n);
    posOrdem_ArvBin(raiz);

    return 0;
}
