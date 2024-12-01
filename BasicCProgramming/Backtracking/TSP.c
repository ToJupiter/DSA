#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int min_cost = INT_MAX;
int n, c[21][21], path[21]; bool visited[21];


void tsp(int checkpoint, int current_cost){

    if (checkpoint == n){
        int final_cost = current_cost + c[path[n-1] - 1][0];
        if (final_cost < min_cost) min_cost = final_cost;
        return;
    }

    for (int i = 1; i < n; i++){
        if (!visited[i]){
            int next_cost = current_cost + c[path[checkpoint-1] - 1][i];
            visited[i] = true;
            path[checkpoint] = i + 1;
            tsp(checkpoint + 1, next_cost);
            visited[i] = false;
        }
    }
}

int main(){
    scanf("%d", &n); for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) scanf("%d", &c[i][j]);
    path[0] = 1; visited[0] = true; tsp(1,0);
    printf("%d", min_cost);
}