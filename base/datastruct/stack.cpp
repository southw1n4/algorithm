#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int stk[N], top = 0;

int main(){
    int n;
    cin >> n;
    while(n --){
        string op;
        int x;
        cin >> op;
        if(op == "push"){
            cin >> x;
            stk[top ++ ] = x;
        }else if(op == "query"){
            cout << stk[top - 1] << endl;
        }else if(op == "pop"){
            top --;
        }else {
            cout << (top == 0 ? "Yes": "No") << endl;
        }

    }
}
