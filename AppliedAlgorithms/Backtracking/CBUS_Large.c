#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>

const int MAXN = 1e3 + 5;
int n, k; 

typedef struct Request{
    int pickup;
    int dropoff;
} Request;

int main(){
    int c[MAXN][MAXN];
    scanf("%d %d", &n, &k); int size = 2 * n + 1;
    for (int i = 0; i < size; ++i) for (int j = 0; j < size; ++j) scanf("%d", &c[i][j]);

    Request requests[n]; for (int i = 0; i < n; i++){
        requests[i].pickup = i + 1;
        requests[i].dropoff = n + i + 1;
    }

    bool picked[n], delivered[n]; int *route = malloc(2 * n * sizeof(int));
    int current = 0, capacity = 0, route_size = 0;

    while(route_size < 2 * n){
        int next = -1;
        int minDist = INT_MAX;

        for (int i = 0; i < n; ++i){
            if (!picked[i] && capacity < k){
                int dist = c[current][requests[i].pickup];
                if (dist < minDist){
                    minDist = dist;
                    next = requests[i].pickup;
                }
            }
        }

        for (int i = 0; i < n; i++){
            if (picked[i] && !delivered[i]){
                int dist = c[current][requests[i].dropoff];
                if (dist < minDist){
                    minDist = dist;
                    next = requests[i].dropoff;
                }
            }
        }

        if (next == -1) break;
        route[route_size] = next; route_size++;
        for (int i = 0; i < n; ++i){
            if (next == requests[i].pickup){
                picked[i] = true;
                capacity++;
            }
            if (next == requests[i].dropoff){
                delivered[i] = true;
                capacity--;
            }
        }

        current = next;
        
    }

    printf("%d \n", n); for (int i = 0; i < (2 * n); i++){
        if (route[i] != 0) printf("%d ", route[i]);
        else continue;
    }
    printf("\n");
    return 0;


}