#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n; vector<int> vec(n+1);
    for (int i = 1; i <= n; i++) cin >> vec[i];
    reverse(vec.begin() + 1, vec.end()); int count_ll = 0;
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            if (vec[j] > vec[i]) { count_ll++; count_ll %= MOD;}
        }
        }
    
        cout << count_ll << endl;
    }

