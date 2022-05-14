#include <iostream>
#include <vector>

using namespace std;
vector<int> nums, st(10, 0);
int n;

void dfs(int p){
    if(p == n + 1){
        for(int num: nums) cout << num << " ";
        cout << endl;

        return ;
    }
    for(int i = 1; i <= n; ++ i){
        if(st[i]) continue;
        st[i] = 1;
        nums.push_back(i);
        dfs(p + 1);
        nums.pop_back();
        st[i] = 0;
    }
}

int main(){
    cin >> n;
    dfs(1);

    return 0;
}
