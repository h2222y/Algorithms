#include <iostream>
using namespace std;

int n;
int arr[101][101] = { 0 }; //n<100

int SumW(); //가로 합
int SumC(); //세로 합
int main() {
	cin >> n;
	for (int y = 1; y <= n; y++) { // 문제에서 인덱스 1로 시작한다고 명시되어 있음
		for (int x = 1; x <= n; x++) {
			cin >> arr[y][x];
		}
	}
	int retw = 0, retc = 0;
	retw = SumW(); //행
	retc = SumC(); //열
	if (retw == -1 && retc == -1) cout << "OK"; //둘다 -1이면 정상
	else if (retw >= 0 && retc >= 0) cout << "Change bit (" << retw << "," << retc << ")"; //둘다 1개이면 각각의 인덱스 출력해주기
	else cout << "Corrupt"; // 여러개면 corrupt
	return 0;
}
int SumW() {
	int sum = 0;
	int cnt = 0, a;
	for (int y = 1; y <= n; y++) {
		sum = 0;
		for (int x = 1; x <= n; x++) {
			sum += arr[y][x];
		}
		if (sum % 2 != 0) { //짝수가 아닌 행 개수 구하기
			cnt++;
			a = y;
		}
	}
	if (cnt == 0) return -1; // 짝수가 아닌 행 없을떄
	else if (cnt == 1) return a; //짝수가 아닌 행이 딱 하나 일 때
	else return -2; // 짝수가 아닌 행 많을때
}
int SumC() {
	int sum = 0;
	int cnt = 0, a;
	for (int x = 1; x <= n; x++) {
		sum = 0;
		for (int y = 1; y <= n; y++) {
			sum += arr[y][x];
		}
		if (sum % 2 != 0) {
			cnt++; //짝수가 아닌 열 개수 구하기
			a = x;
		}
	}
	if (cnt == 0) return -1; //짝수가 아닌 열 없을때
	else if (cnt == 1) return a; //짝수가 아닌 열이 딱 하나일 때
	else return -2; // 짝수가 아닌 열 많을때
}
