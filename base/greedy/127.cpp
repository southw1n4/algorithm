#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, int> PII;
vector<PII> bull;

int main(){
    int n;
    cin >> n;
    while(n --){
        int a, b;
        cin >> a >> b;
        bull.push_back({a, b});
    }
    sort(bull.begin(), bull.end(), [](PII a, PII b)->bool{
        return (a.first + a.second) < (b.first + b.second);
        
    });
    
    int res = -2e9, pre_sum = 0;
    for(auto p : bull){
        res = max(res, pre_sum - p.second);
        pre_sum += p.first;
    }
    cout << res << endl;
    return 0;
}
