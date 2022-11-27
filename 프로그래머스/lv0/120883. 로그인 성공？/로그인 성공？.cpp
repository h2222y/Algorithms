#include <string>
#include <vector>
using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db) {
    string answer = "";
    for(int x=0;x<db.size();x++){
        if(db[x][0]==id_pw[0] &&db[x][1]==id_pw[1]) {
            answer="login";
            break;
        }
        else if(db[x][0]==id_pw[0] && db[x][1]!=id_pw[1]) {
            answer="wrong pw";
            break;
        }
        else {
            answer="fail";
        }
    }
    return answer;
}