#include <bits/stdc++.h>
using namespace std;
#define MAXN 3001


int main(){
    string a,b; cin >> a >> b;
    vector<vector<int>> array(MAXN, vector<int>(MAXN, 0));
    string lar = (a.length() > b.length()) ? a : b;
    string sma = (a.length() > b.length()) ? b : a;
    int bi = lar.length();
    int sm = sma.length();

    for (int i = 1; i < bi; i++){
        for (int j = 1; j < sm; j++){
            if (lar[i-1] == sma[j-1]) array[i][j] = array[i-1][j-1] + 1;
            else array[i][j] = max(array[i-1][j], array[i][j-1]);
        }
    }

    string res; 
    while(bi > 0 && sm > 0){
        if (lar[bi-1] == sma[sm-1]){
            res += lar[bi-1];
            bi--; sm--;
        }
        else if (lar[bi-1] > sma[sm-1]) bi--;
        else sm--;
    }
    cout << res << endl;
    return 0;
    
    
    
}