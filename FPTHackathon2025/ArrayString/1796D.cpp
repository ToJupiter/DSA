#include <bits/stdc++.h>
using namespace std;
 
namespace {
    #define all(x) (x).begin(), (x).end()
    using str = string; using pii = pair<int, int>;
    using ll = long long; using pll = pair<ll, ll>;
    using ld = long double; using pld = pair<ld, ld>;
 
    using ll = long long;
    using vll = vector<ll>;
    using db = double;
    using pii = pair<int,int>;
    #define pb push_back
    #define fir first
    #define sec second
 
    template<class T> using maxHeap = priority_queue<T, vector<T>>;
    template<class T> using minHeap = priority_queue<T, vector<T>, greater<T>>;
    template<class A, class B> bool chmax(A &a, const B b) { return a<b&&(a=b,1); }
    template<class A, class B> bool chmin(A &a, const B b) { return b<a&&(a=b,1); }

}

#define INF 99999999

void solve();

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int testCases; cin >> testCases;
    while(testCases--) solve();

}


void solve(){
    int n, k, x; // n la kich co mang, k la so ptu bi cong
    cin >> n >> k >> x; vector<long long> a(n); for (int i = 0; i < n; i++) cin >> a[i];

    // dp[i][j][s]:
    // mindset two pointer: left = 1, right: 1 => n => dp[i]: i = right(1 => n)
    // j + x: so operation da thuc hien
    // state s: s = 0: chua chon duoc subarray
    // s = 1: dang o trong subarray
    // s = 2: da ket thuc subarray
    // 1 => i: [1,3], current = 0 => s = 0
    // current = 1 => s = 1
    // current = 5 => s = 2
    vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(k + 1, vector<long long>(3, -1e18)));
    dp[0][0][0] = 0;

    // option: current subarray: -x , +x. j so operation da lam: dp[5][3], k = 3
    // dp[5][3]: doan minh dang xet la doan [1,5], so lan +x: 3/3
    for (int i = 0; i < n; i++) for (int j = 0; j <= k; j++) for (int state = 0; state < 3; state++){
        if (dp[i][j][state] == -1e18) continue;
        // -x:
        long long tru_x = a[i] - x;
        for (int next = state; next < 3; next++) dp[i + 1][j][next] = max(dp[i + 1][j][next], dp[i][j][state] + (next == 1 ? tru_x : 0));
        // state = 1: current = [1,5], vi tri hien tai cua minh: 2 => tat ca cac phan tu trong doan [1,5] - x
        // state != 1: minh dang ko o trong doan nay => khong duoc phep -x, luot qua doan nay lan sau -x(+ 0)

        // +x: tieu ton mana(operation)
        if (j + 1 <= k) {
            long long cong_x = a[i] + x;
            for (int next = state; next < 3; next++) dp[i + 1][j+1][next] = max(dp[i + 1][j+1][next], dp[i][j][state] + (next == 1 ? cong_x : 0));
        }

    }
    cout << max(dp[n][k][1], dp[n][k][2]) << endl;


}
