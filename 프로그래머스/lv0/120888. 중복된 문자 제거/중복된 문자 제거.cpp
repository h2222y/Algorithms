#include <string>
#include <vector>

using namespace std;
int dat[300];

string solution(string my_string) {
    string answer = "";
    for(int i=0;i<my_string.length();i++){
        bool flag = false;
        for(int j=0;j<answer.length();j++){
            if(answer[j]==my_string[i]) {
                flag=true;
                break;
            }
        }
            if(flag==false)answer.push_back(my_string[i]);

    }
    return answer;
}