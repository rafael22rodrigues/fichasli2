#include <stdio.h>
#include <assert.h>

int isEqual (int s[]){
    if ((s[0] == s[1]) && (s[1] == s[2])){
        return 1;
    } else{return 0;}
}
int isCrescent (int s[]){
    if ((s[0] <= s [1]) && (s[1] <= s[2])){
        return 1;
    } else{return 0;}
}

int isDecrescent(int s[]){
    if ((s[0] >= s[1])&&(s[1] >= s[2])){
        return 1;
    }
    else{return 0;}
}

int main() {
    int a, b, c;
    assert(scanf("%d %d %d", &a, &b, &c) == 3);
    int array[4] = {a, b, c};
    int cr = isCrescent(array);
    int i = isEqual(array);
    int d = isDecrescent(array);
    if(cr == 1 || i == 1 || d == 1){
        printf("%s\n", "OK");
    } else { printf("%s\n", "NAO");}
    return 0;
}
