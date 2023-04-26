#include <stdio.h>
#include <assert.h>


/*
    Uma taróloga encontra-se perdida no limbo, e para se guiar ela irá usar as cartas que vai de 1 a 78.
    Caso calhe a carte 1 a coordenada fica (X,Y-1), para a carta 2 fica (X,Y+1), para carta 3 fica (X-1,Y), 4 fica (X+1,Y) e 5 fica (X,Y-1) e assim por adiante... 
    
    Este programa serve para determinar as coordenadas finais ao fim de um certo percurso.
*/

int main() {
    int n; // o número de comandos
    assert(scanf("%d", &n) == 1); // aqui lê-se o número de comandos e através do assert verifica se n é um número inteiro mesmo
    int i = 0; // admite-se que o número de comandos é um número inteiro positivo maior que 0, caso contrário os ciclos a seguir não se realizam imprimindo no final "0 0"
    int a; // número do comando correspondente que será alterado ao longo do ciclo a seguir
    int x=0, y=0; //um array auxiliar do tamanho do número de comandos servirá para armazenar os valores de a ao longo do ciclo a seguir
    while (i < n){
        assert(scanf("%d", &a) == 1 ); // o valor de a é atualizado sempre que o ciclo reinicia
        if(a>78 || a<0) return 0; // caso o valor registado em a seja um valor acima de 78 (número máximo das cartas) ou abaixo de 0, o programa termina retornando o valor 0
        if(a%4 == 0) x++; //se a posição j do array for múltiplo de 4, x aumenta uma unidade
        else if (a%4 == 1) y--; //se a posição j do array na divisão inteira por 4 der resto 1, y diminui uma unidade
        else if (a%4 == 2) y++; //se a posição j do array na divisão inteira por 4 der resto 2,  aumenta uma unidade
        else if (a%4 == 3) x--; //se a posição j do array na divisão inteira por 4 der resto 3, x diminui uma unidade   
        i++; // sempre que é adicionada uma unidade a i o ciclo reinicia até ser igual a n-1
    }
    printf("%d %d\n", x, y); //imprime-se as coordenadas finais
    return 0;
}

/*

Input:
6
21
42
54
56
54
4

Output:
2 2

Input:
10
54
42
21
45
64
33
51 
75
38
74

Output:
-1 1

Input:
3
67
60
30

Output:
0 1

*/



