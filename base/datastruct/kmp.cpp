#include <iostream>

using namespace std;

const int N = 1e6 + 10;
char s[N], p[N];
int ne[N], n, m;

int main(){

    cin >> m >> (p + 1) >> n >> (s + 1);

    for(int j = 0, i = 2; i <= m; ++ i){
        while(j && p[i] != p[j + 1]) j = ne[j];
        if (p[i] == p[j + 1]) ++ j;
        ne[i] = j;
    }

    for(int j = 0, i = 1; i <= n; ++ i){
        while(j && s[i] != p[j + 1]) j = ne[j];
        if(s[i] == p[j + 1]) ++ j;
        if(j == m){
            j = ne[j];
            cout << i - m << " ";
        }
    }

    return 0;

}
