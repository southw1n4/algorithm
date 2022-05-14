#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

const int N = 5e2 + 10, INF = 0x3f3f3f3f;
int g[N][N], vis[N];
int n, m;

int dijkstra(){
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, 1});

    while (pq.size()) {
        auto p = pq.top();
        pq.pop();
        if(vis[p[1]]) continue;
        vis[p[1]] = 1;
        if (p[1] == n) return p[0];

        for(int i = 1; i <= n; ++ i){
            if(vis[i] || g[p[1]][i] > INF / 2) continue;
            pq.push({p[0] + g[p[1]][i], i});
        }

    }

    return -1;
}

int main(){
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    while (m --) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
    }

    cout << dijkstra() << endl;

    return 0;
}
