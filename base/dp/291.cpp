#include <iostream>
#include <cstring>

using namespace std;
const int N = 12;
int n, m;
int dp[N][1 << N];
bool st[1 << N];
bool check(int i) {
    int cnt = 0;
    for(int t = 0; t < m; ++ t) {
        if((i >> t) & 1) {
            if(cnt % 2) return false;
            cnt  = 0;
        }else cnt ++;
    }
    return cnt % 2 == 0;
};
int main() {


    while(cin >> n >> m, n) {
        dp[0][0] = 1;
        
        for(int i = 0; i < 1 << m; ++ i) {
            st[i] = check(i);
        }

        for(int i = 1; i <= n + 1; ++ i) {
            for(int j = 0; j < 1 << m; ++ j) {
                dp[i][j] = 0;
                for(int k = 0; k < 1 << m; ++ k) {
                    if(!(k & j) && st[k | j])
                            dp[i][j] += dp[i - 1][k];
                }
            }
        }

        cout << dp[n + 1][(1 << m) - 1] << endl;
    }

    return 0;
}

