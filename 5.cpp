/*Problem statement
A prime number is a positive integer that is divisible by exactly 2 integers, 1 and the number itself.



You are given a number 'n'.



Find out whether 'n' is prime or not.



Example :
Input: 'n' = 5

Output: YES
*/
// in un recursive manner ;
#include <bits/stdc++.h>
using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     int cnt;
//     for (int i=1; i*i<=n; i++){
//         if (n%i==0){
//             cnt++;
//             if(n/i!=i){
//                 cnt++;
//             }
//         }
//     }
//     if(cnt==2){
//         cout<< "TRUE"<<endl;
//     }else {
//         cout<<"false"<<endl;
//     }
// }

bool PrimeNumber(int n){
    int count =0;
    for(int i=1; i*i<=n;i++){
        if(n%i==0){
            count++;
            if(n/i!=i){
                count++;
            }
        }
    }
    if(count==2){
    return true;}
    else {
    return false;}

}
int main(){
    int n;
    cin>>n;
    cout<< boolalpha<< PrimeNumber(n)<<endl;
    return 0;
}
