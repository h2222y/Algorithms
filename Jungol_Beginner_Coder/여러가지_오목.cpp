#include <iostream>
using namespace std;
int map[20][20] = { 0 }; //오목판 그리기
// 기본적으로 맨 왼쪽의 x,y 좌표를 출력할 것이기 때문에 8방향 모두 검사할 필요 없이
// 중복되는 부분 제외하고 4부분만 검사해주면 된다.

int Garo(int sy,int sx) { //가로 검사 코드
	if (map[sy][sx - 1] == map[sy][sx] || map[sy][sx]==map[sy][sx+5]) return 0; // 6목이면 안되기 때문에 해당 좌표 왼쪽과 6칸 뒤 확인
	for (int i = 1; i <= 4; i++) { //4씩 더해주면서
		if (sx + i > 19) return 0; // 범위 벗어나면 바로 종료
		if (map[sy][sx] != map[sy][sx + i]) return 0; //같지 않으면 바로 종료
	} 
	return 1; //모두 해당되지 않으면 1 리턴
}
int Sero(int sy, int sx) { //세로 검사 코드
	if (map[sy-1][sx] == map[sy][sx] || map[sy][sx] == map[sy+5][sx]) return 0;
	for (int i = 1; i <= 4; i++) {
		if (sy + i > 19) return 0;
		if (map[sy][sx] != map[sy+i][sx]) return 0;
	}
	return 1;
}
int Up_Diag(int sy, int sx) { // 위로 올라가는 대각선 확인
	if (map[sy+1][sx - 1] == map[sy][sx] || map[sy][sx] == map[sy - 5][sx + 5]) return 0;
	for (int i = 1; i <= 4; i++) {
		if (sx + i > 19 || sy - i <= 0 ) return 0;
		if (map[sy][sx] != map[sy - i][sx + i]) return 0;
	}
	return 1;
}
int Down_Diag(int sy, int sx) { //아래로 내려가는 대각선 확인
	if (map[sy-1][sx - 1] == map[sy][sx] || map[sy][sx] == map[sy + 5][sx + 5]) return 0;
	for (int i = 1; i <= 4; i++) {
		if (sx + i > 19 || sy +i > 19) return 0;
		if (map[sy][sx] != map[sy+i][sx + i]) return 0;
	}
	return 1;
}
int main() {
	int ret1=0, ret2=0, ret3=0, ret4=0; // 각각 함수의 리턴값을 받아준다
	int ans_y, ans_x, ans_val; // 최종 y,x값 출력과 누가 이겼는지 출력해주기 위함. 
	for (int y = 1; y <= 19; y++) {
		for (int x = 1; x <= 19; x++) {
			cin >> map[y][x]; // 오목 좌표 입력받기
		}
	}
	for (int y = 1; y <= 19; y++) {
		for (int x = 1; x <= 19; x++) {
			if (map[y][x] == 1 || map[y][x] == 2) { // 해당 돌이 1이면 검정, 2면 하양 돌, 0이면 아무돌도 없는거라 검사안함
				ret1=Garo(y, x); //가로 검사
				ret2=Sero(y, x); //세로 검사
				ret3=Up_Diag(y, x); //대각 검사
				ret4=Down_Diag(y, x);
			}
			if (ret1==1 || ret2==1 || ret3==1 || ret4==1) { // 위 함수 검사 결과 하나라도 1이 리턴되면 우승자 생긴다. 
				ans_y = y; //우승시 보냈던 y좌표
				ans_x = x; //x좌표 저장해주고
				ans_val = map[y][x]; // 어떤 돌이 우승했는지 저장해준다. 
				break;
			}
		}
		if (ret1==1 || ret2==1 || ret3==1 || ret4==1) break;
	}
	if (ret1 == 1 || ret2 == 1 || ret3 == 1 || ret4 == 1) {
		cout << ans_val << endl; //출력
		cout << ans_y << " " << ans_x << endl;
	}
	else cout << 0;
	return 0; 

}