#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

/*
    Approach in loop:
        - f[i] = arr[i] if i <= l1
        - we start to priority queue push with i >= l1
        - we pop when i - pq.top().second > l2
*/

int main(){
    int n, l1, l2; cin >> n >> l1 >> l2;
    vector<int> arr(n + 1);

    for (int i = 1; i <= n; i++) cin >> arr[i];
    vector<int> func(n + 1);
    priority_queue<pii> pq;
    int res = INT_MIN;



    for (int i = 1; i <= n; i++){
        if(i <= l1) { func[i] = arr[i]; continue;}
        pq.push(make_pair(func[i-l1], i - l1));
        if (i - pq.top().second > l2) pq.pop();
        func[i] = arr[i] + pq.top().first; 
        res = max(res, func[i]);

    }

    cout << res << endl;



    



}