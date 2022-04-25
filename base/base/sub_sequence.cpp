#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> A(n), B(m);
    for(int i = 0; i < n; ++ i) cin >> A[i];
    for(int i = 0; i < m; ++ i) cin >> B[i];
    int l1 = 0, l2 = 0;
    while(l2 < m){
        if(B[l2] == A[l1]) ++ l1;
        if(l1 == n) break;
        ++ l2;
    }
    if (l1 == n) puts("Yes");
    else puts("No");

    return 0;

}

