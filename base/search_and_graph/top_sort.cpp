#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

const int N = 1e5 + 10, M = N;
int h[N], ne[M], e[M], idx;
int n, m;
int din[N], path[N], cnt;

void add(int a, int b){
    e[idx] = b; ne[idx] = h[a], h[a] = idx ++;
}

int top_sort(){
    stack<int> stk;
    for(int i = 1; i <= n; ++ i){
        if(din[i] == 0) stk.push(i);
    }

    while(stk.size()){
        int p = stk.top();
        stk.pop();
        path[cnt ++] = p;

        for(int i = h[p]; ~i; i = ne[i]){
            int j = e[i];

            din[j] --;
            if(din[j] == 0) stk.push(j);
        }

    }

    return cnt;
}

int main(){
    cin >> n >> m;
    memset(h, -1, sizeof h);
    bool flag = false;
    while(m --){
        int a, b;
        cin >> a >> b;
        if(a == b) {
            flag = true;
            continue;
        }

        din[b] ++;
        add(a, b);
    }


    if (top_sort() == n && !flag) {
        for(int i = 0; i < n; ++ i) cout << path[i] << " ";
        cout << endl;

    }else cout << -1 << endl;

    return 0;
}




