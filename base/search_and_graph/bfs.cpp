#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;
int h[N], e[2 * N], ne[2 * N], idx;
int dist[N];
int n, m;

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a]; h[a] = idx ++;
}

int bfs(){
    if(1 == n) return 0;
    queue<int> que;
    que.push(1);
    dist[1] = 1;

    while(que.size()){
        int p = que.front();
        que.pop();

        for(int i = h[p]; ~i; i = ne[i]){
            int j = e[i];
            if(dist[j]) continue;
            if(j == n) return dist[p];

            dist[j] = dist[p] + 1;
            que.push(j);
        }
    }

    return -1;
}

int main(){
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while(m --){
        int a, b;
        cin >> a >> b;
        add(a, b);
    }

    cout << bfs() << endl;

    return 0;
}
