#include <string>
#include <vector>

using namespace std;

string solution(string letter) {
    string answer = "";
    vector<string> morse = { 
    ".-","-...","-.-.","-..",".","..-.",
    "--.","....","..",".---","-.-",".-..",
    "--","-.","---",".--.","--.-",".-.",
    "...","-","..-","...-",".--","-..-",
    "-.--","--.."};
    
    int first=0;
    int second=0;
    
    while (1) {
        second = letter.find(' ',first);
        string temp;
        if (second == -1) {
            for (int i = first; i < letter.length(); i++) {
                temp += letter[i];
            }
            for (int i = 0; i < morse.size(); i++) {
                if (temp == morse[i]) {
                    answer += i + 'a';
                    break;
                }
            }
            break;
        }
        for (int i = first; i < second; i++) {
            temp += letter[i];
        }
        for (int i = 0; i < morse.size(); i++) {
            if (temp == morse[i]) {
                answer += i + 'a';
                break;
            }
        }
        first = second+1;
    }

    return answer;
}