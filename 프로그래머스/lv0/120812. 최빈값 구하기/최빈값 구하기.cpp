#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    int dat[1001]={};
    int max=-9999;
    int temp_idx=-1;
    int cnt=0;
    
    for(int i=0;i<array.size();i++){
        dat[array[i]]++;
    }
    
    for(int i=0;i<1001;i++){
        if(dat[i]>0 && dat[i]>max){
            max = dat[i];
            temp_idx=i;
        }
    }
    
    for(int i=0;i<1001;i++){
        if(dat[i]==max) cnt++;
    }
    
    if(cnt>1) return -1;
    return temp_idx;
}