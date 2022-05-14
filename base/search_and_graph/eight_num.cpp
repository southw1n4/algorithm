#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

string bg = "12345678x", ed = "12345678x";
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
unordered_map<string, int> dist;

int bfs(){
    queue<string> que;
    que.push(bg);
    dist[bg] = 0;

    while(que.size()){
        auto p = que.front();
        que.pop();
        if(p == ed) return dist[p]; 

        int z = p.find('x'), d = dist[p];
        int x = z / 3, y = z % 3;
        for(int i = 0; i < 4; ++ i){
            int a = x + dx[i], b = y + dy[i];
            if(a < 0 || a >= 3 || b < 0 || b >= 3) continue;
            swap(p[z], p[a * 3 + b]);

            if(!dist.count(p)){
                dist[p] = d + 1;
                que.push(p);
            }

            swap(p[z], p[a * 3 + b]);
        }
    }

    return -1;
}


int main(){
    for(int i = 0; i < 9; ++ i) cin >> bg[i];

    cout << bfs() << endl;

    return 0;
}
