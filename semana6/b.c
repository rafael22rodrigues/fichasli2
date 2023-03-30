#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    char nome[20];
    int peso;
    int altura;
} Cozinheiro;

void swapCozinheiro(Cozinheiro *a, int i, int j) {
    Cozinheiro aux = a[i];
    a[i] = a[j];
    a[j] = aux;
}

int abs (int x){
    if(x<0) return -x;
    else return x;
}

void bubblepeso (Cozinheiro *a, int N) {
    int i;
    for (i = 1; i < N; i++) {
        if (abs(90 - a[i].peso) <= abs(90 - a[i - 1].peso) ) {
            swapCozinheiro(a, i - 1, i);
        }
    }
}

void bubblealtura(Cozinheiro *a, int N){
    int j;
    for (j = 1; j < N; j++) {
        if((abs(90-a[j].peso) == abs(90-a[j-1].peso)) && (a[j].altura >=a[j-1].altura)){
            swapCozinheiro(a,j-1,j);
        }
    }
}

void ordenar (Cozinheiro *a, int N){
    int i, j;
    int pesos[N];
    for (i = N; i > 0; i--) {
        bubblepeso(a,i);
    }
    for (j = N; j > 0; j--) {
        bubblealtura(a,j);
    }

    for (int l = 0; l < N-1; l++) {
        if (a[l].peso == a[l+1].peso && a[l].altura == a[l+1].altura){
            int r = strcmp(a[l].nome,a[l+1].nome);
            if (r>0){
                swapCozinheiro(a,l+1,l);
            }
        }
    }
}


int main() {
    int cozinheiros;
    assert(scanf("%d",&cozinheiros)==1);
    Cozinheiro fichas[cozinheiros];
    int i = 0;
    while (i<cozinheiros){
        char s[20];
        assert(scanf("%s", s));
        int p, a;
        assert(scanf("%d %d",&p,&a)==2);
        strcpy(fichas[i].nome,s);
        fichas[i].peso = p;
        fichas[i].altura = a;
        i++;
    }
    ordenar(fichas,cozinheiros);
    for (int j = 0; j < cozinheiros; ++j) {
        printf("%s %d %d", fichas[j].nome,fichas[j].peso,fichas[j].altura);
        printf("\n");
    }
    return 0;
}

