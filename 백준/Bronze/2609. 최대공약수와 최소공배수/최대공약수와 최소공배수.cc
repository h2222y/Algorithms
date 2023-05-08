#include <iostream>
using namespace std;

int Gcd(int a, int b){
    int rest = a%b;
    if(rest==0) return b;
    return Gcd(b,rest);
}

int main(){
    int a,b;
    cin>>a>>b;
    int gcd = Gcd(a,b);
    cout<<gcd<<"\n";
    cout<<(a*b)/gcd;

    return 0;
}