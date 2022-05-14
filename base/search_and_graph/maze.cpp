#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int N = 110;
vector<vector<char>> mz(N, vector<char>(N));
vector<vector<int>> dist(N, vector<int>(N, 0));
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
int n, m;
int bfs(){
    queue<vector<int>> que;

    que.push({0, 0});
    dist[0][0] = 1;

    while(que.size()){
        auto p = que.front();
        que.pop();
        int x = p[0], y = p[1];

        for(int i = 0; i < 4; ++ i){
            int a = x + dx[i], b = y + dy[i];
            if(a < 0 || a >= n || b < 0 || b >= m || dist[a][b] || mz[a][b] == '1') continue;

            dist[a][b] = dist[x][y] + 1;
            if(a == n - 1 && b == m -1) return dist[a][b] - 1;
            que.push({a, b});
        }
    }

    return 0;

}

int main(){

    cin >> n >> m;

    for(int i = 0; i < n; ++ i){
        for(int j = 0; j < m; ++ j){
            cin >> mz[i][j];
        }
    }

    cout << bfs() << endl;

    return 0;
}
