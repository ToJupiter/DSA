#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, l1, l2; cin >> n >> l1 >> l2;
    vector<int> arr(n+1), func(n+1);
    deque<pii> deq; int res = INT_MIN;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    for (int i = 1; i <= n; i++){
        func[i] = arr[i];

        // push if the new back would be max
        // only do these things if i > l1 otherwise segmentation fault!
        if (i > l1){
            if (!deq.empty() && deq.back().first < func[i-l1] || deq.empty())
                deq.push_back(make_pair(func[i-l1], i - l1));
            
        // pop if the current back is out of range
        if (i - deq.back().second > l2) deq.pop_back();

        // update
        func[i] += deq.back().first;
        }
        res = max(func[i], res);

        
    }
    cout << res << endl;

}