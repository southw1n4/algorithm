#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    int n, res = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    cin >> n;
    while(n --){
       int a; 
       cin >> a;
       pq.push(a);
    }
    while(pq.size() > 1){
        int a = pq.top();pq.pop();
        int b = pq.top(); pq.pop();
        pq.push(a + b);
        res += a + b;
    }
    cout << res << endl;
    return 0;
    
}
