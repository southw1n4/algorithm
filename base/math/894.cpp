#include <iostream>
#include <unordered_set>
#include <cstring>

using namespace std;

const int N = 110;
int sg[N];

int get_sg(int num) {
    if(sg[num] != -1) return sg[num];
    
    unordered_set<int> S;
    for(int i = 0; i < num; ++ i) {
        for(int j = 0; j < num; ++ j) {
            S.insert(get_sg(i) ^ get_sg(j));
        }
    }
    
    for(int i = 0; ; ++ i) {
        if(!S.count(i)){
            sg[num] = i;
            break;
        }
    }
    return sg[num];
}

int main() {
    int n;
    cin >> n;
    int res = 0;
    memset(sg, -1, sizeof sg);
    while(n --) {
        int num;
        cin >> num;
        res ^= get_sg(num);
    }
    
    if(res) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}
