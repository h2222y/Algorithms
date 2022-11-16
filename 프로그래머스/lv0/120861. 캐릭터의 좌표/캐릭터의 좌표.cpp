#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer;
    int nx=0, ny=0;
    int max_xy[2]={};
    max_xy[0]= board[0]/2;
    max_xy[1] = board[1]/2;
    
    for(int i=0;i<keyinput.size();i++){
    if(keyinput[i]=="up"){
        ny += 1;
        if(ny>max_xy[1]) {
            ny-=1;
            continue;
        }
    }
    else if(keyinput[i]=="down"){
        ny -=1;
        if(ny<-1*max_xy[1]) {
            ny+=1;
            continue;
        }
    }
    else if(keyinput[i]=="right"){
        nx +=1;
        if(nx>max_xy[0]) {
            nx-=1;
            continue;
        }
    }
    else{
        nx -=1;
        if(nx<-1*max_xy[0]) {
            nx+=1;
            continue;
        }
    }
    }
    answer = {nx,ny};
    return answer;
}