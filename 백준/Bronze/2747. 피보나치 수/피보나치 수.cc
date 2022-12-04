#include <iostream>
using namespace std;
unsigned long long fib[46]={};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin>>n;
    fib[0]=0;
    fib[1]=1;
    for(int i=2;i<=n;i++){
        fib[i]=fib[i-2]+fib[i-1];
    }
    cout<<fib[n];
   
    return 0; 
}