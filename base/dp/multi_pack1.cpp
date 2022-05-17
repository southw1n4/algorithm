#include <iostream>

using namespace std;

const int N = 1e2 + 10;
int n, m;
int dp[N];

int main() {
    cin >> n >> m;
    while(n --) {
        int w, v, s;
        cin >> v >> w >> s;
        
        for(int i = m; i >= 0; -- i) {
            for(int j = 0; j <= s; ++ j) {
                if(j * v > i) break;
                dp[i] = max(dp[i - j * v] + j * w, dp[i]);
            }
        }
    }
    cout << dp[m] << endl;
}
