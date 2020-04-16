#include <stdio.h>
#include <stdlib.h>
#define MAXVERTICES 100

typedef int TVertice;

typedef int TAresta;

typedef struct {
    int IncideAresta;
    TAresta Aresta;
} TAdjacencia;

typedef struct {
    TAdjacencia Adj[MAXVERTICES][MAXVERTICES];
    int NVertices;
    int NArestas;
} TGrafo;


/* Inicia as variaveis do grafo */
int TGrafo_Inicia(TGrafo *pGrafo, int NVertices){
    TVertice u, v;
    if (NVertices > MAXVERTICES)
        return 0;
    pGrafo->NVertices = NVertices;
    pGrafo->NArestas = 0;
    for (u = 0; u < pGrafo->NVertices; u++)
        for (v = 0; v < pGrafo->NVertices; v++)
            pGrafo->Adj[u][v].IncideAresta = 0;
    return 1;
}

/* Retorna se existe a aresta (u, v) no grafo */
int TGrafo_ExisteAresta(TGrafo *pGrafo, TVertice u, TVertice v)
{
    return pGrafo->Adj[u][v].IncideAresta;
}

/* Insere a aresta e incidente aos vertices u e v no grafo */
int TGrafo_InsereAresta(TGrafo *pGrafo, TVertice u, TVertice v)
{
    pGrafo->Adj[u][v].IncideAresta = 1;
    pGrafo->Adj[u][v].Aresta = 1;
    pGrafo->NArestas++;
    return 1;
}

/* Retira a aresta e incidente aos vertices u e v no grafo */
int TGrafo_RetiraAresta(TGrafo *pGrafo, TVertice u, TVertice v)
{
    if (! TGrafo_ExisteAresta(pGrafo, u, v))
        return 0;
    pGrafo->Adj[u][v].IncideAresta = 0;
    pGrafo->NArestas--;
    return 1;
}

/* Retorna o numero de vertices do grafo */
int TGrafo_NVertices(TGrafo *pGrafo)
{
    return (pGrafo->NVertices);
}
/* Retorna o numero de arestas do grafo */
int TGrafo_NArestas(TGrafo *pGrafo)
{
    return (pGrafo->NArestas);
}


int main()
{
    int n, d, i=0, j=0, u, v, k=0, e;
    
    scanf("%d" "%d", &n, &d);
    TGrafo pGrafo;
    TGrafo_Inicia(&pGrafo, n);
    
    for(i=0; i<d; i++){
        scanf("%d" "%d", &u, &v);
        TGrafo_InsereAresta(&pGrafo, u-1, v-1);
    }
    
    for(i=0; i<n; i++){
        printf("%d ", i+1);
        for(j=0; j<n; j++){
            if(pGrafo.Adj[j][i].IncideAresta != 0){
                k++;
            }
        }    
        
        printf("%d ", k);
        k=0;
            
        for(j=0; j<n; j++){
            if(pGrafo.Adj[i][j].IncideAresta != 0){
                k++;    
            }
                
        }
        
        printf("%d ", k);
        k=0;
        
        for(j=0; j<n; j++){
            if(TGrafo_ExisteAresta(&pGrafo, i, j) != 0){
                printf("%d ", j+1);
            }    
        }
        
        printf("\n");
    }
    return 0;
}