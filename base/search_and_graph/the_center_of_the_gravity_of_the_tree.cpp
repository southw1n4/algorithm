#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;
int h[N], ne[N * 2], e[N * 2], idx = 0;
int n;

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

int  ans = 1e9 + 7;

int dfs (int root, int pre){
    int sum = 1;
    int t_max = 0;
    for (int i = h[root]; ~i; i = ne[i]){
        int j = e[i];
        if (j == pre) continue;

        int t = dfs(j, root); 
        sum += t;
        t_max = max(t, t_max);
    }
    ans = min(ans, max(t_max, n - sum));
    return sum;
}


int main(){
    cin >> n;
    memset(h, -1, sizeof h);
    for(int i = 1; i < n; ++ i){
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }

    dfs(1, -1);
    cout << ans << endl;

    return 0;
}


