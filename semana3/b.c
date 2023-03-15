#include <stdio.h>
#include <assert.h>

/*

Era uma vez um jovem chamado Pedro que trabalhava num call center. 
O call center tinha muitos clientes que ligavam para fazer pedidos ou reclamações e, para atender a todos, Pedro precisava ser muito eficiente nas suas tarefas.

Um dia, o supervisor de Pedro pediu que ele desenvolvesse um programa que pudesse ajudar a ler uma sequência de linhas no keypad com comandos C (cima), B (baixo), E (esquerda) e D (direita). Esses comandos representavam as direções que o utilizador deveria seguir no teclado numérico. 
Pedro deverá iniciar o processo na tecla 5 e mudar de tecla de acordo com o comando lido em cada linha. No entanto, ele deverá ignorar os comandos que fizerem o utilizador sair da parte numérica do keypad (incluindo o zero), ou seja, que o levassem para fora das teclas numeradas.

No final de cada linha de comandos, Pedro deverá imprimir a tecla onde o utilizador está. Depois disso, ele poderá continuar a ler outra linha e continuar o processo a partir dessa tecla até que todas as linhas da sequência sejam lidas.

Teclado numérico:
7 8 9
4 5 6
1 2 3

Em suma:

-Inicialmente começa na casa 5;
-C indica que deve andar para cima;
-B indica que deve andar para baixo;
-D indica que deve andar para a direita;
-E indica que deve andar para a esquerda;
-caso não seja possível mover-se numa dada direção, continua na casa em que está;
-cada nova linha mantém a posição anterior.


*/


int resultadonumerico(char s[], int l){
    int i = 0;
    int r = l; //posição inicial
    //constantes de carateres
    char b = 'B';//baixo
    char c = 'C';//cima
    char d = 'D';//direita
    char e = 'E';//esquerda
    while(s[i] != '\0'){
        if(s[i] == b && (r != 1 && r != 2 && r != 3)){ //caso r não seja 1, 2 ou 3 (ou seja, não está na base do teclado), r diminui 3 unidades
            r = r-3;
        } else if (s[i] == c && (r != 7 && r != 8 && r != 9)){ //caso r não seja 7, 8 ou 9 (ou seja, não está no topo do teclado), r aumenta 3 unidades
            r = r+3;
        } else if (s[i] == d && (r != 3 && r != 6 && r != 9)){ //caso r não seja 3, 6 ou 9 (ou seja, não está na extremidade direita do teclado), r aumenta uma unidade
            r++;
        } else if(s[i] == e && (r != 7 && r != 4 && r != 1)){ //caso r não seja 1, 4 ou 7 (ou seja, não está na extremidade esquerda do teclado), r diminui uma unidade
            r--;
        }
        //caso nehumas das proposições anteriores se demonstrar verdadeira o valor de r não é atualizado
        i++;
    }
    return r; // após passar pelo ciclo, a função retorna o valor final de r
}
/*

O programa deve ler:
    Uma linha com um número N que corresponde ao número de linhas
    N linhas tendo cada uma comandos de direção (no máximo são 20 comandos)

E imprimir:
    uma linha com o código da fechadura

*/

int main() {
    int n; //número de comandos
    assert(scanf("%d",&n) == 1);
    int i = 0;// admite-se que o númro de comandos é um número inteiro positivo, caso contrário o programa encerra retornando 0
    char s[20]; // a string s só pode no máximo ter 20 carateres
    int a[n]; // array a do tamanho do número de comandos
    while(i<n){
        assert(scanf("%s", s));//caso na string s não estejam os carateres 'C','B','D' ou 'E' a função resultadonumerico não irá mudar a posição com que iniciou a função
        if (i == 0){
            a[i] = resultadonumerico(s,5); //função definida acima começa sempre na tecla 5
        }
        else{
            a[i] = resultadonumerico(s,a[i-1]); // através da chamada recursiva da função resultadonumerico é armazenado no array com a tecla onde parou na ultima vez 
        }

        i++;
    }
    for (int j = 0; j < n; j++) {
        printf("%d",a[j]);//imprime-se todos os elementos do array a sem espaços
    }
    printf("\n");
    return 0;
}


/*
Input:
5
CCDB
EBBC
DDBECCD
BDDDDD
EEEEEEE

Output:
65964

Input:
4
DBECED
EEEECBD
EBCEBBEE
CCDDCCBE

Output:
5515

Input:
5
CBC
EBCEECD
BBDECBB
EDCCCCB
DECCBBD

Output:
88253


*/
