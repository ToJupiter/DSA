#include <bits/stdc++.h>
using namespace std;

int main(){
    int num_candidates; cin >> num_candidates; int target; cin >> target;
    vector<int> candidates(101);
    for (int i = 1; i <= num_candidates; i++) cin >> candidates[i];

    vector<int> temp_can;
    vector<vector<int>> end_results(101);
    int sum_ll = 0, count_ll = 0;
    bool visited[101];
    memset(visited, false, 101 * sizeof(bool));
    function<void()> backtrack = [&]{
        if (sum_ll == target){
            for (int cnt = 1; cnt < temp_can.size(); cnt++){
                if (temp_can[cnt] < temp_can[cnt-1]) return;
            }

            for (int can : temp_can) end_results[count_ll].push_back(can);
            count_ll++;
            return;
            
        }

        for (int i = 1; i <= num_candidates; i++){
            if (target - sum_ll >= candidates[i]){
                if (visited[i] == false){
                    visited[i] = true;
                    temp_can.push_back(candidates[i]);
                    sum_ll += candidates[i];
                    backtrack();
                    sum_ll -= candidates[i];
                    temp_can.pop_back();
                    visited[i] = false;
                }
            }
        }



    };

    backtrack();
    for (int i = 0; i <= count_ll; i++){
        for (int ptu : end_results[i]) cout << ptu << " ";
        cout << endl;
    }

}