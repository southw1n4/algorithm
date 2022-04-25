#include <iostream>

using namespace std;

const int N = 1e3 + 10;
int mat[N][N];
int n, m, q;

int main(){
    cin >> n >> m >> q;
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= m; ++ j){
            cin >> mat[i][j];
        }
    }

    for(int i = n; i >= 1; -- i){
        for(int j = m; j >= 1; -- j){
            mat[i][j] += mat[i - 1][j - 1] - mat[i - 1][j]  - mat[i][j - 1]; 
        }
    }

    while(q --){
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        mat[x1][y1] += c;
        mat[x1][y2 + 1] -= c;
        mat[x2 + 1][y1] -= c;
        mat[x2 + 1][y2 + 1] += c;
    }
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= m; ++ j){
            mat[i][j] += mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1];
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}


