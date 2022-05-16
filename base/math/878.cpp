#include <iostream>

using namespace std;

int ex_gcd(int a, int b, int&x, int& y) {
    if(!b) {
        x = 1, y = 0;
        return a;
    }

    int d = ex_gcd(b, a % b, y, x);
    y = y - a / b * x;
    return d;
}

int main() {
    int n;
    cin >> n;

    while(n --) {
        int a, b, c, x, y;
        cin >> a >> b >> c;

        int d = ex_gcd(a, c, x, y);
        if(b % d) cout << "impossible" << endl;
        else cout << b / d * x << endl; 
    }
    return 0;
}
