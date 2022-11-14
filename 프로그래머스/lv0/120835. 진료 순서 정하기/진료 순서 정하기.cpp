#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> emergency) {
    vector<int> temp = emergency;
    sort(temp.begin(),temp.end(),greater<int>());
    vector<int> answer;
    map<int,int> map1;
    int num = 1;
    for(int i=0;i<temp.size();i++){
        map1.insert({temp[i],i+1});
    }
    for(int i=0;i<emergency.size();i++){
    for(auto j:map1){
        if(j.first==emergency[i])
        answer.push_back(j.second);
    }
    }
    return answer;
}