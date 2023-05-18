#include <stdio.h>
#include <assert.h>
/*
    
Os anões decidiram invadar o País das Maravilhas. 
Para passarem despercebidos, vão levar a sua horda em fila indiana.

Esta estratégia funciona porque o vigilante só consegue ver as pessoas que forem maiores do que todas as pessoas que se encontrem primeiro na fila. 
É claro que se pretende enganar os vigilantes ou é possível que eles compreendam a tramoia! 
Por exemplo, se colocares os anões por ordem decrescente de alturas, o vigia só verá um anão!


REQUISITOS: Dados o o número de casos N, que com N casos que possuiem um o número de anões do respetivo, seguido de todas as alturas dos anoes, 
o programa deve retornar N linhas, uma para cada caso, com o número de anões visíveis nesse caso
*/

int main() {
    int n; // número de comandos(linhas)
    assert(scanf("%d",&n)==1); 
    int i = 0; //admite-se que o número de comandos é um número inteiro positivo
    while (i <n){
        int anoes;
        assert(scanf("%d",&anoes)==1); //número de anoes presentes em cada fila
        int j = 0; // também se admite que o número de anoes acabado de ser definido é um número inteiro maior que zero
        int anoes_visiveis = 0, maximo = 0; //Como não existe uma altura menor que zero e nem é possível com que não haja pelo menos um anão visível, logo o resultado de cada fila e o máximo começa sempre por zero
        while (j < anoes){
            int altura_anao;
            assert(scanf("%d",&altura_anao) == 1);//altura de um anoes da fila
            if (maximo<altura_anao) {maximo = altura_anao; anoes_visiveis++;} //se a altura do anão atual for superior à altura do anão anterior, significa que pelo menos há mais um anão visivel e por isso aumenta-se uma unidade ao número de anões visíveis
            j++;
        }
        printf("%d\n",anoes_visiveis); //imprime-se o número de anões visíveis numa fila
        i++;
    }
    return 0;
}

/*
Testes

Input 1:
7
8 56 63 57 105 73 119 92 39
8 33 36 59 82 91 101 135 145
12 46 151 138 90 80 59 31 44 84 120 36 133
5 77 85 88 108 156
6 134 88 34 50 38 84
9 43 55 51 81 108 110 141 158 153
16 123 59 85 107 34 89 82 63 71 66 126 59 151 52 58 95

Output 1:
4
8
2
5
1
7
3

Input 2:
6
8 139 142 69 78 157 121 95 118
20 30 32 41 46 51 52 55 68 73 96 97 102 106 121 123 134 139 153 157 160
17 104 117 129 153 53 83 37 138 54 34 60 75 30 90 65 145 64
7 90 39 111 56 117 86 96
20 51 58 58 63 74 76 88 91 92 94 98 100 107 112 124 124 134 139 153 160
13 35 64 71 72 86 90 104 117 126 128 130 134 159

Output 2:
3
20
4
3
18
13

Input 3:
7
8 37 48 85 91 102 119 130 151
13 41 44 45 53 61 64 68 107 116 120 126 158 157
19 38 38 51 58 63 68 72 87 95 102 104 119 120 120 131 136 140 155 154
11 137 101 78 135 83 99 81 78 45 53 80
7 58 68 101 114 118 119 128
10 37 76 80 88 80 92 95 99 102 115
10 92 129 51 65 67 140 67 32 158 114

Output 3:
8
12
16
1
7
9
4

Input 4:
4
10 38 48 68 68 78 81 82 103 120 121
7 108 96 109 36 158 43 87
10 143 111 122 149 87 50 159 126 80 108
6 97 143 149 67 54 36

Output 4:
9
3
3
3
*/