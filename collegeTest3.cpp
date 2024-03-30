#include <iostream>
#include <unordered_set>
using namespace std;

bool isExpressibleAsSumOfCubes(long long x) {
    unordered_set<long long> cubes;
    
    
    for (long long i = 1; i * i * i <= x; ++i) {
        cubes.insert(i * i * i);
    }
    
    
    for (long long i = 1; i * i * i < x; ++i) {
        long long b_cubed = x - i * i * i;
        if (cubes.find(b_cubed) != cubes.end()) {
            return true;
        }
    }
    
    return false; 
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long x;
        cin >> x;
        
        if (isExpressibleAsSumOfCubes(x)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
