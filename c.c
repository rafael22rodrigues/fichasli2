#include <stdio.h>
#include <assert.h>


int main() {
    int a, b, c;
    assert(scanf("%d %d %d", &a, &b, &c) == 3);
    int array[3]= {a, b, c};
    int i, j, aux;

    for(i = 0; i < 3; i++){
        j = i;

        while((j != 0) && (array[j] > array[j - 1])) {
            aux = array[j];
            array[j] = array[j - 1];
            array[j - 1] = aux;
            j--;
        }
    }
    int l;
    int arrayInvert[3];
    for(l = 0; l <= 2; l++ )
    {
        arrayInvert[l] = array[3-l-1];
    }
    for (int k = 0; k < 3; k++) {
        printf("%d ", arrayInvert[k]);
    }
    putchar('\n');
    return 0;
}
