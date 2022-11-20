#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(vector<vector<int>> dots) {
    int answer = 0;
    int height=0;
    int width=0;
    for(int x=0;x<4;x++){
        for(int y=x+1;y<4;y++){
        if(dots[x][0]==dots[y][0]){
            height= abs(dots[x][1]-dots[y][1]);
            break;
        }
        if(dots[x][1]==dots[x][1]){
            width = abs(dots[x][0]-dots[y][0]);
            break;    
        }
            }
    }
    answer= height*width;
    return answer;
}