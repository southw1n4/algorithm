#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n, q;
int nums[N];

int main(){
    cin >> n >> q;
    for(int i = 0;  i < n; ++ i) cin >> nums[i];
    while(q --){
        int target;
        cin >> target;
        int l = 0, r = n - 1;
        while(l < r){
            int mid = (l + r) / 2;
            if(nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        if(nums[l] != target) l = -1;
        cout << l << " ";

        l = 0, r = n - 1;
        while(l < r){
            int mid = (l + r + 1) / 2;
            if(nums[mid] <= target) l = mid;
            else r = mid - 1;
        }
        if(nums[l] != target) l = -1;
        cout << l << endl;
    }
    return 0;

}
