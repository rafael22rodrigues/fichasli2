#include <stdio.h>
#include <assert.h>

/*
    A Rainha de Copas é muito gulosa: adora biscoitos.
    E, como já se estava a espera, não tem paciência nenhuma! 
    Ou eles trazem mais biscoitos ou ficam sem cabeça.  

    REQUISITO: Dado um conjunto de 5 soldados (representado pela quantidade de biscoitos que cada um tem), o programa deve retornar a posição
    daquele que possui mais biscoitos (em caso de haver mais do que um com a mesma quantidade máxima de biscoitos deve retornar a posição do soldado mais baixa)

    Cenários Possíveis:
    - 1 2 3 4 5 - 5
    - a b -> Assertion failed (As quantidades de biscoitos não são válidas, até porque não são se quer um número, e por isso o programa dá erro)
    - 10 2 3 4 3 -> 1
    - 2 20 20 11 2 -> 2
    - ...
    
*/
int main() {
    // Como não existe "quantidade de biscoito negativa", consideremos que o mínimo possível que cada soldado pode ter de biscoitos é 0
    int soldadoA, soldadoB, soldadoC, soldadoD, soldadoE, maximo_de_biscoitos = 0;
    //através do scanf são lidas as quantidades de biscoitos dos 5 soldados e através do assert verifica se a quantidade de biscoito é realmente um números inteiro 
    assert(scanf("%d %d %d %d %d", &soldadoA, &soldadoB, &soldadoC, &soldadoD, &soldadoE) == 5);
    //os números de bicoitos lidos são convertidos numa lista de 5 elementos com a mesma ordem pela qual foram inseridos
    int soldados[5]={soldadoA, soldadoB, soldadoC, soldadoD, soldadoE};
    // Determina-se a maior quantidade de biscoitos que foi inserida
    for (int i = 0; i < 5; i++)  if(maximo_de_biscoitos < soldados[i]) maximo_de_biscoitos = soldados[i];
    // Assim que se acha o soldado com o mesmo número de biscoitos que o máximo_de_biscoitos, imprime-se (através do printf) na tela a posição desse mesmo soldado e o programa termina
    for (int i = 1; i <= 5; i++) if(maximo_de_biscoitos == soldados[i-1]) {printf("%d\n", i); return 0;} 
}
/*
Testes(Cenários Testados)

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