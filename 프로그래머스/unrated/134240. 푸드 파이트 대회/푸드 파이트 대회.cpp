#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
    string answer;
    for(int i=1;i<food.size();i++){
        int cnt=0;
        cnt = food[i]/2;
        for(int j=0;j<cnt;j++){
            char food_num = i+'0';
            answer.push_back(food_num);
        }
    }
    answer.push_back('0');
    for(int i=food.size()-1;i>=1;i--){
        int cnt=0;
        cnt = food[i]/2;
        for(int j=0;j<cnt;j++){
            char food_num = i+'0';
            answer.push_back(food_num);
        }
    }
    return answer;
}