#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int> > v; // nxn 좌표 입력 받을 벡터
int n; // 좌표 개수

int main(){
    cin>>n; // 개수 입력
    for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y; // 개수만큼 x,y 값 입력
            v.push_back(pair<int,int>(x,y)); // 벡터에 담는다 
    }

    sort(v.begin(),v.end()); // 벡터 정렬 iterator 기준 앞의 key를 기준으로 정렬, 즉 x값 기준 정렬 

    for(int i=0;i<v.size();i++){ // 벡터의 크기만큼
            cout<<v[i].first <<" "<< v[i].second; // 두 개의 pair 값 출력
            cout<<"\n";
    }
    return 0; 

}