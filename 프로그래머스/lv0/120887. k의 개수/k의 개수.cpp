#include <string>
#include <vector>

using namespace std;

int solution(int i, int j, int k) {
    int answer = 0;
    for(int x=i;x<=j;x++){
        string str_num;
        str_num = to_string(x);
        for(int y=0;y<str_num.length();y++){
        if(str_num[y]==k+'0') answer++;
        }
    }
    return answer;
}