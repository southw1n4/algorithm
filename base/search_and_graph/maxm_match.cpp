#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
const int N = 5e2 + 10, M = 1e5 + 10;
int match[N];
vector<int> e[N];
int n1, n2, m;
bool st[N];

bool find(int x) {
    for (int y : e[x]) {
        if (st[y]) continue;
        st[y] = true;
        if (!match[y] || find(match[y])){
            match[y] = x;
            return true;
        }
    }
    return false;
}

int main(){
    cin >> n1 >> n2 >> m;
    while (m --) {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
    }

    int res = 0;
    for (int i = 1; i <= n1; ++ i) {
        memset(st, 0, sizeof st);
        if (find(i)) res ++;
    }

    cout << res << endl;
    return 0;
}
