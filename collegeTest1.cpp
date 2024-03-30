#include<bits/stdc++.h>
using namespace std;

long long AbsoluteDiff(long long A, long long B) {
        
        long long firstEven = A % 2 == 0 ? A : A + 1;
        long long firstOdd = A % 2 != 0 ? A : A + 1;

        
        long long totalEven = 0, totalOdd = 0;
        if (A % 2 == 0) {
                totalEven = ((B - A) / 2) + 1;
                totalOdd = (B - A + 1) / 2;
        } else {
                totalEven = (B - A + 1) / 2;
                totalOdd = ((B - A) / 2) + 1;
        }

        
        long long sumEven = (totalEven * (firstEven + (firstEven + (totalEven - 1) * 2))) / 2;
        
        long long sumOdd = (totalOdd * (firstOdd + (firstOdd + (totalOdd - 1) * 2))) / 2;

        
        long long absoluteDifference = abs(sumEven - sumOdd);

        return absoluteDifference;
}

int main() {
        long long A, B;
        cin >> A >> B;
        
        cout << AbsoluteDiff(A, B) << endl;
        
        return 0;
}
