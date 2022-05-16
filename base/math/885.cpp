#include <iostream>

using namespace std;
const int N = 1e5 + 10, mod = 1e9 + 7;
typedef long long LL;

LL st[N];

LL quick_mi(LL a, LL b) {
    LL res = 1;
    while(b) {
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    LL n;
    cin >> n;
    st[0] = 1;

    for(LL i = 1; i < N; ++ i) st[i] = i * st[i - 1] % mod;

    while(n --) {
        LL a, b;
        cin >> a >> b;

        cout << st[a] * quick_mi(st[b], mod - 2) % mod * quick_mi(st[a - b], mod - 2) % mod << endl;
    }

    return 0;
}
