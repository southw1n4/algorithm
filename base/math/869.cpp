#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    while(n --) {
        int num;
        cin >> num;
        vector<int> res;
        for(int i = 1; i <= num / i; ++ i) {
            if(num % i == 0) {
                res.push_back(i);
                res.push_back(num / i);
            } 
        }

        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());

        for(int p : res) cout << p << " ";
        cout << endl;
    }

    return 0;
}
