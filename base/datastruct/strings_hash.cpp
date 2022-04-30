#include <iostream>

using namespace std;

typedef unsigned long long ull;
const int N = 1e5 + 10, P =131;
int n, m;
ull ha[N], p[N];
int main(){
    string s;
    cin >> n >> m >> s;
    p[0] = 1;
    for(int i = 0; i < n; i ++){
        p[i + 1] = p[i] * P;
        ha[i + 1] = ha[i] * P  + s[i]; 
    }
    while(m --){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        ull n1 = ha[r2] - ha[l2 - 1] * p[r2 -l2 + 1];
        ull n2 = ha[r1] - ha[l1 - 1] * p[r1 - l1 + 1];
        if(n1 == n2) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
    
}
