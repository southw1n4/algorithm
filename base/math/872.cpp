#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if(!b) return a;
    return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;
    while(n --) {
        int a, b;
        cin >> a >> b;
        cout << gcd(a, b) << endl;
    }

    return 0;
}
