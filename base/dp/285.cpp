#include <iostream>
#include <cstring>

using namespace std;

const int N = 6e3 + 10, M = N;
int h[N], e[M], ne[M], idx; 
int w[N], dp[N][2];
bool st[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int p) {

    dp[p][1] = w[p];
    for(int i = h[p]; ~i; i = ne[i]) {
        int j = e[i];
        dfs(j);
        
        dp[p][1] = max(dp[p][1], dp[p][1] + dp[j][0]);
        dp[p][0] = max(dp[p][0], dp[p][0] + max(dp[j][0], dp[j][1]));
    }

}

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++ i) cin >> w[i];
    
    memset(h, -1, sizeof h);
    for(int i = 0; i < n - 1; ++ i) {
        int a, b;
        cin >> b >> a;
        st[b] = true;
        add(a, b);
    }

    int root = 1;
    while(st[root]) root ++;
    dfs(root);

    cout << max(dp[root][0], dp[root][1]) << endl;

    return 0;
}

