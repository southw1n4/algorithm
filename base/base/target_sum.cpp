#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> A(n), B(m);
    for(int i = 0; i < n; ++ i) cin >> A[i];
    for(int i = 0; i < m; ++ i) cin >> B[i];
    int l = 0, r = m - 1;
    while(A[l] + B[r] != x){
        int sum = A[l] + B[r];
        if(sum > x) r --;
        else l ++ ;
    }
    cout << l << " " << r << endl;
    return 0;

}
