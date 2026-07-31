#include <bits/stdc++.h>

using namespace std;

/*
    This only holds true because when reaching i = 1, 0 <= T <= 1.
    If T == 0: put 1 to the first set
    Elif T==1: put 1 to the second set

*/

void print_arr(const vector<int>& arr){
    cout << arr.size() << endl;
    for (int i = 0; i < (int)arr.size(); i++) cout << arr[i] << " ";
    cout << endl;
}

int main(){
    int n; cin >> n;
    long long total = 1LL * n * (n + 1) / 2;
    vector <int> set1, set2;
    if (total % 2 != 0) {
        cout << "NO" << endl;
        return 0;
    }
    else {
        long long target = total / 2;
        for (int i = n; i >= 1; i--){
            if (target >= i){
                target -= i;
                set1.push_back(i);
            }
            else {
                set2.push_back(i);
            }
        }
        cout << "YES" << endl;
        print_arr(set1);
        print_arr(set2);
    }
    
}