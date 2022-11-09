#include <string>
#include <vector>

using namespace std;

int solution(int n, int k) {
    int answer = 0;
    //int sheep=0, beverage=0;
    int sheep = 12000*n;
    if(sheep>=10){
      k = k - n/10;  
    }
    int beverage = 2000*k;

    answer = sheep+beverage;
    return answer;
}