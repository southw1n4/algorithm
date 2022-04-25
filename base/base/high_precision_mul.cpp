#include <iostream>

using namespace std;

void mul(string& a, int b){
    if(b == 0 || a == "0"){
        a = "0";
        return ;
    } 
    int t = 0, n = a.size();
    for(int i = n - 1; i >= 0; -- i){
        t += (a[i] - '0') * b;
        a[i] = t % 10 + '0';
        t /= 10;
    }
    if(t) a = to_string(t) + a;

}

int main(){
    string a;
    int b;
    cin >> a >> b;

    mul(a, b);
    cout << a << endl;

    return 0;

}
