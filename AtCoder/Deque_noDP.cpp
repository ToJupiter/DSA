#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n; deque<int> deq;
    for (int i = 0; i < n; i++){
        int temp; cin >> temp; deq.push_front(temp);
    }

    int counter = 0;
    int dp[2] = {0};

    while(counter < n){
        if (counter == n - 1){
            dp[counter % 2] = deq.front();
            counter++;
        }
        
        int fr = deq.front(); int ba = deq.back();
        deq.pop_front(); deq.pop_back();
        int ba_diff = deq.back() - ba; int fr_diff = deq.front() - fr;

        if (ba_diff < fr_diff){
            dp[counter % 2] = ba;
            deq.push_front(fr);
        }
        else if (ba_diff == fr_diff){
            dp[counter % 2] = ba;
            deq.push_front(fr);
        }        
        else {
            dp[counter % 2] = fr;
            deq.push_back(ba);
        }
        counter++;
    }

    cout << dp[0] - dp[1] << endl;
}