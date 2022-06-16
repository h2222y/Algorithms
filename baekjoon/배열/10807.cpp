#include <iostream>
using namespace std;
//개수 세기

int main() {
	int n; //정수 몇개 주어질건지
	cin >> n;
	int arr[102] = { 0 };
	for (int i = 0; i < n; i++) {
		cin >> arr[i]; // 배열에 입력받기
	}
	int v;
	cin >> v; //찾을 정수
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == v) cnt++; //찾을 정수와 같으면 개수 세기
	}
	cout << cnt;
	return 0;
}