#include <bits/stdc++.h>

using namespace std;

/*
    Normal thought: 2^n or 1 << n.
    But we could not do that, because with n = 10^6, that will overflow our int64 dtype.
    We apply (a x b) mod pr = ((a mod pr) x (b mod pr)) mod pr. Then, we build a simple 1D DP approach around it.
*/

int main(){
    long long mod_num = 1000000007;
    vector<long long> modulus(1000001);
    int n; cin >> n;

    modulus[1] = 2;

    for (int i = 2; i <= n; i++) modulus[i] = (modulus[i-1] * 2) % mod_num;
    cout << modulus[n] << endl;
}
