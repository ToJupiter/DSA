#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k; cin >> n >> k; vector<int> height(n);
    for (int i = 0; i < n; i++) cin >> height[i];
    int max_water = 0;


    function<int()> calculate_water = [&]{
        int water = 0;
        // big for
        for (int i = 1; i < n - 1; i++){
            int left_max = 0; int right_max = 0; int water_level = 0;
            for (int j = 0; j < i; j++) left_max = max(left_max, height[j]);
            for (int j = i + 1; j < n; j++) right_max = max(right_max, height[j]);
            water_level = min(left_max, right_max);
            if (water_level > height[i]) water += water_level - height[i];

        }
        return water;
    };

    function<void(int)> backtrack = [&](int idx){
        if (idx == n){
                //
            max_water = max(max_water, calculate_water());
            return;
        }

        // Option 1: No adding
        backtrack(idx + 1);

        // Option 2: Add heights
        for (int ad = 1; ad <= k; ad++){
            height[idx] += ad;
            k -= ad;
            backtrack(idx + 1);
            k += ad;
            height[idx] -= ad;
        }


    };
    backtrack(0);
    cout << max_water << endl;

}
