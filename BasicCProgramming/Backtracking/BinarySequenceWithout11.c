#include <stdio.h>
#include <stdlib.h>

int n;

void print_binary(int n, char binary[]){
    for (int i = 0; i < n; i++){
        printf("%c", binary[i]);
    }
    printf("\n");
}

void generator(int step, int n, char binary[]){
    if (step==n){
        print_binary(n, binary);
        return;
    }

    // Theo cach lam backtracking binh thuong, chung ta SE UNDO CHANGES DONE.
    // tuy nhien voi bai binary seq, viec undo 0 dong nghia voi replace '0' bang '1'.
    // do vay, binary[step] = '1'.
    binary[step] = '0';
    generator(step + 1, n, binary);

    if (step == 0 || binary[step-1] == '0'){
        binary[step] = '1';
        generator(step + 1, n, binary);
    }
    
}

int main(){
    scanf("%d", &n); char binary[100];
    generator(0, n,binary);


}