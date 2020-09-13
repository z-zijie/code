#include <stdio.h>

#define MAX 100

int main() {

    int x, len, i, j;
    int A[MAX];

    freopen("file.in", "r", stdin);
//    freopen("file.out", "w", stdout);

    len = 0;
    while (scanf("%d", &x) == 1){
        A[len++] = x;
    }

    //InsertSort_A [Ascending]
    for (j = 1; j < len; j++){
        x = A[j];
        i = j - 1;
        while (i >= 0 && A[i] > x){
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = x;
    }

    for (i = 0; i < len-1; i++)
        printf("%d ", A[i]);
    printf("%d\n", A[len-1]);

    return 0;
}
