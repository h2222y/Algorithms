#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int balls, int share) {
    int answer;
    double factory=1;
    double pick=1;
    double select =1 ;
    if(balls==share){
        return 1;
    }
    
    for(int i=balls;i>=1;i--){
        factory *=i;
    }
    
    for(int i=balls-share;i>=1;i--){
        pick *=i;
    }
    for(int i=share;i>=1;i--){
        select *=i;
    }
    answer = round(factory/(pick*select));
    return answer;
    //return answer;
}