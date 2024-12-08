#include <bits/stdc++.h>
using namespace std;

int n, k;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<int> a_set(101); cin >> n >> k; 
    for (int i = 1; i <= n; i++)
        cin >> a_set[i];
    
    vector<bool> dp(100001, false);
    for (int i = 1; i <= k; i++){
        for (int j = 1; j <= n; j++){
            if (i - a_set[j] >= 0 && !dp[i - a_set[j]]) dp[i] = true;
        }
    }

    if (dp[k] == true) cout << "First" << endl;
    else cout << "Second" << endl;





}