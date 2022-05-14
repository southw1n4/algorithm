#include <iostream>
#include <vector>

using namespace std;
int n;

vector<bool>  col(10, 0), row(10, 0), diag(20, 0), r_diag(20, 0);

void dfs(int p, int n, int cnt, vector<string>& st){
    if(p / n == n){
        if(cnt == n){
            for(auto& s: st){
                cout << s << endl;
            }
            cout << endl;
        }
        return ;
    }


    int x = p / n, y = p % n;

    dfs(p + 1, n, cnt, st);

    if(!row[x] && !col[y] && !r_diag[x + y] && !diag[10 + (x - y)]){
        row[x] = col[y] = r_diag[x + y] = diag[10 + (x - y)] = true;
        st[x][y] = 'Q';
        dfs(p + 1, n, cnt + 1, st);
        st[x][y] = '.';
        row[x] = col[y] = r_diag[x + y] = diag[10 + (x - y)] = false;
    }

    return ;

}

int main(){
    cin >> n;
    vector<string> st(n, string(n,'.'));

    dfs(0, n, 0, st);
    return 0;
}
