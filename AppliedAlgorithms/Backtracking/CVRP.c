
#include <stdio.h>
#include <string.h>

#define MAX_N 50
#define INF 1e9

int num_c, num_r, max_l;  // Number of clients, Number of routes, Max load
int dem[MAX_N];          // Demand of each client
int dist[MAX_N][MAX_N];   // Distance matrix

int nxt[MAX_N];        // Next point on a route
int strt[MAX_N];       // Starting point of each route
int best_nxt[MAX_N];  // Best solution next points
int best_strt[MAX_N]; // Best solution starting points

int vis[MAX_N];   // Visited status of clients
int rt_dst[MAX_N]; // Distance of each route
int ld[MAX_N];    // Load of each route
int tot_dst;     // Total distance of current solution
int best_dst;     // Best total distance found
int seg_cnt;      // Number of segments
int rt_cnt;       // Number of routes in the current solution
int min_d;       // Minimum distance between any two different points

void read_data() {
    scanf("%d%d%d", &num_c, &num_r, &max_l);
    for (int i = 1; i <= num_c; i++) {
        scanf("%d", &dem[i]);
    }
    dem[0] = 0;
    min_d = INF;
    for (int i = 0; i <= num_c; i++) {
        for (int j = 0; j <= num_c; j++) {
            scanf("%d", &dist[i][j]);
            if (i != j && min_d > dist[i][j]) min_d = dist[i][j];
        }
    }
}

void update_best_sol() {
    if (tot_dst < best_dst) {
        best_dst = tot_dst;
    }
}

int is_valid_nxt(int v, int k) {
    if (v > 0 && vis[v]) return 0;
    if (ld[k] + dem[v] > max_l) return 0;
    return 1;
}

void try_nxt(int s, int k) {
    if (s == 0) {
        if (k < num_r) try_nxt(strt[k + 1], k + 1);
        return;
    }
    for (int v = 0; v <= num_c; v++) {
        if (is_valid_nxt(v, k)) {
            nxt[s] = v;
            vis[v] = 1;
            tot_dst += dist[s][v];
            ld[k] += dem[v];
            seg_cnt++;
            if (v > 0) {
                if (tot_dst + (num_c + rt_cnt - seg_cnt) * min_d < best_dst)
                    try_nxt(v, k);
            } else {
                if (k == num_r) {
                    if (seg_cnt == num_c + rt_cnt) update_best_sol();
                } else {
                    if (tot_dst + (num_c + rt_cnt - seg_cnt) * min_d < best_dst)
                        try_nxt(strt[k + 1], k + 1);
                }
            }
            seg_cnt--;
            ld[k] -= dem[v];
            tot_dst -= dist[s][v];
            vis[v] = 0;
        }
    }
}

int is_valid_strt(int v, int k) {
    if (v == 0) return 1;
    if (ld[k] + dem[v] > max_l) return 0;
    return !vis[v];
}

void try_strt(int k) {
    for (int v = (strt[k - 1] == 0 ? 0 : strt[k - 1] + 1); v <= num_c; v++) {
        if (is_valid_strt(v, k)) {
            strt[k] = v;
            if (v > 0) seg_cnt++;
            vis[v] = 1;
            tot_dst += dist[0][v];
            ld[k] += dem[v];
            if (k < num_r) {
                try_strt(k + 1);
            } else {
                rt_cnt = seg_cnt;
                try_nxt(strt[1], 1);
            }
            ld[k] -= dem[v];
            tot_dst -= dist[0][v];
            vis[v] = 0;
            if (v > 0) seg_cnt--;
        }
    }
}

void solve() {
    tot_dst = 0;
    best_dst = INF;
    for (int v = 1; v <= num_c; v++) vis[v] = 0;
    strt[0] = 0;
    try_strt(1);
    if (best_dst == INF) best_dst = -1;
    printf("%d\n", best_dst);
}

int main() {
    read_data();
    solve();
    return 0;
}
