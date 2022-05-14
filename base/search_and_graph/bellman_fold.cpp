#include <iostream>
#include <cstring>

using namespace std;

const int N = 5e2 + 10, M = 1e4 + 10, INF = 0x3f3f3f3f;
struct Edge{
    int s, e, v;
}e[M];
int backup[N], dist[N];
int n, m, k;

string bellman_fold(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for (int i = 1; i <= k; ++ i){
        memcpy(backup, dist, sizeof dist);
        for(int j = 0; j < m; ++ j){
            int a = e[j].s, b = e[j].e, c = e[j].v;
            dist[b] = min(dist[b], backup[a] + c);
        }

    }

    if (dist[n] > INF / 2)  return "impossible";
    else return to_string(dist[n]);
}

int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < m; ++ i){
        int a, b, c;
        cin >> a >> b >> c;
        e[i] = {a, b, c};
    }

    cout << bellman_fold() << endl;

    return 0;
}
