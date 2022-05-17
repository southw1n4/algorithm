#include <iostream>

using namespace std;
const int N = 1e3 + 10;
int dp[N], nums[N];
int n;

int main() {
    cin >> n;
    for(int i = 0; i < n; ++ i)  cin >> nums[i];

    int res = 0;
    for(int i = 0; i < n; ++ i) {
        dp[i] = 1;
        for(int j = 0; j < i; ++ j) {
            if(nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }

    cout << res << endl;

    return 0;
}
