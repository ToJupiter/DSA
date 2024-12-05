#include <bits/stdc++.h>
using namespace std;

const int MAX_TEACHERS = 50;
const int MAX_COURSES = 50;

int teachers, courses;
int main(){
    cin >> teachers >> courses;
    vector<vector<int>> choices(courses + 1);
    for (int t = 1; t <= teachers; t++){
        int k; cin >> k; for (int c = 1; c <= k; c++){
            int temp; cin >> temp; choices[temp].push_back(t);
        }
    }
    vector<vector<bool>> conflict(MAX_COURSES, vector<bool>(MAX_COURSES, false));
    int c; cin >> c; for (int con = 0; con < c; con++){
        int c1, c2; cin >> c1 >> c2; conflict[c1][c2] = conflict[c2][c1] = true;
    }

    int assigned[MAX_COURSES + 1];
    int load[MAX_TEACHERS+1];
    memset(assigned, 0, MAX_COURSES * sizeof(int)); 
    memset(load, 0, MAX_COURSES * sizeof(int)); 
    int min_load = INT_MAX;

    function<void(int)> solve = [&](int course){
        if (course == courses + 1){
            int maxLoad = 0;
            for (int idx = 1; idx <= teachers; idx++) maxLoad = max(maxLoad, load[idx]);
            min_load = min(maxLoad, min_load);
            return;
        }   

        for (int teacher : choices[course]){
            bool possible = true;
            for (int prev = 1; prev < course; prev++){
                if (assigned[prev] == teacher && conflict[prev][course]){
                    possible = false;
                    break;
                }
            }

            if (possible){
                assigned[course] = teacher;
                load[teacher]++;
                if (load[teacher] < min_load) solve(course + 1);
                load[teacher]--;
            }
        }
    };

    solve(1);
    cout << min_load << endl;
    return 0;

}
