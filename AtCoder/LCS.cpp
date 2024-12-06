#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3005;

int main() {
    ios::sync_with_stdio(false);
    string a, b; cin >> a >> b;
    string larger_str = (a.length() > b.length()) ? a : b;
    string smaller_str = (a.length() > b.length()) ? b : a;
    int larger_length = larger_str.length();
    int smaller_length = smaller_str.length();
    vector<vector<int>> array(MAXN, vector<int>(MAXN, 0));
    
    for (int i = 1; i <= larger_length; i++) {
        for (int j = 1; j <= smaller_length; j++) {
            if (larger_str[i-1] == smaller_str[j-1]) {
                // i-1, j-1 la subtract ca phan tu do o small 
                // string va bigger string
                array[i][j] = array[i-1][j-1] + 1;
            } else {
                // neu khong thi thuc hien optimization, tim ra
                // cong thuc de optimize for the max
                array[i][j] = max(array[i-1][j], array[i][j-1]);
            }
        }
    }

    
    string result;
    int i = larger_length, j = smaller_length;
    while (i > 0 && j > 0) {
        if (larger_str[i-1] == smaller_str[j-1]) {
            // tu duy backtracking
            result = larger_str[i-1] + result;
            // neu nhu bang nhau chung to no ke thua tu ca big va small
            i--; j--;
        } else if (array[i-1][j] > array[i][j-1]) {
            // ke thua tu larger arr thi cai nay moi lon hon
            i--;
        } else {
            // ke thua tu smaller array!
            j--;
        }
    }
    
    cout << result << endl;
    return 0;
}