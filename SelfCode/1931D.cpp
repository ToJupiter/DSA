#include <bits/stdc++.h>
using namespace std;


// ai + aj % x = 0
// ai - aj % y = 0 => ai % y = aj % y

int main(){
    int t; cin >> t; while(t--){
    long long n, x, y; cin >> n >> x >> y;
    map<pair<long long, long long>, long long> cnt;
    long long ans = 0; for (int i = 0; i < n; i++){
        long long a; cin >>  a; int rx = a % x, ry = a % y;
        // needx = x - rx, day la phep chia tuong trung
        long long needx = (x - rx) % x; 
        // truy cap vao gia tri da co. Chung ta can bu vao khoang needx, so thu 2. 
        // Neu nhu cnt = 0 thi khong co pair tuong ung. Neu nhu cnt >= 1 thi co pair tuong ung.
        ans+= cnt[{needx, ry}];
        // append 1 pair moi vao.
        cnt[{rx, ry}]++;
    }
    cout << ans << endl;
    }
    return 0;
}