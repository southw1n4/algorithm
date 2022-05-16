#include <iostream>
#include <vector>

using namespace std;
typedef  long long LL;

int main() {
    LL n, m, res;
    cin >> n >> m;
    vector<LL> prime(m);
    res = 0;
    
    for(int i = 0; i < m; ++ i) cin >> prime[i];
    
    for(int i = 0; i < 1 << m; ++ i) {
        LL cnt = 0, sum = 1, sig = 1;
        bool flag = false;
        
        for(int j = 0; j < m; ++ j) {
            if((i >> j) & 1){
                cnt ++;  
                sum *= prime[j];
                if(sum > n){
                    flag = true;
                    break;
                } 
            } 
        }
        
        if(cnt % 2 == 0) sig = -1;
        if(sum != 1 || flag)
            res += n * sig / sum;
    }
    
    cout << res << endl;
}
