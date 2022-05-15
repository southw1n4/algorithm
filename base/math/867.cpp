#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    while (n --) {
        int num;
        cin >> num;

        int t = num;
        for (int i = 2; i <= num / i; ++ i) {
            if (t % i == 0) {
                int cnt = 0;
                while (t % i == 0) {
                    cnt ++;
                    t /= i;
                }
                cout << i << " " << cnt << endl;
            }
        }
        if (t > 1) {
            cout << t << " " << 1 << endl;
        }

        cout << endl;
    }

    return 0;
}
