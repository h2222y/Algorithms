#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int> > v;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        v.push_back(pair<int,int>(y,x));
    }
    sort(v.begin(),v.end());

    for(int i=0;i<v.size();i++){
        cout<<v[i].second<<" "<<v[i].first<<"\n";
    }
    return 0; 
}