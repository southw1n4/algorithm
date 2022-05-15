#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    while (n --) {
        int num;
        cin >> num;
        string flag = "Yes";

        for (int i = 2; i <= num / i; ++ i) {
            if (num % i == 0) {
                flag = "No";
                break;
            }
        }
        if (num == 1) flag = "No";

        cout << flag << endl;
    }

    return 0;
}
