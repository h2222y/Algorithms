#include <iostream>
#include <vector>
using namespace std;
vector<int> arr;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--){
        int n; 
        cin>>n;
        fill(arr.begin(),arr.end(),0);
        for(int i=0;i<n;i++){
            int num;
            cin>>num;
            arr.push_back(num);
        }
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum +=arr[i];
        }
        cout<<sum<<"\n";
    }
    return 0;
}