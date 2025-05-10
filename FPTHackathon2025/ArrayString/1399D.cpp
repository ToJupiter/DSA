#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }

    int max_teams = 0;
    for (int s = 2; s <= 2 * n; ++s) {
        vector<bool> used(n, false);
        int teams = 0;
        for (int i = 0; i < n; ++i) {
            if (used[i]) continue;
            for (int j = i + 1; j < n; ++j) {
                if (!used[j] && w[i] + w[j] == s) {
                    teams++;
                    used[i] = used[j] = true;
                    break;
                }
            }
        }
        max_teams = max(max_teams, teams);
    }
    cout << max_teams << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}