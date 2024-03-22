// Given an integer x, return true if x is a palindrome, and false otherwise.
#include<bits/stdc++.h>
using namespace std;
bool PalindromeNum(int n){
    int dup =n;
    int rev=0;
    if(n<0||(n/10==0&&n!=0))
    return false;
    while(n!=0){
        int Ldigit=n%10;
        n/=10;
        rev=(rev*10)+Ldigit;
    }
    return dup==rev;
}
int main(){
    int n;
    cin>>n;
    cout<< boolalpha << PalindromeNum(n)<<endl;
    return 0;
}