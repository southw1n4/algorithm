#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){
    int n;
    cin >> n;
    int ans = 0, l = 0, r = -1;
    vector<int> nums(n);
    unordered_map<int, int> cnt;

    for(int i = 0; i < n; ++ i) cin >> nums[i];

    while(true){
        cnt[nums[++ r]] ++;
        if(r == n) break;
        while(cnt[nums[r]] > 1) {
            cnt[nums[l ++]] --;
        }
        ans = max(ans, r - l + 1);
    }

    cout << ans << endl;

    return 0;
}
