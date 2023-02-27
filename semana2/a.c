#include <stdio.h>
#include <assert.h>

int main() {
    int n;
    assert(scanf("%d", &n) == 1);
    int i = 0;
    int a;
    int array[n];
    while (i < n){
        assert(scanf("%d", &a) == 1 );
        if(a>78){
            return 0;
        }
        array[i] = a;
        i++;
    }
    int x=0, y=0;
    for (int j = 0; j < n; j++) {
        if((array[j])%4 == 0){
            x++;
        } else if ((array[j])%4 == 1){
            y--;
        } else if((array[j])%4 == 2){
            y++;
        } else if((array[j])%4 == 3){
            x--;
        }
    }
    printf("%d %d\n", x, y);
    return 0;
}

