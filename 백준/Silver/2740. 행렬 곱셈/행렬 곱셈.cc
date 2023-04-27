#include <iostream>
using namespace std;

int A[101][101];
int B[101][101];
int MUL[101][101];

int main(){
    int n,m,k;
    cin>>n>>m;
    for(int y=0;y<n;y++){
        for(int x=0;x<m;x++){
            cin>>A[y][x]; // nxm 배열 입력
        }
    }

    cin>>m>>k;

    for(int y=0;y<m;y++){
        for(int x=0;x<k;x++){
            cin>>B[y][x]; // mxk 배열 입력
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){ // nxm * mxk = nxk 배열
            for(int z=0;z<m;z++){
                MUL[i][j]+= A[i][z]*B[z][j]; // 합해서 배열에 담기
            }
            cout<<MUL[i][j]<<" ";
        }
        cout<<"\n";
    }


    return 0; 
}