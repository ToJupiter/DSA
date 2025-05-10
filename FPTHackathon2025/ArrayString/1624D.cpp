#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(0), std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::string s;
        std::cin >> n >> k >> s;

        int cnt[200] = {};
        for (auto c : s) cnt[c]++;

        int even = 0, odd = 0;
        for (int i = 0; i < 200; ++i) {
            even += cnt[i] / 2;
            odd += cnt[i] % 2;
        }

        int pairs = even / k * 2;
        int rem = even % k * 2 + odd;
        std::cout << (pairs ? pairs + (rem >= k) : 1) << '\n';
    }
}