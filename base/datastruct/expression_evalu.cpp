#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<char, int> order;

int compute(int a, int b, char c){
    int res;
    switch(c){
        case '+': res = a + b; break;
        case '-': res = a - b; break;
        case '*': res = a * b; break;
        case '/': res = a / b; break;
    }
    return res;
}

int main(){
    
    order['+']  = order['-'] = 0;
    order['*']  = order['/'] = 1;
    order['('] = -1;
    string op, mid, st;
    cin >> mid;
    for(char c : mid){
        if (c >= '0' && c <= '9') op.push_back(c);
        else if(c == '(') st.push_back(c);
        else if(c == ')'){
            if(op.size() && op.back() >= '0' && op.back() <= '9') op.push_back(',');
            while(st.back() != '('){
                op.push_back(st.back());
                st.pop_back();
            }
            st.pop_back();
        }else{
            if(op.size() && op.back() >= '0' && op.back() <= '9') op.push_back(',');
            while(st.size() && order[st.back()] >= order[c]){
                op.push_back(st.back());
                st.pop_back();
            }
            st.push_back(c);
        }
    }
    while(st.size()){
        op.push_back(st.back());
        st.pop_back();
    }
    vector<int> tt;
    int n = op.size();
    for(int i = 0; i < n; i ++){
        char c = op[i];
        if(c == ',') continue;
        if(c >= '0' && c <= '9'){
            int num = c - '0';
            while(i + 1 < n && op[i + 1] >= '0' && op[i + 1] <= '9') {
                i ++;
                num = num * 10 + op[i] - '0';
            }
            tt.push_back(num);
           // cout << tt.back() << endl;
        }else{
           // cout << c << endl;
            int a, b;
            b = tt.back();
            tt.pop_back();
            a = tt.back();
            tt.pop_back();
            tt.push_back(compute(a, b, c));
        }
    }
    cout << tt.back() << endl;
    return 0;
}
