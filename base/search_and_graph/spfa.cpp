#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f;
int h[N], e[N], ne[N], v[N], idx;
int n, m;
int dist[N], in_stk[N], cnt[N];

void add(int a, int b, int c){
    e[idx] = b, v[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

string spfa(){
    queue<int> que;
    for (int i = 1; i <= n; ++ i) que.push(i);

    while(que.size()){
        int p = que.front();
        que.pop();
        in_stk[p] = 0;

        for(int i = h[p]; ~i; i = ne[i]){
            int j = e[i], d = v[i] + dist[p];
            if(d < dist[j]){
                dist[j] = d;
                cnt[j] = cnt[p] + 1;
                if(cnt[j] >= n) return "Yes";
                if (!in_stk[j]) {
                    in_stk[j] = 1;
                    que.push(j);
                }
            }
        }
    }

    return "No";
}

int main(){
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while(m --){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    cout << spfa() << endl;

    return 0;
}
