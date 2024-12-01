#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int n, m, c[16][16], path[16], count = 0; bool visited[16];

void tsp(int checkpoint, int current_cost){

    if (checkpoint == n){
        int final_cost = current_cost + c[path[n-1] - 1][0];
        if (final_cost <= m){ 
        count++;
        }
        return;
    }

    for (int i = 1; i < n; i++)
    {
        if (!visited[i]){
            int next_cost = current_cost + (checkpoint > 0 ? c[path[checkpoint - 1] - 1][i] : 0);

            if (next_cost <= m){
                path[checkpoint] = i + 1;
                visited[i] = true;
                tsp(checkpoint + 1, next_cost);
                visited[i] = false;
            }
        }
    }

}

int main(){
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) scanf("%d", &c[i][j]);
    path[0] = 1; visited[0] = true; tsp(1, 0); printf("%d", count);
}