#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 1e2 + 10, M = 1e4 + 10;
int n, m;
int sg[M], p[N];

int dfs(int num) {
    if(sg[num] == -1) {
        vector<int> st;
        
        for(int i = 0; i < n; ++ i){
            if(p[i] <= num) st.push_back(dfs(num - p[i]));
        }
        sort(st.begin(), st.end());
        for(int i = 0; i < st.size(); ++ i) {
            if(st[i] != i) {
                sg[num] = i;
                break;
            }
        }
    }
    
    return sg[num];
}

int main() {
    cin >> n;
    for(int i = 0; i < n; ++ i) cin >> p[i];
    cin >> m;
    int res = 0;
    
    memset(sg, -1, sizeof sg);
    while(m --) {
        int s;
        cin >> s;
        
        res ^= dfs(s);
    }
    
    if(res) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}
