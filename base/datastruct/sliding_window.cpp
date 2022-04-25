#include <iostream>

using namespace std;
const int N = 1e6 + 10;
int nums[N], que[N];
int n, w;

int main(){
    cin >> n >> w;
    for(int i = 0; i < n; ++ i) cin >> nums[i];
    int h = 0, t = -1;
    for(int i = 0; i < n; ++ i){
        if(h <= t && que[h] + w > i) ++ h;
        while(h <= t && nums[que[t]] >= nums[i]) -- t;
        que[++ t] = i;
        for(int j = h; j <= t; ++ j) cout << nums[que[j]] << " ";
        cout << endl;
        if(i >= w - 1) cout << nums[que[h]] << " ";
    }
    cout << endl;

    h = 0, t = -1;
    for(int i = 0; i < n; ++ i){
        if(h <= t && que[h] + w >= i) ++ h;
        while(h <= t && nums[que[t]] <= nums[i]) -- t;
        que[++ t] = i;
        if(i >= w - 1) cout << nums[que[h]] << " ";
    }
    cout << endl;

    return 0;

}



