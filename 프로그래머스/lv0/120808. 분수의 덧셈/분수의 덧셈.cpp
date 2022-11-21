#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int denum1, int num1, int denum2, int num2) {
    vector<int> answer;
    int cal_denum1= denum1*num2;
    int cal_m = num1*num2;
    int cal_denum2 = denum2*num1;
    int temp_ans = cal_denum1+cal_denum2;
    for(int i=1000;i>=1;i--){
        if(temp_ans%i==0 && cal_m%i==0){
            temp_ans /=i;
            cal_m /=i;
        }
    }
    answer.push_back(temp_ans);
    answer.push_back(cal_m);
    return answer;
}