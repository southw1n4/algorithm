#include <iostream>
#include <string>


using namespace std;
const int N = 1e4 + 10;

int trie[N][26], idx = 0;
int cnt[N];
int root = 0;


void insert(string s){
    int p = root;
    for(char c: s){
        int t = c - 'a';
        if(!trie[p][t]) trie[p][t] = ++ idx;
        p = trie[p][t];
    }
    cnt[p] ++;
}

int query(string& s){
    int p = root;
    for(char c: s){
        int t = c - 'a';
        p = trie[p][t];
        if(!p) return 0;
    }
    return cnt[p];
}
int main(){
    int n;
    string s;
    char op;
    cin >> n;

    while (n -- ) {
        cin >> op >> s;
        if (op == 'I') {
            insert(s);
        }else {
            cout << query(s) << endl;
        }
    }

    return 0;

}
