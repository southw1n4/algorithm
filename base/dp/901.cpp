#include <iostream>
#include <cstring>

using namespace std;

const int N = 3e2 + 10;
int dp[N][N], g[N][N];
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
int n, m;

int dfs(int x, int y){
    if(dp[x][y] != -1) return dp[x][y];

    dp[x][y] = 1;
    for(int i = 0; i < 4; ++ i) {
        int a = dx[i] + x, b = dy[i] + y; 
        if(a < 0 || a >= n || b < 0 || b >= m || g[x][y] <= g[a][b]) continue;
        dp[x][y] = max(dp[x][y], 1 + dfs(a, b));
    }

    return dp[x][y];
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; ++ i) {
        for(int j = 0; j < m; ++ j) cin >> g[i][j];
    }

    int ans = 0;
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n; ++ i) {
        for(int j = 0; j < m; ++ j){
            if(dp[i][j] == -1) dfs(i, j);
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << endl;
    return 0;
}
