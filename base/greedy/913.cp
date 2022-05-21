#include <iostream>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
int ti[N];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n;  ++ i){
        cin >> ti[i];
    }
    long long res = 0, temp = 0;
    sort(ti, ti + n);
    for(int i = 0; i < n; ++ i){
        res += temp;
        temp += ti[i];
    }
    cout << res << endl;
    return 0;
}
