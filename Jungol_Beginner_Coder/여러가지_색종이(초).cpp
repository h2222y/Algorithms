#include <iostream>
using namespace std;

int n; // 색종이의 개수
int map[100][100] = { 0 }; // 하얀 도화지

void check(int sy, int sx ) { //y의 시작점과 x의 시작점을 입력받는다
	for (int y = sy; y < sy + 10; y++) { 
		for (int x = sx; x < sx + 10; x++) {
			map[y][x] = 1; // 시작점으로부터 열칸씩 1로 채워주면 검은 네모를 만들 수 있다.
		}
	}
}

int main() {
	cin >> n; //색종이의 수를 입력받고
	int cnt = 0;
	for (int i = 0; i < n; i++) { // 색종이의 수만큼 각각 x,y의 시작 좌표를 입력받는다.
		int y, x;
		cin >> x >> y;
		check(y, x); //좌표를 입력받을 때마다 도화지에 표시해준다.
	}

	for (int y = 0; y < 100; y++) {
		for (int x = 0; x < 100; x++) {
			if (map[y][x] == 1) cnt++; //도화지에서 0이면 흰색 1이면 검은색이니, 검은색의 개수만 세면 넓이를 구할 수 있다.
		}
	}
	cout << cnt; //개수를 출력하면 넓이와 같다. 
	
	return 0;

}