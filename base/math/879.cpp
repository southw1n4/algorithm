#include <iostream>

using namespace std;

typedef long long LL;

LL ex_gcd(LL a, LL b, LL& x, LL& y) {
    if(!b) {
        x = 1, y = 0;
        return a;
    }

    LL d = ex_gcd(b, a % b, y, x); 
    y = y - a / b * x;
    return d;
} 

int main() {
    int n;
    cin >> n;
    LL a1, m1;
    bool flag = true;

    cin >> a1 >> m1;
    for(int i = 1; i < n;  ++ i) {
        LL a2, m2, k1, k2;
        cin >> a2 >> m2;
        if(!flag) continue;

        LL d = ex_gcd(a1, a2, k1, k2); 
        if((m2 - m1) % d) {
            flag = false;
            break;
        }

        k1 *= (m2 - m1) /d;
        LL t = a2 / d;
        k1 = (k1 % t + t) % t;
        m1 = k1 * a1 + m1;
        a1 = abs(a1 * a2 / d);

    }

    if(!flag) cout << -1 << endl; 
    else
        cout << (m1 % a1 + a1) % a1  << endl;

    return 0;
}
