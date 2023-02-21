#include <stdio.h>
#include <assert.h>

int maxfive(int a[]){
    int max = 0;
    int i = 0;
    while (i<=4){
        if((max < a[i])){
            max = a[i];
        }
        i++;
    }
    return max;
}

int maxline(int a[]){
    int m = maxfive(a);
    int r = 1;
    int i = 0;
    while (i<=4){
        if(m == a[i]){
            break;
        } else{r++; i++;}

    }
    return r;
}


int main() {
    int a, b, c, d, e;
    assert(scanf("%d %d %d %d %d", &a, &b, &c, &d, &e) == 5);
    int array[5]={a, b, c, d, e};
    int r = maxline(array);
    printf("%d\n", r);
    return 0;
}
