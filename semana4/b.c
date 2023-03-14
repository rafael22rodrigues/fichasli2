#include <stdio.h>
#include <assert.h>
#include <string.h>
#define MAX 1000

char charwrepet(char *s){
    int i, j;
    for (i = 0; s[i] != '\0' ; i++) {
        for (j = 0; s[j] != '\0' ; j++) {
            if(i != j && s[i] == s[j]) return s[i];
        }
    }
    return '*';
}



int main() {
    int n;
    assert(scanf("%d", &n) == 1);
    int i = 0;
    char r[n];
    while(i < n){
        char s[MAX];
        assert(scanf("%s",s));
        r[i] = charwrepet(s);
        i++;
    }
    for (int j = 0; j < n; j++) {
        printf("%c", r[j]);
    }
    printf("\n");
    return 0;
}