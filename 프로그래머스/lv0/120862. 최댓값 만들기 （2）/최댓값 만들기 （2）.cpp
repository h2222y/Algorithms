#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> numbers) {
    int answer = -99999999999999;
    for(int i=0;i<numbers.size();i++){
        for(int j=i+1;j<numbers.size();j++){
            int mul = numbers[i]*numbers[j];
            answer = max(answer,mul);
        }
    }
    return answer;
}