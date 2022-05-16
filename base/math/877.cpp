#include <iostream>

using namespace std;

int ex_gcd(int a, int b, int& x, int& y) {

    if(!b) {
        x = 1, y = 0;
        return a;
    }

    int d = ex_gcd(b, a % b, y, x);
    y = y -  a / b * x;
    return d;

}

int main() {
    int n;
    cin >> n;

    while(n --) {
        int a, b, x, y;
        cin >> a >> b;

        ex_gcd(a, b, x, y);
        cout << x << " " << y << endl;
    }

    return 0;
}
