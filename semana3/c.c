#include <stdio.h>
#include <assert.h>
/*
    
Os anões decidiram invadar o País das Maravilhas. 
Para passarem despercebidos, vão levar a sua horda em fila indiana.

Esta estratégia funciona porque o vigilante só consegue ver as pessoas que forem maiores do que todas as pessoas que se encontrem primeiro na fila. 
É claro que se pretende enganar os vigilantes ou é possível que eles compreendam a tramoia! 
Por exemplo, se colocares os anões por ordem decrescente de alturas, o vigia só verá um anão!


*/
int visiveis (int *v, int N){ // determina quantos anões são visíveis, caso o primeiro anão seja o mais alto o vigia só verá um anão
    int r = 0;
    int i = 0;
    int max = 0; // admite-se que não existem alturas negativas, caso contrário a função devolve um valor errado
    for(; i < N; i++){
        if(v[i] > max){
            max = v[i]; 
            r++;
        }
    }
    return r;
}

/*

O programa deve ler:

-Uma linha com o número de casos N
-N linhas tendo cada uma:
-Um inteiro positivo K seguido de
-K inteiros positivos representando cada um a altura de um anão

E deve imprimir:
    N linhas, uma para cada caso, com o número de anões visíveis nesse caso

*/

int main() {
    int n; // número de comandos(linhas)
    assert(scanf("%d",&n)==1); 
    int i = 0; //admite-se que o número de comandos é um número inteiro positivo
    int array[10000] ;
    while (i <n){
        int k;
        assert(scanf("%d",&k)==1); //número de comandos que corresponde à fila com a altura dos anões
        int j = 0; // também se admite que o número inteiro k acabado de ser definido é um número inteiro positivo
        while (j < k){
            int q;
            assert(scanf("%d",&q) == 1);
            array[j] = q; //armazena no array a altura de todos os anões numa fila, quando o ciclo reinicia o array inteiro é atualizado
            j++;
        }
        printf("%d\n",visiveis(array,k)); //imprime-se o número de anões visíveis numa fila
        i++;
    }
    return 0;
}
