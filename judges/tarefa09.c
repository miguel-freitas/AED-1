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
 
 
struct NO* remove_atual(struct NO* atual) {
    struct NO *no1, *no2;
    if(atual->esq == NULL){
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    // no2 é o nó anterior a r na ordem e-r-d
    // no1 é o pai de no2
    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}
 
 
int remove_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* ant = NULL;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
            if(atual == *raiz)
                *raiz = remove_atual(atual);
            else{
                if(ant->dir == atual)
                    ant->dir = remove_atual(atual);
                else
                    ant->esq = remove_atual(atual);
            }
            return 1;
        }
        ant = atual;
        if(valor > atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}
 
 
 
 
 
int consulta_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
            return 1;
        }
        if(valor > atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}
 
 
 
void preOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        printf("(C%d",(*raiz)->info);
        
        preOrdem_ArvBin(&((*raiz)->esq));
        if((*raiz)->esq == NULL)
            printf("()");
        preOrdem_ArvBin(&((*raiz)->dir));
        if((*raiz)->dir == NULL)
            printf("()");
        printf(")");
    }
}
 
 
 
int main()
{
    int q, n, b, i=0;
    
    ArvBin* raiz = cria_ArvBin();
    
    scanf("%d", &q);
    if(q==0){
        printf("()");
        return 0;
    }
    for(i=0; i<q; i++){
        scanf("%d", &n);
    insere_ArvBin(raiz, n);
    }
    scanf("%d", &b);
    
    if(q==1 && n==b){
        printf("()");
        return 0;
    }
    
    if(consulta_ArvBin(raiz, b) == 1){
        remove_ArvBin(raiz, b);
    }
        else{
            insere_ArvBin(raiz, b);
        }    
 
    preOrdem_ArvBin(raiz);
 
    return 0;
}