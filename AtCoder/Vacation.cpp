#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(3));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> dp(n + 1, vector<int>(3, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (j != k) {
                    // chung ta co a[i-1][j] vi su dung i la 1-indexing
                    // vay a[i-1][j] la happiness doing j in the current date
                    dp[i][j] = max(dp[i][j], dp[i - 1][k] + a[i - 1][j]);
                }
            }
        }
    }

   

    cout << max({dp[n][0], dp[n][1], dp[n][2]}) << endl;

    return 0;
}