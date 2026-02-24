#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t; while(t--){
        int n; cin >> n; vector<int> a(n+1);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        
        int gap = a[0];
        for (int i = 0; i < n; i++) {
            a[i] -= gap;
            if (a[i] != i) {
                cout << i << endl;
                break; 
            }
        }

        
    }
}