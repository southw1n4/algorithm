#include <iostream>
#include <unordered_map>

using namespace std;
const int N = 5e3 + 10;

unordered_map<int, int> st;

int main() {
    int n;
    cin >> n;

    while(n --) {
        int num;
        cin >> num;

        int res = num;
        for(int i = 2; i <= num / i; ++ i) {
            if(num % i == 0) {
                int cnt = 0;
                while(num % i == 0) {
                    cnt ++;
                    num /= i;
                }
                st[i] = cnt;
            }
        }
        if(num > 1) st[num] = 1;
        
        for(auto& [k, v] : st) {
            res = res * (k - 1) / k;
        }
        st.clear();

        cout << res << endl; 
    }
}
