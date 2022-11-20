#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<string> solution(string my_str, int n) {
    vector<string> answer;
    int a=0;
    while(1){
        if(a>=my_str.length())break;
        string temp;
        temp = my_str.substr(a,n);
        answer.push_back(temp);
        a=a+n;
    }
    
    return answer;
}