#include <iostream>
#include <string>

using namespace std;

const int N = 5e4 + 10;
int fa[N], dist[N];

int find(int a){

    if(fa[a] != a){
        int t = find(fa[a]);
        dist[a] = (dist[a] + dist[fa[a]]) % 3;
        fa[a] = t;
    }
    return fa[a];
}

int main(){
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; ++ i) fa[i] = i;

    int res = 0;
    for(int i = 1; i <= k; ++ i){
        int op, a, b;
        cin >> op >> a >> b;

        if(a > n || b > n){
            res ++;
            continue;
        }

        int pa = find(a), pb = find(b);
        if(op == 1){
            if(pa == pb && dist[a] != dist[b]){
                res ++;
            }else if(pa != pb){
                dist[pa] = (3 + dist[b] - dist[a]) % 3;
                fa[pa] = pb;
            }
        }else{
            if(pa == pb && (dist[a] + 1) % 3 != dist[b]){
                res ++;
            }else if(pa != pb){
                dist[pa] = ((dist[b] - dist[a] - 1) % 3 + 3) % 3;
                fa[pa] = pb;
            }
        }
    }

    cout << res << endl;

    return 0;
}
