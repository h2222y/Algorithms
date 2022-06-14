#include <iostream>
#include <algorithm>
using namespace std;

// 두 수의 합
// 시간초과 고려해서 투 포인터 알고리즘 이용

int main() {
	int n,x; // 수열의 개수 n, 합 x
	cin >> n;
	int cnt = 0;//합 x와 일치하는 두 수의 순서쌍
	int arr[100001] = { 0 };
	for (int i = 0; i < n; i++) {
		cin >> arr[i]; // 입력받기
	}
	cin >> x; // x 입력받기
	sort(arr, arr + n); //오름차순으로 정렬
	
	int i = 0, j = n - 1;
	while (1) {
		int sum = arr[i] + arr[j]; // 합구하기
		if (i >= j) break; // 앞 포인터가 뒤보다 크거나 같아지면 종료
		if (sum == x) { 
			cnt++;
			i++;
			j--;
		}
		else if (sum < x) {
			i++;
		}
		else j--;

	}
	cout << cnt;
	return 0;
}