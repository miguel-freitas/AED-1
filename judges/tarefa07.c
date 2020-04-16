#include <stdio.h>
#include <stdlib.h>

typedef int TIPOCHAVE;

typedef struct no {
    TIPOCHAVE chave;
    struct no *primFilho;
    struct no *proxIrmao;
} NO;

typedef NO* PONT;


/*cria um novo no na arvore*/
PONT criaNovoNO(TIPOCHAVE ch){
    PONT novo = (PONT)malloc(sizeof(NO));
    novo->primFilho = NULL;
    novo->chave = ch;
    return(novo);
}

/*inicializa uma nova arvore*/
PONT inicializa(TIPOCHAVE ch){
    return(criaNovoNO(ch));
}

PONT buscaChave(TIPOCHAVE ch, PONT raiz){
    if (raiz == NULL) return NULL;
    if (raiz->chave == ch) return raiz;
    PONT p = raiz->primFilho;
    while(p) {
        PONT resp = buscaChave(ch, p);
        if (resp) return(resp);
        p = p->proxIrmao;
    }
    return(NULL);
}

/*insere novo vertice*/
int insere(PONT raiz, TIPOCHAVE novaChave, TIPOCHAVE chavePai){
    PONT pai = buscaChave(chavePai,raiz);
    if (!pai) return(0);
    PONT filho = criaNovoNO(novaChave);
    PONT p = pai->primFilho;
    if (!p) pai->primFilho = filho;
    else {
        while (p->proxIrmao)
            p = p->proxIrmao;
        p->proxIrmao = filho;    
        }
    return(1);
}    

/*imprime a arvore*/    
void exibirArvore(PONT raiz){
    if (raiz == NULL) return;
    printf("(%d",raiz->chave);
    PONT p = raiz->primFilho;
        while (p) {
            exibirArvore(p);
            p = p->proxIrmao;
        }
    printf(")");
}    

int main()
{
    int n, m, i = 0, p, f;
    scanf("%d" "%d", &n, &m);
    
    int r = 1;
    PONT pont;
    pont = inicializa(r);
    
    /*laço para inserir as relaçoes entre os membros da familia*/
    for(i=0; i<m; i++){
        scanf("%d" "%d", &p, &f);
        insere(pont, f, p);
    }  
    
    exibirArvore(pont);
    return 0;
}