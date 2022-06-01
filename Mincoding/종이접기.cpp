#include <iostream>
using namespace std;
// 가로나 세로의 길이가 짝수일때 종이를 반으로 접는다.
// 종이의 가로, 세로 길이가 모두 홀수면 종료
// 세로 가로 중 한 개의 길이가 짝수면 짝수인 부분 접기
// 둘 다 짝수면 큰 수 접기
// 둘 다 짝수고 길이가 같으면 가로 먼저 접기
// 종이를 접으면 각 칸의 숫자가 더해진다

int paper[210][210] = { 0 }; //종이 접기할 배열
int n, m; // 세로의 길이 가로의 길이

void isMax(int n, int m) { // 종이를 접은 후 최대값을 찾는다
	int max = -99999;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			if (paper[y][x] > max) max = paper[y][x];
		}
	}
	cout << max << " ";

}
void isMin(int n, int m) { // 종이를 접은 후 최소값을 찾는다
	int min = 1000000;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			if (paper[y][x] < min) min = paper[y][x];
		}
	}
	cout << min << " " << endl;
}

void foldGaro() {// 종이를 가로로 접을 경우
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m / 2; x++) {
			paper[y][x] = paper[y][x] + paper[y][m - 1 - x];
		}
	}
	isMax(n, m / 2);
	isMin(n, m / 2);
}

void foldSero() { // 종이를 세로로 접을 경우
	for (int x = 0; x < m; x++) {
		for (int y = 0; y < n / 2; y++) {
			paper[y][x] = paper[y][x] + paper[n - 1 - y][x];
		}
	}
	isMax(n / 2, m);
	isMin(n / 2, m);
}


int main() {
	cin >> n >> m;
	int cnt = 0;// 몇 번 접었는지 확인하기 위해 카운트 값을 먼저 출력
	int N = n, M = m;  // 카운트 값을 출력하고 다시 접기 위해서 백업

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			cin >> paper[y][x]; // 종이에 입력되어 있는 값 적기
		}
	}

	while (1) { // 몇 번 접는지 확인하기 위한 반복문
		if (m % 2 != 0 && n % 2 != 0) break; //둘다 홀수면 종료
		cnt++;

		if (m % 2 == 0) { //가로가 짝수일때
			if (n % 2 == 0) { //세로도 짝수이면
				if (m >= n) {
					m /= 2;
				}
				else {
					n /= 2;
				}
			}
			else {
				m /= 2;
			}
		}
		else if (n % 2 == 0) {
			n /= 2;
		}
	}

	cout << cnt << endl; //카운트 값 출력
	n = N; // 백업 값 다시 올리기
	m = M;

	while (1) {
		if (m % 2 != 0 && n % 2 != 0) break;

		if (m % 2 == 0) { //가로가 짝수일때
			if (n % 2 == 0) { //세로도 짝수이면
				if (m >= n) {
					foldGaro(); // 가로가 더 길거나 같으면 가로로 접기
					m /= 2;
				}
				else {
					foldSero(); // 세로가 더 길면 세로로 접기
					n /= 2;
				}
			}
			else { // 세로가 짝수가 아니면
				foldGaro(); // 가로만 짝수
				m /= 2;
			}
		}
		else if (n % 2 == 0) { //세로만 짝수이면
			foldSero();
			n /= 2;
		}
	}

	return 0;
}