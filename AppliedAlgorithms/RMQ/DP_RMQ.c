#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int MAXN = 1e6 + 1;
int n, m; 
// malloc mang arr
// malloc mang hold

int intLog2(int x) {
    int result = 0;
    while (x >>= 1) {
        result++;
    }
    return result;
}

int **allocate2Darray(int rows, int cols){
    rows = intLog2(rows) + 1;
    int **array = (int **) malloc(rows * sizeof(int*));
    for(int i = 0; i < rows; i++){
        array[i] = (int*) malloc(cols * sizeof(int));
    }
    return array;
}

void free2DArray(int** array, int rows) {
    rows = intLog2(rows) + 1;
    for (int i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);
}



int min(int a, int b) {
    return (a < b) ? a : b;
}


void build(int **hold, int *arr){
    for (int i = 0; (1 << i) < n; i++){
        int temp = 1 << i; for (int j = 0; j + temp <= n; j++){
            if (i == 0) hold[i][j] = arr[j];
            else hold[i][j] = min(hold[i-1][j], hold[i-1][j + temp/2]);
        }
    }
}

int query(int fir, int sec, int **hold){
    int count = sec - fir + 1;
    count = intLog2(count);

    return min(hold[count][fir], hold[count][sec + 1 - (1 << count)]);
}


int main(){
    scanf("%d", &n);
    int **hold = allocate2Darray(n, n);
    int *arr = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    int sum = 0; build(hold, arr); scanf("%d", &m);
    while(m--){
        int fi, se; scanf("%d %d", &fi, &se); sum += query(fi,se, hold);
    }
    printf("%d", sum);

    free2DArray(hold, n);
    free(arr);

    
}