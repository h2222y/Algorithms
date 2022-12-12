#include <iostream>
#include <algorithm>
using namespace std;
long int line[10002];
int k, n;

long int cut(long long start, long long end) {
	long long result = 0; // 결과값
	long long mx = 0;
	while (start <= end) {
		long long cnt = 0; // 개수 카운트
		long long mid = (start + end) / 2; // 중간값
		for (int i = 0; i < k; i++) {
			cnt += line[i] / mid;
		}
		if (cnt < n) { // 개수가 안되면 
			end = mid - 1; // 중간값을 1 줄여서 끝값으로 설정하고 다시 중간값 구하기 
		}
		else {
			start = mid+1;
			if (mx < mid) mx = mid; //중간값 1 늘려서 시작점에 넣고 확인해보기 
		}
	}
	return mx;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> line[i];
	}
	sort(line, line + k);
	long long start = 1; // 시작 0
	long long end = line[k - 1]; // 가장 큰 값
	cout << cut(start, end);
	return 0;
}