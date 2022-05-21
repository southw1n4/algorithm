#include <iostream>
#include <algorithm>

using namespace std;
const int N = 1e6 + 10;
int huo[N];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; ++ i) cin >> huo[i];
    sort(huo, huo + n);
    int loc = huo[n / 2];
    
    int res = 0;
    for(int i = 0; i < n; ++ i) res += abs(huo[i] - loc);
    cout << res << endl;
    return 0;
    
}
