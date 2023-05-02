#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> v;

int main(){
    int n;
    cin>>n; // 입력받을 숫자의 개수 입력

    for(int i=0;i<n;i++){ // 입력 받을 숫자의 개수만큼
        int num;
        cin>>num; // 숫자 입력
        v.push_back(num);
    }
    sort(v.begin(),v.end()); // 정렬 (오름차순)
    v.erase(unique(v.begin(),v.end()),v.end()); // 중복 원소 제거
    for(int i=0;i<v.size();i++){ 
        cout<<v[i]<<" "; // 출력
    }
    return 0; 
}