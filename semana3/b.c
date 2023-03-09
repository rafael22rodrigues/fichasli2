#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

int resultadonumerico(char s[], int l){
    int i = 0;
    int r = l;
    char b = 'B';
    char c = 'C';
    char d = 'D';
    char e = 'E';
    while(s[i] != '\0'){
        if(s[i] == b && (r != 1 && r != 2 && r != 3)){
            r = r-3;
        } else if (s[i] == c && (r != 7 && r != 8 && r != 9)){
            r = r+3;
        } else if (s[i] == d && (r != 3 && r != 6 && r != 9)){
            r++;
        } else if(s[i] == e && (r != 7 && r != 4 && r != 1)){
            r--;
        }
        i++;
    }
    return r;
}

int main() {
    int n;
    assert(scanf("%d",&n) == 1);
    int i = 0;
    char s[20];
    int a[n];
    while(i<n){
        assert(scanf("%s", s));
        if (i == 0){
            a[i] = resultadonumerico(s,5);
        }
        else{
            a[i] = resultadonumerico(s,a[i-1]);
        }

        i++;
    }
    for (int j = 0; j < n; j++) {
        printf("%d",a[j]);
    }
    printf("\n");
    return 0;
}
