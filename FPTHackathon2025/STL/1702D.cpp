#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int charValue(char c) {
    return c - 'a' + 1;
}

string removeLetters(string& w, int p) {
    int total = 0;
    vector<pair<int, int>> chars; // {value, index}

    for (int i = 0; i < w.size(); ++i) {
        int val = charValue(w[i]);
        total += val;
        chars.push_back({val, i});
    }

    if (total <= p)
        return w;

    // Sort by value descending to remove most expensive characters first
    sort(chars.begin(), chars.end(), greater<>());

    set<int> toDelete;
    for (auto& [val, idx] : chars) {
        if (total <= p)
            break;
        total -= val;
        toDelete.insert(idx);
    }

    string res;
    for (int i = 0; i < w.size(); ++i) {
        if (!toDelete.count(i))
            res += w[i];
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string w;
        int p;
        cin >> w >> p;
        cout << removeLetters(w, p) << endl;
    }

    return 0;
}