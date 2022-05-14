#include <iostream>
#include <cstring>

using namespace std;

const int N = 5e2 + 10, INF = 0x3f3f3f3f;
int g[N][N], dist[N], vis[N];
int n, m;

string prim(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    int ans = 0;

    for (int i = 1; i <= n; ++ i) {
        int min_v = INF, p;
        for (int j = 1; j <= n; ++ j) {
            if (!vis[j] && dist[j] < min_v) {
                p = j;
                min_v = dist[j];
            }
        }

        vis[p] = 1;
        ans += dist[p];

        for (int j = 1; j <= n; ++ j) {
            if (!vis[j] && dist[j] > g[p][j]) {
                dist[j] = g[p][j];
            }
        }
    }

    for (int i = 1; i <= n; ++ i) {
        if (dist[i]> INF / 2) return "impossible";
    }
    return to_string(ans);
}

int main(){
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    for(int i = 1; i <= n; ++ i) g[i][i] = 0;
    while (m --) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }

    cout << prim() << endl;

    return 0;
}
