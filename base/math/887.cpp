#include <iostream>

using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
LL mod;
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

LL locus(LL a, LL b) {
    if(a < mod && b < mod) {
        if(b > a) return 1;
        return st[a] * quick_mi(st[a - b], mod - 2) % mod * quick_mi(st[b], mod - 2) % mod;
    } 
    return locus(a % mod, b % mod) * locus(a / mod, b / mod) % mod;
}

int main() {
    int n;
    cin >> n;

    while(n --) {
        LL a, b;
        cin >> a >> b >> mod;
        st[0] = 1;
        for(int i = 1; i <= mod; ++ i) st[i] = st[i - 1] * i % mod;

        cout << locus(a, b) << endl;
    }

    return 0;
}
