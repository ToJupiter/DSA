#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 1;
int n, m; vector<int> arr; vector<vector<int>> hold;

void build(vector<vector<int>>& hold){
    for (int i = 0; i < log2(n); i++){
        int temp = 1 << i;
        for (int j = 0; j + temp <= n; j++){
            if (i == 0) hold[i][j] = arr[j];
            else hold[i][j] = min(hold[i-1][j],
            hold[i-1][j + temp/2]);
        }
    }
}

int query(int fir, int sec){
    int count = sec - fir + 1;
    count = log2(count);
    return min(hold[count][fir], hold[count][sec - (1 << count) + 1]);
}

int main(){
    cin >> n; arr.resize(n); hold.resize(log2(n) + 1, vector<int>(n));
    for(int i = 0; i < n; i++) cin >> arr[i];
    int sum = 0;
    build(hold);
    cin >> m; while(m--){
        int fi, se; cin >> fi >> se; sum += query(fi, se);
    }
    cout << sum << endl;

}