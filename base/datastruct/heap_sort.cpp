#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int heap[N];
int h2c[N], c2h[N];
int n, m, cnt;


void push_down(int k){
    int t = k;
    if(k * 2 <= m && heap[k * 2] < heap[k]) t = 2 * k;
    if(k * 2 + 1 <= m && heap[k * 2 + 1] < heap[t]) t = 2 * k + 1;
    if(t != k){
        swap(heap[k], heap[t]);
        c2h[h2c[k]] = t, c2h[h2c[t]] = k;
        swap(h2c[k], h2c[t]);

        push_down(t);
    }
}

void push_up(int k){
    if(k == 1) return ;

    int t = k / 2;
    if(heap[t] > heap[k]){
        swap(heap[k], heap[t]);
        c2h[h2c[k]] = t, c2h[h2c[t]] = k;
        swap(h2c[k], h2c[t]);
        
        push_up(t);
        push_down(k);
    }
}

int main(){
    cin >> n; 
    for(int i = 1; i <= n; ++ i){
        string op;
        int x, k;
        cin >> op;
        if (op == "I"){
            cin >> x;
            heap[++ m] = x; 
            h2c[m] = ++ cnt;
            c2h[cnt] = m;
            push_up(m);

        }else if (op == "PM") {
            cout << heap[1] << endl;
        }else if (op == "DM") {
            heap[1] = heap[m];
            c2h[h2c[m]] = 1;
            h2c[1] = h2c[m --];
            push_down(1);
        }else if (op == "D") {
            cin >> k;
            int t = c2h[k];
            heap[t] = heap[m];
            c2h[h2c[m]] = t;
            h2c[t] = h2c[m --];
            push_up(t);
            push_down(t);
        }else{
            cin >> k >> x;
            int t = c2h[k];
            heap[t] = x;
            push_up(t);
            push_down(t);
        }
    }

}

