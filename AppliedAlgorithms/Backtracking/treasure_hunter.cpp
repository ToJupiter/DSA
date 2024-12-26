#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Treasure {
    long long x, y, c;
};

bool can_move(const Treasure& from, const Treasure& to) {
    return from.x <= to.x && from.y <= to.y;
}

int main() {
    int n;
    cin >> n;

    vector<Treasure> treasures(n);
    for (int i = 0; i < n; ++i) {
        cin >> treasures[i].x >> treasures[i].y >> treasures[i].c;
    }

    long long max_gold = 0;
    vector<pair<long long, long long>> dp(n); 

    
    vector<int> p(n);
    for(int i = 0; i < n; i++) p[i] = i;
    sort(p.begin(), p.end(), [&](int i, int j) {
        if (treasures[i].x != treasures[j].x) {
            return treasures[i].x < treasures[j].x;
        } else if (treasures[i].y != treasures[j].y){
            return treasures[i].y < treasures[j].y;
        } else {
            return false;
        }
    });

    vector<Treasure> sorted_treasures(n);
    for(int i = 0; i < n; i++) {
        sorted_treasures[i] = treasures[p[i]];
    }
    treasures = sorted_treasures;

    for (int i = 0; i < n; ++i) {
        dp[i].first = treasures[i].c;
        dp[i].second = i;

        for (int j = 0; j < i; ++j) {
            if (can_move(treasures[j], treasures[i])) {
                if (dp[j].first + treasures[i].c > dp[i].first) {
                    dp[i].first = dp[j].first + treasures[i].c;
                }
            }
        }
        max_gold = max(max_gold, dp[i].first);
    }

    cout << max_gold << endl;

    return 0;
}