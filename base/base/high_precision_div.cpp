#include <iostream>

using namespace std;

void div(string& a, int& b){
    int rem = 0;
    string quo;
    for(int i = 0; i < a.size(); ++ i){
        rem = rem * 10 + a[i] - '0';
        quo.push_back(rem / b + '0');
        rem %= b;
    }
    int n = 0;
    while(quo[n] == '0') ++ n;
    a = quo.substr(n);
    if(a.size() == 0) a = "0";
    b = rem;
}

int main(){
    string a;
    int b;

    cin >> a >> b;
    div(a, b);

    cout << a << endl << b << endl;

    return 0;
}
