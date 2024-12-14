#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;
const int INF = 1e9;

int n;
int distanceMap[MAX][MAX];
vector<int> bestPath;
int bestDistance = INF;

// Function to read input
void readInput() {
    cin >> n;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> distanceMap[i][j];
}

// Branch and Bound function
void tsp(int current, int count, int cost, vector<bool> &visited, vector<int> &path) {
    if(count == n && distanceMap[current][0] > 0){
        if(cost + distanceMap[current][0] < bestDistance){
            bestDistance = cost + distanceMap[current][0];
            bestPath = path;
        }
        return;
    }

    for(int i = 1; i < n; ++i){
        if(!visited[i] && distanceMap[current][i] > 0){
            if(cost + distanceMap[current][i] < bestDistance){
                visited[i] = true;
                path.push_back(i);
                tsp(i, count + 1, cost + distanceMap[current][i], visited, path);
                visited[i] = false;
                path.pop_back();
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    readInput();
    vector<bool> visited(n, false);
    vector<int> path;
    visited[0] = true;
    path.push_back(0);
    tsp(0, 1, 0, visited, path);
    cout << n << "\n";
    for(auto city : bestPath)
        cout << (city + 1) << " ";
    return 0;
}