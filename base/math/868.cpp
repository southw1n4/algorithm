#include <iostream>

using namespace std;

const int N = 1e6 + 10; 
int prime[N], cnt;
bool isp[N];

int shuai(int n) {
    int cnt = 0;
    for (int i = 2; i <= n; ++ i) {

        if (!isp[i]) prime[cnt ++] = i;

        for (int j = 0; prime[j] <= n / i; ++ j) {
            isp[prime[j] * i] = true;
            if (i % prime[j] == 0) break;
        }
    }

    return cnt;
}

int main() {
    int n;
    cin >> n;

    cout << shuai(n) << endl;

    return 0;
}
