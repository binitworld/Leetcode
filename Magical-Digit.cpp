#include <bitset>
#include <algorithm>
#include <vector>

long long count(int n, vector<int>& needed) {
    long long sum = 0;
    for (int i : needed) {
        sum += i;
    }

    int remaining = 10 - needed.size(), extra = n - sum;
    if (extra < 0) {
        return 0;
    }

    vector<long long> fact(1, 1);
    for (int i = 1; i <= 9; i++) {
        fact.push_back(fact.back() * i);
    }

    long long ans = fact[sum];
    for (int i : needed) {
        ans /= fact[i];
    }

    ans *= (fact[n] / (fact[extra] * fact[n - extra]));

    for (int i = 0; i < extra; i++) {
        ans *= remaining;
    }

    return ans;
}

void fillAnyDigits(vector<long long>& mask, vector<int>& a, int start, int end, int digitsAvailable) {
    for (int i = start; i <= end; i++) {
        a[i]--;
        for (int j = 0; j < (int)mask.size(); j++) {
            bitset<10> bit = j;
            vector<int> needed;
            int sum = 0;
            bool ok = true;

            for (int k = 0; k < 10; k++) {
                if (bit[k]) {
                    if (a[k] < 0) {
                        ok = false;
                        break;
                    }
                    sum += a[k];
                    if (sum > digitsAvailable) {
                        ok = false;
                        break;
                    }
                    needed.push_back(a[k]);
                }
            }

            if (!ok) {
                continue;
            }

            long long z = count(digitsAvailable, needed);
            mask[j] += z;
        }

        a[i]++;
    }
}

void leadingZeros(vector<long long>& mask, vector<int>& digits, vector<int>& a) {
    int nd = digits.size();
    for (int i = 1; i < nd; i++) {
        fillAnyDigits(mask, a, 1, 9, nd - i - 1);
    }
}

long long magical0ToN(long long n, vector<int> a) {
    vector<long long> mask(1 << 10);

    int nCpy = n;
    vector<int> digits;
    while (nCpy > 0) {
        digits.push_back(nCpy % 10);
        nCpy /= 10;
    }
    reverse(digits.begin(), digits.end());

    leadingZeros(mask, digits, a);

    int nd = digits.size();
    for (int i = 0; i < nd; i++) {
        fillAnyDigits(mask, a, (i == 0), digits[i] - (i != nd - 1), nd - i - 1);
        a[digits[i]]--;
    }

    long long ans = 0;
    for (int i = 1; i < (int)mask.size(); i++) {
        int setBits = __builtin_popcount(i);
        if (setBits & 1) {
            ans += mask[i];
        } else {
            ans -= mask[i];
        }
    }

    return ans;
}

long long nonMagicalNumbers(long long l, long long r, vector<int>& a) {
    return r - l + 1 - (magical0ToN(r, a) - magical0ToN(l - 1, a));
}