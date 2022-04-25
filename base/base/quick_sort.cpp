#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int nums[N];

void quick_sort(int l, int r){

    if (l >= r) return ;
    int x = nums[(l + r) >> 1], i = l - 1, j =  r + 1;
    while(i < j){
        do {++ i;} while(nums[i] < x);
        do {-- j;} while(nums[j] > x);
        if( i < j) swap(nums[i], nums[j]);
     }
    quick_sort(l, i - 1);
    quick_sort(i, r);
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; ++ i) cin >> nums[i];
    quick_sort(0, n -  1);
    for(int i = 0; i < n; ++ i) cout << nums[i] << " ";
    return 0;
}

