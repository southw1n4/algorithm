#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int nums[N];
int dp[N];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++ i) cin >> nums[i];

    int cnt = 0;
    for(int i = 0; i < n; ++ i) {
        int l = 0, r = cnt;

        while(l < r) {
            int mid = l + (r - l) / 2 + 1;
            if(dp[mid] >= nums[i]) r = mid - 1;
            else l = mid;
        }

        dp[++ l] = nums[i];
        cnt = max(cnt, l);
    }

    cout << cnt << endl;

    return 0;
}
