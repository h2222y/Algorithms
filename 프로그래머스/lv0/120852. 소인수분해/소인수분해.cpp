#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<int> temp;
    
    for(int i=2;i<=10000;i++){
        if(n%i==0){
            while(n%i==0){
                n/=i;
            }
            temp.push_back(i);
        }
    }
    return temp;
}