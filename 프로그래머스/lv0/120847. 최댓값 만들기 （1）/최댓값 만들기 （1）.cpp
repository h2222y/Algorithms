#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<int> numbers) {
    int answer = -9999;
    for(int i=0;i<numbers.size();i++){
        for(int j=i+1;j<numbers.size();j++){
            answer = max(answer,numbers[i]*numbers[j]);
        }
    }
    return answer;
}