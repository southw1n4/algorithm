#include <iostream>
#include <vector> v, w;

using namespace std;

const int N = 1e2 + 10;
int dp[N];
int n, m, k;

int main() {
    cin >> n >> m;
    vector<int> v(N), w(N);
    while(n --) {
        cin >> k;
        for(int i = 0; i < k; ++ i) cin >> v[i] >> w[i];
        
        for(int i = m; i >= 0; i --) {
            for(int j = 0; j < k; ++ j) {
                if(i < v[j]) continue;
                dp[i] = max(dp[i - v[j]] + w[j], dp[i]);
            }
        }
    }
    
    cout << dp[m] << endl;
    
    return 0;
}
