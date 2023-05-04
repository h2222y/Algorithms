#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
int n;

int main(){
    int true_div_num;
    cin>>true_div_num;
    for(int i=0;i<true_div_num;i++){
        int true_divs;
        cin>>true_divs;
        v.push_back(true_divs);        
    }
    sort(v.begin(),v.end());
    cout<<v[0]*v[true_div_num-1];


    return 0; 
}