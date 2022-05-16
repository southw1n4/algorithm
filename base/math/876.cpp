#include <iostream>

using namespace std;

int gcd(int a,  int b) {
    if(!b) return a;
    return gcd(b, a % b);
}

int quick_mi(int a, int b) {
    int res = 1;
    int p = b + 2;

    while(b) {
        if(b & 1 ) res = (long long)res * a % p;
        a = (long long)a * a % p;
        b >>= 1;
    }

    return res;
}

int main() {
    int n;
    cin >> n;

    while(n --) {
        int a, p;
        cin >> a >> p;
        if(gcd(a, p) != 1) cout << "impossible" << endl;
        else {
            cout << quick_mi(a, p - 2) << endl;
        }
    }

    return 0;
}
