#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> interval;
    while(n --){
        int l, r;
        cin >> l >> r;
        interval.push_back({l, r});
    }

    sort(interval.begin(), interval.end(), [&](auto& a, auto& b){
            if(a[0] == b[0]) return a[1] <= b[1];
            return a[0] < b[0];
    });
    int cnt = 0, r = -2e9;
    for(auto& inte: interval){
        if(inte[0] > r) {
            cnt ++;
        }
        r = max(r, inte[1]);
    }

    cout << cnt << endl;

    return 0;

}
