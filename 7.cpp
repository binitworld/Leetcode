/*58. Length of Last Word
Solved
Easy
Topics
Companies
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal 
substring
consisting of non-space characters only.*/
#include <bits/stdc++.h>
using namespace std;
int solution(const string& s) {
    int ans = 0;
    bool flag = false; 
    for(int i=s.length()-1;i>=0;i--){
        if (s[i]==' ' && flag == true){
            break;
        }else if(s[i]!=' '){
            flag=true;
            ans++;
        }
    }
    return ans;
}

int main() {
    string s;
    
    getline(cin, s);

    cout << solution(s) << endl;
    return 0;
}
