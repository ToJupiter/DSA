#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){

    // freopen("input_d.txt", "r", stdin);
    int t; cin >> t; while(t--){
        ll n, m, h; cin >> n >> m >> h;
        vector<ll> arr(n+1); for (int i = 1; i <= n; i++) cin >> arr[i];
        vector<ll> surplus(n+1); 
        surplus = arr;
        while(m--){
            int b, c; cin >> b >> c;
            arr[b] = (arr[b] + c > h) ? surplus[b] : (arr[b] + c); 
        }
        
        for (int i = 1; i <= n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;


    }
}