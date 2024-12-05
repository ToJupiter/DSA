#include <stdio.h>
int n, a, b, c;

void towerOfHanoi(int n, int start, int end, int aux){
    if (n == 0) return;
    towerOfHanoi(n-1, start, aux, end);
    printf("%d %d\n", start, end);
    towerOfHanoi(n-1, aux, end, start);
}   

int main(){
    scanf("%d", &n, &a, &b, &c);
    printf("%d\n", (1 << n) - 1);
    towerOfHanoi(n, a, b, c);
}