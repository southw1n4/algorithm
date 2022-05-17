#include <iostream>
#include <vector>

using namespace std;

const int N = 2e3 + 10;
int n, m;
int dp[N];

int main() {
    cin >> n >> m;
    vector<int> w, v;
    
    while(n --) {
        int a, b, c;
        cin >> a >> b >> c;
        
        int cnt = 1;
        while(c) {
            cnt = min(cnt, c);
            w.push_back(cnt * b), v.push_back(cnt * a);
            c -= cnt;
            cnt *= 2;
        }
    }
    
    for(int i = 0; i < w.size(); ++ i) {
        for(int j = m; j >= v[i]; -- j) {
            dp[j] = max(dp[j - v[i]] + w[i], dp[j]);
        }
    }

    cout << dp[m] << endl;

    return 0;
}
