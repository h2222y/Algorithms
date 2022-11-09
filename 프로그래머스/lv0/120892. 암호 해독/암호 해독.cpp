#include <string>
#include <vector>
using namespace std;

string solution(string cipher, int code) {
    string answer = "";
    int i=1;
    while(code*i<=cipher.length()){
        int index = code*i;
        answer.push_back(cipher[index-1]);
        i++;
    }
    return answer;
}