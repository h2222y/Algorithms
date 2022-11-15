#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
    int i = 10;
    
    while (1) {
        int temp = 1;

        for (int j = i; j >= 1; j--) {
            temp *= j;
            if (temp > n) break;
        }
        if (temp == n) return i;
        if(temp<n) return i; // 이하의 최대 팩토리얼 
        i--;
    }
    // return answer;
}