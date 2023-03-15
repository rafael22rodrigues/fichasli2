#include <stdio.h>
#include <assert.h>

/*
Ajuda o sargento a colocar os soldados por ordem crescente de alturas para não haver problemas com a Rainha de Copas.
O programa deve receber 3 linhas, uma para cada soldado e escrever as alturas por ordem crescente.




O programa deve ler uma linha para cada soldado. Cada linha contém um número inteiro positivo.

O programa deve imprimir uma linha com as alturas por ordem crescente, separadas por espaços. 
Isto é, há um espaço a separar cada dois números.

*/


int main() {
    int a, b, c;
    assert(scanf("%d %d %d", &a, &b, &c) == 3);//através do scanf são lidos 3 números inteiros positivos e através do assert verifica se são realmente números inteiros
    int array[3]= {a, b, c};//os números lidos são convertidos num array de 3 elementos com a mesma ordem pela qual foram inseridos
    int i, j, aux; //as variáveis auxiliares serão usadas exclusivamente no ciclo em baixo
    /*
        Pelo ciclo a seguir o array definido acima é colocado por ordem decrescente
    */
    for(i = 0; i < 3; i++){
        j = i;

        while((j != 0) && (array[j] > array[j - 1])) {
            aux = array[j];
            array[j] = array[j - 1];
            array[j - 1] = aux;
            j--;
        }
    }
    int l;
    int arrayInvert[3]; // definido um array auxiliar
    /*
    Porém, como é pedido que os números sejam dados por ordem crescente, 
    no ciclo a seguir invertemos os elementos do array que ficou definido pelo ciclo acima
    */
    for(l = 0; l <= 2; l++ )
    {
        arrayInvert[l] = array[2-l];
    }
    printf("%d %d %d\n", arrayInvert[0], arrayInvert[1], arrayInvert[2]); // por fim imprime-se os 3 primeiros elementos de um array (separados por um espaço), já que são as únicas posições com inteiros
    return 0;
}

/*

Input:
14
16
17

Output:
14 16 17

Input:
12
18
13

Output:
12 13 18

Input:
30
20
21

Output:
20 21 30


*/





