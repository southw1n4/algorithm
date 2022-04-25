#include <iostream>


using namespace std;

const int N = 1e5 + 10;
int nums[N], backup[N];
int n, cnt = 0;


void merge_sort(int l, int r){

    if(l >= r) return ;
    int mid = l + (r - l) / 2;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    while(i <= mid && j <= r){
        if(nums[i] <= nums[j]) backup[k ++] = nums[i ++ ];
        else{
            cnt += mid - i + 1;
            backup[k ++] = nums[j ++];
        }
    }
    while(i <= mid) {
        backup[k ++] = nums[i ++];
    }
    while(j <= r) backup[k ++] = nums[j ++];
    for(i = 0; i < k; ++ i) nums[l + i] = backup[i];
}

int main(){
    cin >> n;
    for(int i = 0; i < n; ++ i) cin >> nums[i];
    merge_sort(0, n - 1);
    cout << cnt << endl;
    return 0;
}


