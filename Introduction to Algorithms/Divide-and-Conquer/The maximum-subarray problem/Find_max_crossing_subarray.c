# include <stdio.h>

#define MAX 100
#define INFTY 0x7fffffff

int main() {

    int x, len, i, j;
    int left_sum, right_sum, sum, low, mid, high;
    int max_left, max_right;

    int A[MAX];

    freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);

    //read the data
    len = 0;
    while (scanf("%d", &x) == 1){
        A[len++] = x;
    }

    // test the read data
    // for (i = 0; i < len-1; i++)
    //     printf("%d ", A[i]);
    // printf("%d\n", A[len-1]);

    left_sum = -INFTY;
    sum = 0;
    low = 0; mid = 9; high = len-1;

    for (i = mid; i >= low; i--){
        sum += A[i];
        if (sum > left_sum){
            left_sum = sum;
            max_left = i+1; // mark the left edge
        }
    }
    right_sum = -INFTY;
    sum = 0;
    for (i = mid+1; i <= high; i++){
        sum += A[i];
        if (sum > right_sum){
            right_sum = sum;
            max_right = i+1; // mark the right edge
        }
    }

    printf("-------- HERE IS THE OUTPUT --------\n");
    printf("In the code, I select the mid=%d\n", mid);
    printf("The maximum-subarray crossing the point %d, is range[%d, %d]\n", mid, max_left, max_right);
    printf("The maximum-sum is %d\n", left_sum+right_sum);

    return 0;
}
