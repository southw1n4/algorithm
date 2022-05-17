#include <iostream>
#include <cstring>

using namespace std;

const int N = 22, M = 1 << 20;

int G[N][N];
int n;
int dp[M][N];

int main(){
    cin >> n;
    memset(dp, 0x3f, sizeof dp);
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= n; ++ j){
            cin >> G[i][j];
        }
    }
    
    dp[1][0] = 0;
    for(int i = 1; i < 1 << n; ++ i){
        for(int k = 0; k < n; ++ k){
            if(i & (1 << k)){
                for(int j = 0; j < n; ++ j){
                    if((i - (1 << k)) & (1 << j))dp[i][k] = min(dp[i][k], dp[i - (1 << k)][j] + G[j + 1][k + 1]);
                }
            }
        }
    }
    cout << dp[(1 << n) - 1][n - 1] << endl;
    return 0;
    
}

