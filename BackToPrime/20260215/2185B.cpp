#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t; while(t--){
        int n; cin >> n; vector<int> a(n+1);

        int first_max = 0;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            first_max = max(first_max, a[i]);
        }

        cout << n * first_max << endl;
    }
}