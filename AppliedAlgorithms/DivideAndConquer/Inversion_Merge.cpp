#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod_ll = 1e9+7;
int count_inv = 0;


void merge(vector<int> &arr, int left, int mid, int right){
    vector<int> temp(right - left + 1); int i = left,
    j = mid + 1, k = 0;

    while(i <= mid &&  j <= right){
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else{
            temp[k++] = arr[j++];
            count_inv += (mid - i + 1);
            count_inv %= mod_ll;
        }
    }

    // because we merge 2 arrays, we know that
    // one array may get exhausted before the another
    // so we have to prevent that case by doing
    // 2 while's

    while(i <= mid) temp[k++] = arr[i++];
    while(j <= right) temp[k++] = arr[j++];

    for (int p = 0; p < k; p++) arr[left + p] = temp[p];


}

void merge_sort(vector<int> &arr, int left, int right){
    if(left < right){
        int mid = left + (right - left)/2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main(){
//    freopen("inversion.txt", "r", stdin);

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n; vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    merge_sort(arr, 0, n - 1);
    cout << count_inv << endl;
    return 0;

}
