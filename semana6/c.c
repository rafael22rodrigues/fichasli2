#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int ordem;
    char dificuldade;
    int preco;
}Pedido;

void swapPedido (Pedido *a, int i, int j){
    Pedido aux;
    aux = a[i];
    a[i] = a[j];
    a[j] = aux;
}

void bubblepreco(Pedido *a, int N){
    int i;
    for (i = 1; i < N; i++) {
        if (a[i].preco>a[i-1].preco){
            swapPedido(a,i-1,i);
        }
    }
}

void bubbledificuldade(Pedido *a, int N){
    int i;
    for (i = 1; i < N; i++) {
        if (a[i].preco == a[i-1].preco && a[i].dificuldade<a[i-1].dificuldade){
            swapPedido(a,i-1,i);
        }
    }
}

void ordenar (Pedido *a, int N){
    int i, j;
    for (i = N; i >0 ; i--) {
        bubblepreco(a,i);
    }
    for (j = N; j >0 ; j--) {
        bubbledificuldade(a,j);
    }
}

int main(){
    int n;
    assert(scanf("%d",&n)==1);
    int i = 0;
    Pedido pedidos[100];
    while (i<n){
        int ord;
        char dif;
        int pr;
        assert(scanf("%d %c %d",&ord,&dif,&pr)==3);
        pedidos[i].ordem = ord;
        pedidos[i].dificuldade = dif;
        pedidos[i].preco = pr;
        i++;
    }
    ordenar(pedidos,n);
    for (int j = 0; j <n ; j++) {
        printf("%d %c %d\n", pedidos[j].ordem, pedidos[j].dificuldade, pedidos[j].preco);
    }
    return 0;
}

