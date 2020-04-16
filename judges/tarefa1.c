#include <stdio.h>
#include <stdlib.h>

typedef struct {
int codigo;
int matricula;
} TAluno;

typedef struct {
int codigo;
int NAlunos;
int cont;
} TUnidade;

int main()
{
    int n, m, i = 0, a = 0, pergunta = 0;
    scanf("%d", &n);
   
    TUnidade *unidade = (TUnidade*) malloc(n * sizeof(TUnidade));
        if(unidade == NULL){
            printf("ERRO: sem memoria!\n");
            exit(1);
        }
    for(i = 0; i < n; i++){
        scanf("%d %d", &unidade[i].codigo, &unidade[i].NAlunos);
    }
   
    scanf("%d", &m);


    TAluno *bloco = (TAluno*) malloc(m * sizeof(TAluno));
        if(bloco == NULL){
            printf("ERRO: sem memoria!\n");
            exit(1);
        }

    while(bloco[a - 1].codigo != -1){
     
        if((a % m) == 0){
            bloco = (TAluno*) realloc(bloco, (m * sizeof(TAluno)));
        }
        
        scanf("%d", &bloco[a].codigo);
            if(bloco[a].codigo != -1)
                scanf("%d", &bloco[a].matricula);
        
       a++;
       
    }
    
    int c = 0, d = 0, aux = 0;
    
    for(d = 0; d < n; d++){
        for(c = 0; c < a; c++){
            if(bloco[c].codigo == unidade[d].codigo){
                aux++;
                unidade[d].cont = aux;
            }
                
        }
        aux = 0;
    }
    int e = 0, maior = 0;
    
    maior = unidade[0].cont;  // assume que o primeiro é o maior
    for(e=0; e<n; e++){
       if (unidade[e].cont > maior)
          maior = unidade[e].cont;
    }
    
    int g = 0, novo = 0;
    for (g=0; g<n; g++){
        if(unidade[g].cont == maior){
            printf("%d\n", unidade[g].codigo);
            novo = g;
        }
    }
    
    
    int b = 0;
    
    for(b=0; b<a; b++){
        if(bloco[b].codigo == unidade[novo].codigo){
            printf("%d\n", bloco[b].matricula);
        }
    }

    return 0;
}

