#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#define MAXSIZE 1000

void ler_linha(char *linha, int tamanho) {
    if(fgets(linha, tamanho, stdin) == NULL) {
        fprintf(stderr, "Não consegui ler uma linha!\n");
        abort();
    }

    // O fgets deixa um \n no fim da linha
    // Se a linha não terminar por um \n é porque não conseguimos
    // ler a linha inteira!
    if(linha[strlen(linha) - 1] != '\n') {
        fprintf(stderr, "Não consegui ler uma linha completa!\n");
        abort();
    }

}

int isAlternating(char str[]) {
    int i, isVowel, isConsonant;

    // Começa com uma vogal
    if (tolower(str[0]) == 'a' || tolower(str[0]) == 'e' || tolower(str[0]) == 'i' || tolower(str[0]) == 'o' || tolower(str[0]) == 'u' || tolower(str[0]) == 'y') {
        isVowel = 1;
        isConsonant = 0;
    }
        // Começa com uma consoante
    else {
        isVowel = 0;
        isConsonant = 1;
    }

    // Verifica se a string é alternada entre consoantes e vogais
    for (i = 1; str[i] != '\0'; i++) {
        // Se o caractere atual é uma vogal
        if (tolower(str[i]) == 'a' || tolower(str[i]) == 'e' || tolower(str[i]) == 'i' || tolower(str[i]) == 'o' || tolower(str[i]) == 'u' || tolower(str[i]) == 'y') {
            // Se o caractere anterior foi uma vogal, a string não é alternada
            if (isVowel) {
                return 0;
            }
                // O caractere atual é uma vogal, mas o anterior foi uma consoante
            else {
                isVowel = 1;
                isConsonant = 0;
            }
        }
            // Se o caractere atual é uma consoante
        else {
            // Se o caractere anterior foi uma consoante, a string não é alternada
            if (isConsonant) {
                return 0;
            }
                // O caractere atual é uma consoante, mas o anterior foi uma vogal
            else {
                isVowel = 0;
                isConsonant = 1;
            }
        }
    }

    return 1; // A string é alternada entre consoantes e vogais
}
/**
 *
 * Este programa lê uma linha e
 * imprime cada uma das suas palavras
 */
int main() {
    int n;
    assert(scanf("%d\n",&n)==1);
    int i = 0;
    int ar[n];
    while(i<n){
        char linha[MAXSIZE];
        char palavra[MAXSIZE];
        ler_linha(linha,MAXSIZE);
        int r = 0;
        while(sscanf(linha, "%s%[^\n]", palavra, linha) == 2) {
            if (isAlternating(palavra) == 1) r++;
        }
        ar[i] = r + isAlternating(palavra);
        i++;
    }
    for (int j = 0; j < n; j++) {
        printf("%d\n",ar[j]);
    }
    return 0;
}
