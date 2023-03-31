#include <stdio.h>
#include <assert.h>
#include <string.h>

typedef struct {
	char nome[100];
}Nome;

void retirar_espacos(char *s){
	int i, j = 0;
    int n = strlen(s);

    // Percorre a string original
    for (i = 0; i < n; i++) {
        if (s[i] != ' ') {
            // Move o caractere não espaço para a posição correta
            s[j] = s[i];
            j++;
        }
    }

    // Adiciona o caractere nulo para indicar o fim da string
    s[j] = '\0';
}

void ordenar(char *s){
	int i, j;
    char temp;

    int n = strlen(s);
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (s[i] > s[j]) {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

int main()
{
	int n;
	assert(scanf("%d\n",&n)==1);
	int i = 0;
	char nomeV[100];
	while(i<n){
		int k;
		assert(scanf("%d\n",&k)==1);
		if(fgets(nomeV,100,stdin)== NULL) return 0;
		nomeV[strcspn(nomeV,"\n")]='\0';
		retirar_espacos(nomeV);
		ordenar(nomeV);
		Nome nomes[k];
		int j = 0;
		char nomeC[100];
		while(j<k){
			if(fgets(nomeC,100,stdin)==NULL) return 0;
			nomeC[strcspn(nomeC,"\n")]='\0';
			retirar_espacos(nomeC);
			ordenar(nomeC);
			strcpy(nomes[j].nome,nomeC);
			j++;
		}
		int l, p = 0;
		for (l = 0; l < j; l++)
		{
			if (strcmp(nomes[l].nome,nomeV)==0)
			{
				if (p == 0)
				{
					printf("%d",l+1);
					p++;	
				}
				else{
					printf(" %d",l+1);
					p++;
				}
			}
		}
		if (p==0)
		{
			printf("%d\n",-1);
		}
		else{
			printf("\n");
		}
		i++;
	}
	return 0;
}