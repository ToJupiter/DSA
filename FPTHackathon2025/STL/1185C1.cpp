#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, M;
    cin >> n >> M;
    vector<int> t(n);
    for(auto &x : t) cin >> x;

    for(int i = 0; i < n; i++){
        multiset<int, greater<int>> s;
        int sum = 0, cnt = 0;
        for(int j = 0; j < i; j++){
            s.insert(t[j]);
            sum += t[j];
        }
        while(sum + t[i] > M){
            sum -= *s.begin();
            s.erase(s.begin());
            cnt++;
        }
        cout << cnt << " ";
    }
    return 0;
}