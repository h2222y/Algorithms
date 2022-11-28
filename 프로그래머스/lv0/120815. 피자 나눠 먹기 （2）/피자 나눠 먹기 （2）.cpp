#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    for(int i=1;i<=100;i++){
        int pizza=6;
        if((pizza*i)%n==0) return i;
    }
    //return answer;
}