#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main(){
    vector<pii> segs(100001); int n; cin >> n;
    segs.resize(n+1); vector<pii> results; int last;
    for (int i = 1; i <= n; i++) cin >> segs[i].first >> segs[i].second;

    function<bool(pii, pii)> comp = [&](pii a, pii b) -> bool{
        return a.second < b.second;
    };


    sort(segs.begin() + 1, segs.begin() + n + 1, comp);
    last = segs[1].second;

    for (int i = 2; i <= n; i++){
       if (segs[i].first > last){
            results.push_back(segs[i]);
            last = segs[i].second;
       }
    }

    cout << results.size() + 1 << endl;
    


}