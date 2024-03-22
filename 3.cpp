/*Checking armstrong number or not  */
#include <bits/stdc++.h>
using namespace std;
bool Armstrong(int n){
    int sum =0;
    int count =0;
    int dup = n;
    while(dup != 0){
        dup /=10;
        count++;
    } 
    dup = n;
    while (n!=0){
        int Ldigit = n % 10 ;
        n/=10;
        sum = sum + pow(Ldigit , count);
    }
    if (sum == dup ){
        return true;

    }
    else {
        return false;
    }
}
int main(){
    int n;
    cin>>n;
    cout<<boolalpha<<Armstrong(n)<<endl;
    return 0;
}