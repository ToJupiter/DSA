#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t; while(t--){
        int n; cin >> n; vector<int> a(n+1);

        int first_max = 0;
        int max_max = -1;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            first_max += 
        }

        for (int k = 1; k <= n; k++){
            for (int j = 1; j <= n; j++){
                int current_max = first_max - k*a[k] - j*a[j] + j*a[k] + k*a[j];
                max_max = max(current_max, first_max);
            }
        }

        cout << max_max << endl;

    }
}