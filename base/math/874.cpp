#include <iostream>

using namespace std;
const int N = 1e6 + 10;

bool isp[N];
int euler[N], prime[N], cnt;

int get_prime(int n) {
    euler[1] = 1;
    for(int i = 2; i <= n; ++ i) {
        if(!isp[i]) {
            prime[cnt ++] = i;
            euler[i] = i - 1;
        }

        for(int j = 0; prime[j] <= n / i; ++ j) {
            isp[i * prime[j]] = true;
            if(i % prime[j] == 0) {
                euler[i * prime[j]] = euler[i] * prime[j];
                break;
            }else {
                euler[i * prime[j]] = euler[i] * (prime[j] - 1);
            }
        }
    }

    int res = 0;
    for(int i = 1; i <= n; ++ i){
        res += euler[i];
    }
    return res;
}

int main() {

    int n;
    cin >> n;
    cout << get_prime(n) << endl;

    return 0;

}
