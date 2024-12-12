#include <bits/stdc++.h>
using namespace std;

#define MAXN 1002
#define MOD 1000000007

int main(){
    int n, k1, k2; cin >> n >> k1 >> k2;
    int rest_dp[MAXN];
    int work_dp[MAXN];
    memset(rest_dp, 0, MAXN * sizeof(int));
    memset(work_dp, 0, MAXN * sizeof(int));
    rest_dp[0] = 1; rest_dp[1] = 1;

    // ta co quy luat, mot ngay nghi se tuong ung voi so cach lam viec o ngay truoc
    for (int i = 1; i <= n; i++){

        for (int k = k1; k <= k2; k++){
                if (i - k >= 0) {
                        work_dp[i] += rest_dp[i-k];
                        work_dp[i] %= MOD;
                        }
        }
        rest_dp[i] += work_dp[i-1];

    }

    cout << work_dp[n] + rest_dp[n] << endl;



}
