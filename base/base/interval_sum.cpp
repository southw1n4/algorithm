#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n, m;
    vector<int> pos(1, 0);
    vector<vector<int>> op, qu;
    cin >> n >> m;
    while(n --){
        int x, c;
        cin >> x >> c;
        op.push_back({x, c});
        pos.push_back(x);
    }
    while(m --){
        int l, r;
        cin >> l >> r;
        qu.push_back({l, r});
        pos.push_back(l), pos.push_back(r);
    }
    sort(pos.begin(), pos.end());
    pos.erase(unique(pos.begin(), pos.end()),  pos.end());
    vector<int> pre_sum(pos.size() + 1);

    auto get_pos = [&](int num){
        int l = 0, r = pos.size() - 1;
        while(l < r){
            int mid = l + (r - l ) / 2;
            if(pos[mid] == num) return mid;
            else if(pos[mid] > num) r = mid - 1;
            else l = mid + 1;
        }
        return l;
    };
    for(auto& o: op){
        pre_sum[get_pos(o[0])] += o[1];
    }
    for(int i = 1; i < pre_sum.size(); ++ i) pre_sum[i] += pre_sum[i - 1];
    for(auto&q : qu){
        int l = get_pos(q[0]), r = get_pos(q[1]);
        cout << pre_sum[r] - pre_sum[l - 1] << endl;
    }

    return 0;
}
