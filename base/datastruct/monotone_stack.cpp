#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n;
int stk[N];

int main(){
    int head = 0, tail = 0;
    stk[0] = -1;
    cin >> n;
    for(int i = 0; i < n; ++ i){
        int num;
        cin >> num;
        while(stk[tail] >= num) -- tail;
        cout << stk[tail] << " ";
        stk[++ tail] = num;
    }
    cout << endl;
    return 0;
}
