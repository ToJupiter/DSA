#include <bits/stdc++.h>
using namespace std;

int main(){
    int h, w; cin >> h >> w;
    vector<vector<int>> array(h, vector<int>(w, 0));
    vector<vector<int>> dp(h + 1, vector<int>(w + 1, 0));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++){
            char temp; cin >> temp; if (temp == '#') array[i][j] = 1;

        }

    dp[0][0] = 1;
    for (int i = 1; i <= h; i++)
        for (int j = 0; j < w; j++){
            if (!array[i-1][j]) dp[i][j] += dp[i-1][j];
            if (!array[i][j-1]) dp[i][j] += dp[i][j-1];

        }
    cout << dp[h][w-1] << endl;


}