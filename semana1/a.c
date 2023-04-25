#include <stdio.h>
#include <assert.h>

/*
    A Rainha de Copas é muito gulosa: adora biscoitos.
    E, como já se estava a espera, não tem paciência nenhuma! 
    Ou eles trazem mais biscoitos ou ficam sem cabeça.  

    Este programa deve receber a quantidade de biscoitos que cada soldado tem e devolver a posição do soldado que tem o maior número de biscoitos
    NOTA: Em caso de empate devolve a ordem mais baixa

*/
int main() {
    int soldadoA, soldadoB, soldadoC, soldadoD, soldadoE;
    assert(scanf("%d %d %d %d %d", &soldadoA, &soldadoB, &soldadoC, &soldadoD, &soldadoE) == 5); //através do scanf são lidos 5 números inteiros positivos e através do assert verifica se são realmente números inteiros positivos
    int soldados[5]={soldadoA, soldadoB, soldadoC, soldadoD, soldadoE}; //os números lidos são convertidos num array de 5 elementos com a mesma ordem pela qual foram inseridos
    int maximo_de_biscoitos = 0, soldado_escolhido = 1;
    for (int i = 0; i < 5; i++) if(maximo_de_biscoitos < soldados[i]) maximo_de_biscoitos = soldados[i];
    for (int i = 0; i < 5; i++)
    {
        if(maximo_de_biscoitos == soldados[i]) break;
        else soldado_escolhido++;
    }
    printf("%d\n", soldado_escolhido);
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