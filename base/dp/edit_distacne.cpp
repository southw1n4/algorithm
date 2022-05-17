#include <iostream>

using namespace std;
const int N = 1e3 + 10;
int dp[N][N];

int main() {
    int n, m;
    string a, b;
    cin >> n >> a >> m >> b;
    for(int i = 0; i < N; ++ i)dp[i][0] = dp[0][i] = i;

    for(int i = 1; i <= n; ++ i) {
        for(int j = 1; j <= m; ++ j) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (a[i - 1] == b[j - 1] ? 0 : 1));
        }
    }

    cout << dp[n][m] << endl;

    return 0;
}


