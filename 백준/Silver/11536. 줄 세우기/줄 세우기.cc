#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

char names[20][13];
bool increase = true, decrease = true;

int main(){
    int n;
    cin>>n;
    cin>>names[0];
    for(int i=1;i<n;i++){
        cin>>names[i];
        int comp = strcmp(names[i-1],names[i]);
        if(comp>0)
            increase = false;
        else if(comp<0)
            decrease = false;
    }
    if(increase)
        cout<<"INCREASING";
    else if(decrease)
        cout<<"DECREASING";
    else
        cout<<"NEITHER";
    
    return 0; 
}