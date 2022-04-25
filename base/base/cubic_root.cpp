#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double n, eps = 1e-9, l = -100, r = 100;
    cin >> n;
    while(abs(l * l * l - n) > eps){
        double mid = (l + r) / 2;
        if(mid * mid * mid > n) r = mid;
        else l = mid;
    }
    printf("%0.6lf", l);
}

