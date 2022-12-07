#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long int a,b,c;
    cin>>a>>b>>c;
    long long int sum= a+b;
    if(sum>=c*2) cout<<sum-(c*2);
    else cout<<sum;
    return 0;
}