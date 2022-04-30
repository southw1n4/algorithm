#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int trie[N * 31][2], idx = 0;
int  cnt[N * 31];
int n;

void insert(int num){
    int p = 0;
    for(int i = 31; i >= 0; -- i){
        int t = (num >> i) & 1;
        if(!trie[p][t]) trie[p][t] = ++ idx;
        p = trie[p][t];
    }
    cnt[p] = num;
}

int query(int num){
    int p = 0;
    for(int i = 31; i >= 0; -- i){
        int t = (num >> i) & 1;
        t ^= 1;
        if(!trie[p][t]) t ^= 1;
        p = trie[p][t];
    }
    return num ^ cnt[p];
}

int main(){
    cin >> n;
    int res = 0;
    for(int i = 0; i < n; ++ i){
        int num;
        cin >> num;
        insert(num);
        res = max(res, query(num));
    }

    cout << res << endl;
    return 0;
}

