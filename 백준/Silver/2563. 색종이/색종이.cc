#include <iostream>
using namespace std;

int paper[100][100];

int main(){
    int n;
    cin>>n; // 색종이 개수 입력
    int x,y; // 색종이의 좌측 끝 (x,y) 입력
    int width=0; // 넓이 카운트
    while(n--){ // n만큼
        cin>>x>>y; // 입력
        for(int j=y;j<y+10;j++){ // 색종이의 넓이는 10x10 고정
            for(int i=x;i<x+10;i++){
                if(!paper[j][i]){ // 좌표에 해당하는 값이 1이 아니라면
                    width++; // 넓이에 포함
                    paper[j][i]=1; // 1로 마킹
                }
            }
        }
    }
    cout<<width<<endl;
    return 0; 
}