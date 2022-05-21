#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    vector<vector<int>> inte;

    cin >> n;
    while(n --) {
        int a, b;
        cin >> a >> b;
        inte.push_back({a, b});
    }

    sort(inte.begin(), inte.end(), [](auto& a, auto& b){
        if(a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    });

    int res = 0;
    int r = -2e9;

    for(auto& p : inte) {
        if(p[0] > r) {
            res ++;
            r = p[1];
        }
    }

    cout << res << endl;
}

