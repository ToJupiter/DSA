#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n; cin >> n; long long sum = 0;
    for (int i = 1; i <= n - 1; i++){
        int temp; cin >> temp; sum += temp;
    }
    long long n_sum = n * (n+1) / 2;
    cout << n_sum - sum << endl;
}