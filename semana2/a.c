#include <stdio.h>
#include <assert.h>
/*
    Uma taróloga encontra-se perdida no limbo, e para se guiar ela irá usar as cartas que vai de 1 a 78.
    Caso calhe a carte 1 a coordenada fica (X,Y-1), para a carta 2 fica (X,Y+1), para carta 3 fica (X-1,Y), 4 fica (X+1,Y) e 5 fica (X,Y-1) e assim por adiante... 
    
    REQUISITO: Dado um número inteiro positivo correspondente ao número de comandos e um conjunto de valores de cartas sorteadas (do mesmo tamanho do numero de comandos),
    deve retornar as coordenadas X e Y, que devem ser definidas a partir da definição acima no enunciado

*/
int main() {
    int n;
    //lê-se o número de comandos e através do assert verifica se n é um número inteiro mesmo
    assert(scanf("%d", &n) == 1); 
    // admite-se que o número de comandos é um número inteiro positivo maior que 0, caso contrário os ciclos a seguir não se realizam imprimindo no final "0 0"
    int i = 0; 
    int carta_escolhida; // número da carta correspondente que será alterado ao longo do ciclo a seguir
    int x=0, y=0; //as coordenadas x e y começam os dois no ponto 0
    while (i < n){
        assert(scanf("%d", &carta_escolhida) == 1 ); // o valor da carta_escolhida é atualizado sempre que o ciclo reinicia
        //caso o valor da carta_escolhida seja um valor acima de 78 (número máximo das cartas) ou abaixo de 0, o programa termina retornando o valor 0
        if(carta_escolhida>78 || carta_escolhida<0) return 0; 
        //se o valor da carta_escolhida for múltiplo de 4, a coordenada em x aumenta uma unidade
        if(carta_escolhida%4 == 0) x++;
        //se o valor da carta_escolhida na divisão inteira por 4 der resto 1, a coordenada em y diminui uma unidade     
        else if (carta_escolhida%4 == 1) y--; 
        //se o valor da carta_escolhida na divisão inteira por 4 der resto 2, a coordenada em y aumenta uma unidade
        else if (carta_escolhida%4 == 2) y++;
        //se o valor da carta_escolhida na divisão inteira por 4 der resto 3, a coordenada em x diminui uma unidade
        else if (carta_escolhida%4 == 3) x--;    
        i++; // sempre que é adicionada uma unidade a i o ciclo reinicia até ser igual a n-1
    }
    printf("%d %d\n", x, y); //imprime-se as coordenadas finais
    //Fim do programa
    return 0;
}
/*
Testes (Cenários Testados)

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



