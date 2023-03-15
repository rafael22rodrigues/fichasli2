#include <stdio.h>
#include <assert.h>

/*
    A Rainha de Copas é muito gulosa: adora biscoitos.
    E, como já se estava a espera, não tem paciência nenhuma! 
    Ou eles trazem mais biscoitos ou ficam sem cabeça.  

*/

int maxfive(int a[]){//função maxfive que determina o maior elemento de um array com 5 elementos
    int max = 0;    //admite-se que todos os elementos são maiores que 0
    int i = 0;
    while (i<=4){
        if((max < a[i])){
            max = a[i];
        }
        i++;
    }
    return max;
}

int maxline(int a[]){ 
    int m = maxfive(a); //invoca a função anterior
    int r = 1;
    int i = 0;
    while (i<=4){
        if(m == a[i]){
            break; // assim que se chega à primeira posição do maior elemento o ciclo termina
        } else{r++; i++;} // caso contrário o r aumenta um inteiro
    }
    return r; // retorna o valor de r acumulado ao longo do ciclo
}

/*
    Este programa deve receber 5 números inteiros positivos e devolver a posição do maior número
    NOTA: Em caso de empate devolve a ordem mais baixa

*/
int main() {
    int a, b, c, d, e;
    assert(scanf("%d %d %d %d %d", &a, &b, &c, &d, &e) == 5); //através do scanf são lidos 5 números inteiros positivos e através do assert verifica se são realmente números inteiros positivos
    int array[5]={a, b, c, d, e}; //os números lidos são convertidos num array de 5 elementos com a mesma ordem pela qual foram inseridos
    int r = maxline(array); // pela função maxline consegue-se determinar em que (primeira) posição está o maior elemento
    printf("%d\n", r);
    return 0;
}
/*
Input:

53
55
56
58
58

Output:
4

Input:

70
50
67
62
54

Output:
1

Input:

43
54
54
50
50

Output:
2


*/