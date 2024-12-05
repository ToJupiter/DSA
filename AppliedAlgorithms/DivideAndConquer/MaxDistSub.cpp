#include <bits/stdc++.h>
using namespace std;
#define MAXN 1005

int tests, number; int count_diff;
vector<int> arr(MAXN);

int main(){
    cin >> tests; while(tests--){
        cin >> number >> count_diff;
        arr.resize(number + 1);
        for (int i = 1; i <= number; i++) cin >> arr[i];
        sort(arr.begin() + 1, arr.end());

        function<bool(int)> validate = [&](int dist){
            int cnt = 1, curr = 1, next = 2;
                while(curr < number){
                while(next <= number && arr[next] - arr[curr] < dist) next++;
                if (next <= number) cnt++;
                if (cnt >= count_diff) return true;
                curr = next;
                next++;
                }
                return false;
        };


        int left = 0, right = arr[number] - arr[1];
        while(left <= right){
            int mid = left + (right - left)/2;
            if (validate(mid)) left = mid + 1;
            else right = mid - 1;
        }
        cout << right << endl;


    }
    return 0;
}