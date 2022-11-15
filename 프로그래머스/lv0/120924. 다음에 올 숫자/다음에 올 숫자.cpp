#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> common) {
    int answer = 0;
    int d = common[1]-common[0];
    double r =1;
    if(common[0]!=0) r = common[1]/common[0];
    cout<<r;
    bool flag = false;
    double temp=0;
    if(common[1]+d==common[2]) flag= true;
    if(flag==true){
        answer = common[common.size()-1]+d;
    }
    else {
        temp = common[common.size()-1]*r;
        answer = int(temp);
    }
    return answer;
}