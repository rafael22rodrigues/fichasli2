#include <stdio.h>
#include <assert.h>

/*
    O sargento quer colocar os soldados por ordem crescente de alturas para não haver problemas com a Rainha de Copas.

    REQUISITO: Dadas as alturas de 3 soldados, deve ser imprimido na tela essas mesmas alturas, mas desta vez por ordem crescente

    Cenários possíveis:

    - 1 2 3 -> 1 2 3 (a ordem não é alterada)
    - 3 2 1 -> 1 2 3 (a ordem é invertida)
    - a b c -> Assertion failed (o programa dá erro, afinal a, b e c não são números inteiros)
    - 3 1 2 -> 1 2 3
    - ...

*/
int main() {
    int soldadoA, soldadoB, soldadoC;
    //através do scanf são lidas as 3 alturas e através do assert verifica se são realmente números inteiros
    assert(scanf("%d %d %d", &soldadoA, &soldadoB, &soldadoC) == 3);
    //as alturas lidas são convertidos numa lista de 3 elementos com a mesma ordem pela qual foram inseridos
    int soldados[3] = {soldadoA, soldadoB, soldadoC};
    //Pelo ciclo a seguir os soldados são colocados por ordem crescente de altura
    for(int i = 0; i < 3; i++){
        // estas variáveis auxiliares são usadas única e exclusivamente no neste ciclo
        int j = i, trocar; 
        // caso a altura de um soldado seja menor que a de outro que foi inserido a uma posição anteriormente, os dois trocam de posição, através do ciclo while a seguir  
        while((j > 0) && (soldados[j] < soldados[j - 1])) {
            trocar = soldados[j];
            soldados[j] = soldados[j - 1];
            soldados[j - 1] = trocar;
            j--;
        }
    }
    // por fim imprime-se as alturas dos soldados por ordem crescente
    printf("%d %d %d\n", soldados[0], soldados[1], soldados[2]); 
    // o programa termina
    return 0;
}
/*
Testes (Cenários Testados)

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





