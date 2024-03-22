#include <bits/stdc++.h>
using namespace std;

int SumOfAllDivisor(int n){
    int sum=0;
    for (int i=1; i<=n ;i++){
        if (n%i == 0){
            sum+=i;
        }if(i != n/i && i != 1){
            sum+=n/i;
        }
    }
    return sum;
}
int main(){
    int n;
    cin>>n;
    cout<<SumOfAllDivisor(n)<<endl;
    return 0;
}