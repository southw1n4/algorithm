#include <iostream>

using namespace std;
const int N = 3e2 + 10;
int dp[N][N], psum[N];
int n;

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++ i){
        cin >> psum[i];
        psum[i] += psum[i - 1];
    } 

    for(int l = 2; l <= n; ++ l) {
        for(int i = 1; i + l - 1 <= n; ++ i) {
            int j = i + l - 1;
            dp[i][j] = 0x3f3f3f3f;
            for(int k = i; k < j; ++ k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + psum[j] - psum[i - 1]);
            }
        }
    }


    cout << dp[1][n] << endl;
    return 0;
}
