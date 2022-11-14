#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    int dat[300]={};
    for(int i=0;i<s.length();i++){
        dat[s[i]]++;    
    }
    for(int i=60;i<250;i++){
        if(dat[i]==1) answer += i;
    }
    sort(answer.begin(),answer.end());
    return answer;
}