#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int h = 0, t = 1, l[N], r[N], v[N], idx = 1;


int main(){
    int n;
    l[0] = 1, r[0] = 1;
    l[1] = 0, r[1] = 0;

    cin >> n;
    
    while(n --){
        string op;
        cin >> op;
        int k, x;
        if(op == "L"){
            cin >> x;
            v[++ idx] = x;
            r[idx] = r[h], r[h] = idx;
            l[idx] = 0, l[r[idx]] = idx;

        }else if(op == "R"){
            cin >> x;
            v[++ idx] = x;
            l[idx] = l[t], l[t] = idx;
            r[idx] = 1, r[l[idx]] = idx;
        }else if(op == "D"){
            cin >> k;
            ++ k;
            r[l[k]] = r[k], l[r[k]] = l[k];
        }else if(op == "IL"){
            cin >> k >> x;
            ++ k;
            v[++ idx] = x;
            l[idx] = l[k], r[idx] = k;
            r[l[idx]] = idx, l[k] = idx;
        }else{
            cin >> k >> x;
            ++ k;
            v[++ idx] = x;
            l[idx] = k, r[idx] = r[k];
            l[r[idx]] = idx; r[k] = idx;
        }
    }

    h = r[h];
    for(; h != 1; h = r[h]){
        cout << v[h] << " ";
    }
    return 0;
}
