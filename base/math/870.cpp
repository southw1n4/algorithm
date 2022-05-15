#include <iostream>
#include <unordered_map>

using namespace std;
const int mod = 1e9 + 7;

unordered_map<int, int> st;

int main() {
    int n;
    cin >> n;

    while(n --) {
        int num;
        cin >> num;

        int t = num;
        for(int i = 2; i <= num / i; ++ i) {
            if(t % i == 0) {
                int cnt = 0;
                while(t % i == 0) {
                    t /= i;
                    cnt ++;
                }
                if(!st.count(i)) st[i] = 0;
                st[i] += cnt;
            }
        }
        if(t > 1) { 
            if(!st.count(t)) st[t] = 0;
            st[t] += 1;
        }
    }

    int res = 1;
    for(auto& [k, v] : st) {
        res = res * (v + 1 ) % mod;
    }
    cout << res << endl;

    return 0;
}
