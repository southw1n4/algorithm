#include <iostream>

using namespace std;

string sub(string& a, string& b){
    int t = 0;
    int n = a.size(), m = b.size();
    for(int i = n - 1, j = m - 1; j >= 0; -- i, -- j){
        t += b[j] - '0';
        if(i >= 0)t -= a[i] - '0';
        b[j] = (t % 10 + 10) % 10 + '0';
        t = t < 0 ? -1 : 0;
    }
    m = 0;
    while(b[m] == '0' && m < b.size()) ++ m;
    if(m == b.size()) return "0";
    return b.substr(m);
}

int main(){
    string a, b;

    cin >> a >> b;
    if((a.size() == b.size() && a < b) || a.size() < b.size()) {
        cout << '-'; 
    }else swap(a, b);
    cout << sub(a, b) << endl;

    return 0;

}
