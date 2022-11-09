#include <string>
#include <vector>

using namespace std;

int solution(int order) {
    int answer = 0;
    string num_str = to_string(order);
    for(int i=0;i<num_str.length();i++){
    if(num_str[i]=='3'||num_str[i]=='6'||num_str[i]=='9')
        answer++;
    }
    return answer;
}