#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        ll n, x, y;
        cin >> n >> x >> y;

        map<pair<ll,ll>, ll> cnt;
        ll ans = 0;
        for(int i = 0; i < n; i++){
            ll a;
            cin >> a;
            ll rx = a % x;
            ll ry = a % y;
            ll needx = (x - rx) % x;
            ans += cnt[{needx, ry}];
            cnt[{rx, ry}]++;
        }
        cout << ans << "\n";
    }
    return 0;
}