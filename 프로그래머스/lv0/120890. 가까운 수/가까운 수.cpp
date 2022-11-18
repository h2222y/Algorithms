#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int solution(vector<int> array, int n) {
    int answer = 0;
    int min_val=999999999;
    int idx=0;
    sort(array.begin(),array.end());
    for(int i=0;i<array.size();i++){
        if(abs(array[i]-n)<min_val){
            min_val=abs(array[i]-n);
            idx = i;
        }
    }
    return array[idx];
}