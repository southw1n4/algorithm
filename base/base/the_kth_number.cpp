#include <iostream>

using namespace std;
const int N = 1e5 + 10;
int nums[N];
int n, k;

int quick_sort(int l, int r){

    if(l == r) return nums[l];
    int x = nums[l + (r - l) / 2], i = l - 1, j = r + 1;

    while (i < j){
        do ++ i; while(nums[i] < x);
        do -- j; while(nums[j] > x);
        if(i < j) swap(nums[i], nums[j]);
    }
    if(k <= j) return quick_sort(l, j);
    return quick_sort(j + 1, r);
}

int main(){
    cin >> n >> k;
    -- k;
    for(int i = 0; i < n; ++ i) cin >> nums[i];
    cout << quick_sort(0, n - 1) << endl;

    return 0;
}

