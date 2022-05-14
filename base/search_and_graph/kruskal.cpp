#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
int n, m;
int fa[N];

int find(int x){
    return fa[x] = fa[x] == x ? x : find(fa[x]);
}

int main(){
    cin >> n >> m;
    vector<vector<int>> e;
    for(int i = 1; i <= n; ++ i) fa[i] = i;
    while (m --) {
        int a, b, c;
        cin >> a >> b >> c;
        e.push_back({c, a, b});
    }
    sort(e.begin(), e.end());

    int ans = 0, cnt = 0;
    for (auto& p : e) {
        if (find(p[1]) == find(p[2])) continue;

        fa[fa[p[1]]] = p[2];
        ans += p[0];
        cnt += 1;
    }

    if (cnt != n - 1) cout << "impossible" << endl;
    else cout << ans << endl;

    return 0;
}
