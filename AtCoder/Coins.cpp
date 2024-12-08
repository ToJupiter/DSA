#include <bits/stdc++.h>
using namespace std;

int n; vector<double> arr(3000);
vector<vector<double>> dp(3000, vector<double>(3000, 0));

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n; for (int i = 1; i <= n; i++){ cin >> arr[i];}
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= i; j++){
            if (i == j){ dp[i][j] = dp[i-1][j-1] * arr[i]; continue;}
            dp[i][j] = dp[i-1][j] * (1- arr[i]) + dp[i-1][j-1] * arr[i];
        }
    }
    double summation = 0; for (int j = n/2 + 1; j <= n; j++) summation += dp[n][j];
    cout << setprecision(10) << summation << endl;
}