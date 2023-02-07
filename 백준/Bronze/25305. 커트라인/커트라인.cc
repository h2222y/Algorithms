#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> arr;
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int score;
        cin>>score;
        arr.push_back(score);
    }
    sort(arr.begin(),arr.end(),greater<>());
    cout<<arr[k-1];

    return 0;
}