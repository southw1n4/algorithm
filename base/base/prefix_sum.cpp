#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n, m;
int pre_sum[N];

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++ i){
        cin >> pre_sum[i];
        pre_sum[i] += pre_sum[i - 1];
    }
    while(m --){
        int l, r;
        cin >> l >> r;
        cout << pre_sum[r] - pre_sum[l - 1] << endl;
    }
    return 0;
}
