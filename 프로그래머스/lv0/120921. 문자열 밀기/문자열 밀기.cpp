#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string A, string B) {
    int cnt=0;
    while(1){
        if(cnt==A.length()) return -1;
        if(A==B){
            return cnt;
        }
        for(int i=A.length()-1;i>0;i--){
            char temp;
            temp = A[i];
            A[i]=A[i-1];
            A[i-1]=temp;
        }
        cnt++;
        cout<<A<<"\n";

    }
}