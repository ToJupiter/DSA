#include <bits/stdc++.h>
using namespace std;

int main(){
    string inp; cin >> inp;
    int max_count = 1;
    int current_count = 1;
    for (int i = 1; i < inp.size(); i++){
        if (inp[i] == inp[i-1]) current_count++;
        else current_count = 1;
        max_count = max(max_count, current_count);
    }
    cout << max_count << endl;
}