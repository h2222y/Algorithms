#include <iostream>
using namespace std;

int n; //색종이 개수
int map[101][101] = { 0 }; // 하얀 도화지 0의 개수를 셀거니까 크기 넉넉하게 만들어 주기

void Draw(int sy, int sx) { // 검은 사각형을 그려줄 함수
	for (int y = sy; y < sy + 10; y++) {
		for (int x = sx; x < sx + 10; x++) {
			map[y][x] = 1; //검은 사각형은 크기가 10x10으로 고정, 시작값을 입력받아서 그리기
		}
	}
}

int Check(int y, int x) { //둘레를 세어줄 함수
	int direct_y[4] = {-1,+1,0,0}; //도화지에서 1로 표시된 부분의 상하좌우를 확인한다. y의 방향배열
	int direct_x[4] = { 0,0,-1,+1 }; // x의 방향배열
	int cnt = 0; //0의 갯수를 세어서 확인할 것이다. 1 주변에 0이 있으면 세고, 1이면 세지 않는다. (둘레를 계산하는 방법)
	int dx, dy;
	for (int t = 0; t < 4; t++) {
		dy = y + direct_y[t]; // 방향배열을 반복하며 상하좌우를 확인한다.
		dx = x + direct_x[t]; 
		if (map[dy][dx] == 0) cnt++; //1 주변이 0이면 갯수를 세어준다.
	}
	return cnt;
}

int main() {
	cin >> n;
	int ret,sum=0;
	for (int i = 0; i < n; i++) {
		int x,y;
		cin >> x >> y;
		Draw(y, x); //사각형 그리기
	}
	for (int y = 0; y < 100; y++) {
		for (int x = 0; x < 100; x++) {
			if (map[y][x] == 1) {
				ret = Check(y, x); // 1일때 각 좌표의 상하좌우를 확인해서 0의 개수를 반환
				sum += ret; // 리턴값을 누적해서 둘레의 합을 구한다. 
			}
		}
	}
	cout << sum; //둘레값 게산
	return 0;
}