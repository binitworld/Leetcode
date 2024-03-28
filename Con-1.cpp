/*r
E. Nearly Shortest Repeating Substring
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given a string s
 of length n
 consisting of lowercase Latin characters. Find the length of the shortest string k
 such that several (possibly one) copies of k
 can be concatenated together to form a string with the same length as s
 and, at most, one different character.

More formally, find the length of the shortest string k
 such that c=k+⋯+kx times
 for some positive integer x
, strings s
 and c
 has the same length and ci≠si
 for at most one i
 (i.e. there exist 0
 or 1
 such positions).

Input
The first line contains a single integer t
 (1≤t≤103
) — the number of test cases.

The first line of each test case contains a single integer n
 (1≤n≤2⋅105
) — the length of string s
.

The second line of each test case contains the string s
, consisting of lowercase Latin characters.

The sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, print the length of the shortest string k
 satisfying the constraints in the statement.*/


#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Function to find the length of the shortest repeating substring
int shortest_repeating_substring(string s) {
    int n = s.length();
    vector<int> prefix(n, 0);
    int j = 0;
    for (int i = 1; i < n; ++i) {
        while (j > 0 && s[i] != s[j])
            j = prefix[j - 1];
        if (s[i] == s[j])
            ++j;
        prefix[i] = j;
    }
    int len = n - prefix[n - 1];
    if (n % len == 0)
        return len;
    else
        return n;
}

int main() {
    int t;
    cin >> t; // Read the number of test cases

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n; // Read the length of string s
        string s;
        cin >> s; // Read the string s

        cout << shortest_repeating_substring(s) << endl;
    }

    return 0;
}
