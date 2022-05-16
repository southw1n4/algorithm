#include <iostream>
#include <unordered_map>

using namespace std;
const int mod = 1e9 + 7;

unordered_map<int, int> st;

int quick_mul(int a, int b) {
    int res = 1;

    while(b) {
        if(b & 1) res = (long long)res * a % mod;
        a = (long long )a * a % mod;
        b >>= 1;
    }

    return res;
}

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
        int t =  (long long ) (quick_mul(k, v + 1) - 1) % mod * (quick_mul(k - 1, mod - 2)) % mod;
        res = (long long)res * t % mod;

    }
    cout << res << endl;

    return 0;
}
