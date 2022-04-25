#include <iostream>

using namespace std;

const int N =1e5 + 10;
int que[N];

int main(){
    int n;
    cin >> n;
    int h = 0, t = 0;
    while(n --){
        string op;
        cin >> op;
        int x;
        if(op == "push"){
            cin >> x;
            que[t ++] = x; 
        }else if(op == "empty"){
            cout << (h == t ? "YES": "NO") << endl;
        }else if(op == "query"){
            cout << que[h] << endl;
        }else ++ h;
    }
    return 0;
}

