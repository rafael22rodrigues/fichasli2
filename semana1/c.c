#include <stdio.h>
#include <assert.h>

/*
O sargento quer colocar os soldados por ordem crescente de alturas para não haver problemas com a Rainha de Copas.

O programa deve ler uma linha para cada soldado. Cada linha deve conter as alturas de cada soldado.

O programa deve imprimir uma linha com as alturas por ordem crescente, separadas por espaços. 
Isto é, há um espaço a separar cada dois números.

*/
int main() {
    int soldadoA, soldadoB, soldadoC;
    assert(scanf("%d %d %d", &soldadoA, &soldadoB, &soldadoC) == 3);//através do scanf são lidas as 3 alturas e através do assert verifica se são realmente números inteiros
    int soldados[3]= {soldadoA, soldadoB, soldadoC};//as alturas lidas são convertidos num array de 3 elementos com a mesma ordem pela qual foram inseridos
    int i, j, aux; //as variáveis auxiliares serão usadas exclusivamente no ciclo em baixo
    //Pelo ciclo a seguir o array soldados definido acima é colocado por ordem crescente
    for(i = 0; i < 3; i++){
        j = i;
        while((j > 0) && (soldados[j] < soldados[j - 1])) {
            aux = soldados[j];
            soldados[j] = soldados[j - 1];
            soldados[j - 1] = aux;
            j--;
        }
    }
    printf("%d %d %d\n", soldados[0], soldados[1], soldados[2]); // por fim imprime-se as alturas dos soldados por ordem crescente
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





