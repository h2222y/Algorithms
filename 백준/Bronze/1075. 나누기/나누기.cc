#include <iostream>
#include <string>
using namespace std;

int main(){
    int n,f;
    cin>>n>>f;
    string num = to_string(n);
    int idx = num.length();
    // cout<<idx;
    string last = "00";
    num[idx-2] = '0';
    num[idx-1] = '0';
    int new_num = stoi(num);
    // cout<<new_num;
    while(1){
        if(new_num%f==0) {
            cout<<last;
            break;
        }
        else {
            last[1]++;
            if(last[1]>'9') {
                last[0]++;
                last[1]='0';
            }
            num[idx-2]=last[0];
            num[idx-1]=last[1];
            new_num = stoi(num);
        }
    }
    return 0; 
}