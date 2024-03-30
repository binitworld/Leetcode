#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;

        if (n >= k) {
            cout << (k == 1 || k % n == 0 ? 1 : 2) << endl;
        } else {
            cout << (k + n - 1) / n << endl;
        }
    }
    return 0;
}
