#include <iostream>

using namespace std;

string add(string& a, string& b){
    if(a.size() > b.size()) return add(b, a);
    string ans;
    int n = a.size(), m = b.size(), t = 0;
    for(int i = n - 1, j = m - 1; j >= 0; -- i, -- j){
        t += b[j] - '0';
        if(i >= 0) t += a[i] - '0';
        b[j] = (t % 10) + '0';
        t /= 10;
    }
    if(t) b = to_string(t) + b; 
    return b;

}

int main(){
    string a, b;
    cin >> a >> b;
    cout << add(a, b) << endl;
    return 0;
}
