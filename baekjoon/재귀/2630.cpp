#include <iostream>
using namespace std;

int paper[200][200];
int cnt[2];
bool check(int x,int y,int n) {
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (paper[x][y] != paper[i][j]) return false; // 하나라도 다르면 false 
		}
	}
	return true; // 모두 같은 경우 true
}

void recur(int x, int y, int n) {
	if (check(x, y, n)) { // 배열이 모두 같은 숫자로 이루어져 있는지 확인
		cnt[paper[x][y]] ++; // true면 모두 같은 경우므로 cnt[0|1]++;
		return;
	}
	int k = n / 2; // 2로 나눠주면 4등분 가능 x,y 모두 4으로 나눈 범위이므로 
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			recur(x + i * k, y + j * k, k); // 시작 좌표를 보내준다. 
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			cin >> paper[x][y]; // 배열에 숫자 입력받기
		}
	}
	recur(0, 0, n);
	for (int i = 0; i < 2; i++)
		cout << cnt[i]<<"\n"; // cnt 출력
}