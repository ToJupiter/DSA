#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n; 
    cin >> n;
    while (true) {
        cout << n << ' ';
        if (n == 1) break;
        n = (n % 2 == 0) ? n/2 : 3*n + 1;
    }
    cout << '\n';
}