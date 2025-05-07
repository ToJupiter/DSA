#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    const ull B = 1315423911ULL;
    while(t--){
        int n;
        string s;
        cin >> n >> s;

        vector<ull> h(n+1), p(n+1);
        p[0] = 1;
        for(int i = 0; i < n; i++){
            h[i+1] = h[i]*B + (ull)(s[i] + 1);
            p[i+1] = p[i]*B;
        }

        unordered_set<ull> seen;
        seen.reserve(n*2);
        for(int i = 0; i + 1 < n; i++){
            // hash of s[0..i-1]
            ull left = h[i];
            // hash of s[i+2..n-1]
            ull right = h[n] - h[i+2]*p[n-(i+2)];
            // combine: left * B^(n-(i+2)) + right
            ull hv = left * p[n-(i+2)] + right;
            seen.insert(hv);
        }
        cout << seen.size() << "\n";
    }
    return 0;
}