#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int h = -1, ne[N], v[N], idx = 0;
int n;

void out(){
    for(int i = h; ~i; i = ne[i]){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){
    cin >> n;
    while(n --){
        char op;
        int k, x;
        cin >> op;
        if (op == 'H'){
            cin >> x;
            v[++ idx] = x; 
            ne[idx] = h;
            h = idx;
        }else if (op == 'D'){
            cin >> k;
            if(k == 0) h = ne[h];
            else
                ne[k] = ne[ne[k]];
        }else{
            cin >> k >> x;
            v[++ idx] = x;
            ne[idx] = ne[k];
            ne[k] = idx;
        }
    }
    out();
    return 0;
}
