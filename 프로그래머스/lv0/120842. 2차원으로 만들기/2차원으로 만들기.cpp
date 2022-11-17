#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    vector<vector<int>> answer;
    // int len = (num_list.size()-1)/n;
    for(int j=0;j<num_list.size();j+=n){
        vector<int> v={};
        for(int i=j;i<j+n;i++){
            if(j+n>num_list.size()) continue;
            v.push_back(num_list[i]);
        }
        answer.push_back(v);
    }    
    return answer;
}