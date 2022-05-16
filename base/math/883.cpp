#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;
const int N = 1e2 + 10;
double eps = 1e-6;
double eq[N][N];
int n;

int gauss() {

    int c, r;
    for(r = 0, c = 0; c < n; ++ c) {
        int t = r;
        for(int i = r; i < n; ++ i) {
            if(abs(eq[i][c]) > abs(eq[t][c])) t = i;
        }

        if(abs(eq[t][c]) < eps) continue;

        for(int i = c; i <= n; ++ i )swap(eq[t][i], eq[r][i]);
        for(int i = n; i >= c; -- i) eq[r][i] /= eq[r][c];

        for(int i = r + 1; i < n; ++ i) {
            if(abs(eq[i][c]) < eps) continue;

            for(int j = n; j >= c; -- j) {
                eq[i][j] -= eq[r][j] * eq[i][c];
            }
        }
        r ++;
    }

    if(r < n) {
        for(int i = 0; i < n; ++ i) {
            if(abs(eq[i][n]) > eps) return 2;
        }
        return 1;
    }

    for(int i = n - 1; i >= 0; -- i) {
        for(int j = i + 1; j < n; ++ j) {
            eq[i][n] -= eq[i][j] * eq[j][n];
        }
    }

    return 0;
}

int main() {
    cin >> n;

    for(int i = 0; i < n; ++ i) {
        for(int j = 0; j <= n; ++ j) cin >> eq[i][j];
    }

    int r = gauss();
    if(r == 2) puts("No solution");
    else if(r == 1) puts("Infinite group solutions");
    else {
        for(int i = 0; i < n; ++ i)  
            printf("%.2lf\n", eq[i][n]);

    }

    return 0;
}
