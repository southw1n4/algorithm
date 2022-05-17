#include <iostream>

using namespace std;

const int N = 5e2 + 10;
int g[N][N];
int n;

int main() {
    cin >> n;

    for(int i = 1; i <= n; ++ i) {
        for(int j = 1; j <= i; ++ j) {
            cin >> g[i][j];
        }
    }

    for(int i = n - 1; i >= 0; i --) {
        for(int j =1; j <= i; ++ j) {
            g[i][j] += max(g[i + 1][j], g[i + 1][j + 1]);
        }
    }

    cout << g[1][1] << endl;

    return 0;
}
