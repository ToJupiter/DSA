#include <bits/stdc++.h>
using namespace std;

int main(){
    int number, time, distance; cin >> number >> time >> distance;
    vector<int> amount(number + 1);
    vector<int> indiv_time(number + 1);
    for (int i = 1; i <= number; i++) cin >> amount[i];
    for (int i = 1; i <= number; i++) cin >> indiv_time[i];


    vector<vector<int>> dp(number + 1, vector<int>(number + 1, -1));
    int res = INT_MIN;
    for (int ware = 0; ware <= number; ware++){
        for (int t = 0; t <= time; t++){
            if (indiv_time[ware] > t) dp[ware][t] = 0;
            else{
                for (int j = 1; j <= distance; j++){
                    if (ware >= j) dp[ware][t] = max(dp[ware][t], dp[ware - j][t - indiv_time[ware]] + amount[ware]);
                }
                res = max(res, dp[ware][t]);
            }
        }
    }

    cout << res + 1 << endl;


}
