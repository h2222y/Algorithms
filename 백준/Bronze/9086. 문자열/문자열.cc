#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--){
        string str;
        cin>>str;
        cout<<str[0];
        cout<<str[str.length()-1];
        cout<<"\n";
    }
    return 0;
}