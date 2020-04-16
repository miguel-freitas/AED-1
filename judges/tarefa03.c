#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXTAM 65536
 
typedef struct {
int indice;
int forca;
} TItem;
 
TItem dados(int indice, int forca){
TItem competidor;
competidor.indice = indice;
competidor.forca = forca;
return competidor;
}
 
typedef struct {
TItem Item[MAXTAM];
int Frente, Tras;
int tamanho;
} TFila;
 
 
void TFila_Inicia(TFila *pFila)
{
pFila->Frente = 0;
pFila->Tras = 0;
pFila->tamanho = 0;
} /* TFila_Inicia */
 
 
int TFila_EhVazia(TFila *pFila)
{
return (pFila->Frente == pFila->Tras);
} /* TFila_EhVazia */
 
 
int TFila_Enfileira(TFila *pFila, TItem x)
{
pFila->Item[pFila->Tras] = x;
pFila->Tras = (pFila->Tras + 1) % MAXTAM;
pFila->tamanho++;
return 1;
} /* TFila_Enfileira */
 
 
int TFila_Desenfileira(TFila *pFila, TItem *pX)
{
if (TFila_EhVazia(pFila))
return 0;
*pX = pFila->Item[pFila->Frente];
pFila->Frente = (pFila->Frente + 1) % MAXTAM;
pFila->tamanho--;
return 1;
} /* TFila_Desenfileira */
 
 
int main(){
    TFila pFila;
    int n, k, ncompetidores, i=0;
    int forca1;
    TItem a, b;
 
    TFila_Inicia(&pFila);        
 
    scanf("%d %d", &n, &k);
    ncompetidores = pow(2,n);
    
    for (i=0; i<ncompetidores; i++){
        scanf("%d",&forca1);
        TFila_Enfileira(&pFila, dados(i+1, forca1));
        }
    
    while(pFila.tamanho > 1){
        TFila_Desenfileira(&pFila, &a);
        TFila_Desenfileira(&pFila, &b);
            
            if (a.forca >= b.forca){
                forca1 = a.forca - b.forca;
                forca1 = forca1 + k;
                TFila_Enfileira(&pFila, dados(a.indice, forca1));
                }
                
            else{
                forca1 = b.forca - a.forca;
                forca1 = forca1 + k;
                TFila_Enfileira(&pFila, dados(b.indice, forca1));
                }
      
        }
        
  TFila_Desenfileira(&pFila, &a);
  printf("%d",a.indice);
  return 0;
}