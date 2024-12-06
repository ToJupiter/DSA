#include <bits/stdc++.h>
using namespace std;

/*
    O(M+N):
        - M la so input, tuc la DFS truoc
        - N la iterate qua de tim max sau khi DFS
*/

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M; cin >> N >> M;
    vector<vector<int>> adj(N + 1);
    vector<int> dp(N + 1, -1);
    // preprocess
    for (int i = 0; i < M; i++){
        int t1, t2; cin >> t1 >> t2;
        adj[t1-1].push_back(t2-1);
    }

    // DFS first
    function<int(int)> dfs = [&](int x){
        if (dp[x] != -1) return dp[x];
        dp[x] = 0;

        for (int neighbor : adj[x]){
            dp[x] = max(dp[x], dfs(neighbor) + 1);
        }
        return dp[x];
    };

    for (int i = 0; i < N; i++) dfs(i);

    // Just maxing

    int max_func = 0;
    for (int i = 0; i < N; i++) max_func = max(max_func, dfs(i));
    cout << max_func << endl;    

}