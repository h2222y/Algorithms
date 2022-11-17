#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> numbers, int k) {
    int cnt=1;
    int i=0;
    int len = numbers.size();
    while(1){
        if(len%2==0 && i==len-2) {
            i=0;
            cnt++;
            if (k == cnt) return numbers[i];
        }
        if(len%2!=0){  
            if(i==len-1 && i!=0){
            i = 1;
            cnt++;
            if (k == cnt) return numbers[i];
            }
            if (i == len-2 && i!=0) {
                i = 0;
                cnt++;
            if (k == cnt) return numbers[i];

            }
        }
        i+=2;
        cnt++;
        if(k==cnt) return numbers[i];
    }
    //return answer;
}