#include <iostream>
#include <cstring>

using namespace std;
const int N = 1e5 + 10, M = 2 * N;
int h[N], e[M], ne[M], idx;
int n, m, color[N];

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

bool dfs(int u, int c){
    color[u] = c;

    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (color[j]) {
            if(color[j] == c) return false;
        } else 
        {
            if (!dfs(j, 3 - c)) return false;
            
        }
    }

    return true;
}

int main(){
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while (m --) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
 
    bool flag = true;
    int cnt = 0;
    for (int i = 1; i <= n; ++ i) {
        if (!color[i]) {
            cnt ++ ;
            flag = dfs(i, 1);
            if (!flag) break;
        }
    }

    if (!flag ) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}

