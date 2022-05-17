#include <iostream>

using namespace std;

const int N = 1e3 + 10;
int n, m;
int dp[N];

int main() {
    cin >> n >> m;
    while(n --) {
        int w, v;
        cin >> v >> w;
        
        for(int j = v; j <= m; ++ j) {
            dp[j] = max(dp[j - v] + w, dp[j]);
        }
    }
    cout << dp[m] << endl;
}
