#include <string>
#include <vector>

using namespace std;

int solution(int hp) {
    int answer = 0;
    int rest =hp;
    while(rest>0){
        if(rest>=5){
            answer += rest/5;
            rest = rest%5;
        }
        else if(rest>=3){
            answer += rest/3;
            rest = rest%3;
        }
        else if(rest>=1){
            answer +=rest/1;
            rest = rest%1;
        }
    }
    return answer;
}