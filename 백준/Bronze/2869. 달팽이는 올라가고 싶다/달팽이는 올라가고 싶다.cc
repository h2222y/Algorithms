#include <iostream>
using namespace std;

int main(){
    int a,b,v;
    cin>>a>>b>>v; // climb Am, fall Bm, height_goal Vm
    int days=1; // 1일에서 시작
    days += (v-a)/(a-b); // 정상에 다다르기만 하면 자는동안 미끄러지지 않기 때문에, v-a를 올라가는 m만큼으로 나눠줘서 날짜를 추가해준다. 
    if((v-a)%(a-b)!=0) // 만약 나누어 떨어지지 않는다면 
        days++; // 하루 추가 
    if(a==v) // 만약 정상과 a 값이 같다면 
        cout<<"1"; // 1일 출력 
    else
        cout<<days;
    return 0; 

}