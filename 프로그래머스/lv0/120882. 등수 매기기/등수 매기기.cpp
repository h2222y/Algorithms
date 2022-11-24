#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<vector<int>> score) {
    vector<int> avgs;
    vector<int> answer;
    vector<int> avg;
    
    for(int i=0;i<score.size();i++){
        avg.push_back(score[i][0]+score[i][1]);
    }
    
    for(int i=0;i<avg.size();i++){
        int rank=1;
        for(int j=0;j<avg.size();j++){
            if(avg[i]<avg[j]) rank++;
        }
            answer.push_back(rank);
    }
    
    
    return answer;
}