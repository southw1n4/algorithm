#include <iostream>

using namespace std;


int quick_mi(int a, int b, int p) {
    int res = 1;

    while(b) {
        if(b & 1) res = (long long)res * a % p;
        a = (long long)a * a % p;
        b >>= 1;
    }

    return res;
}

int main() {
    int n;
    cin >> n;

    while(n --) {
        int a, b, p;
        cin >> a >> b >> p;
        cout << quick_mi(a, b, p) << endl;
    }

    return 0;
}
