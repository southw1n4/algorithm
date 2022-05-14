#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int N = 150000 + 10, INF = 0x3f3f3f3f;
int h[N], e[N], ne[N], v[N], idx;
int dist[N], vis[N];
int n, m;

void add(int a, int b, int c){
    e[idx] = b, v[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

int dijkstra(){
    memset(dist, 0x3f, sizeof dist);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    dist[1] = 0;
    pq.push({0, 1});

    while (pq.size()) {
        auto p = pq.top();
        pq.pop();
        if (vis[p[1]]) continue;
        vis[p[1]] = 1;
        if (p[1] == n) return p[0];

        for (int i = h[p[1]]; ~i; i = ne[i]) {
            int j = e[i];
            if (dist[j] > p[0] + v[i] && !vis[j]) {
                dist[j] = p[0] + v[i];
                pq.push({dist[j], j});
            }
        }
    }

    return -1;
}

int main(){
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while (m --) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    cout << dijkstra() << endl;
    
    return 0;
}
