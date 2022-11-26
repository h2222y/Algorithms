#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,c; // 집의 개수,공유기의 개수
int idx = 0;
// 인접한 두 공유기 사이의 최대 거리를 출력

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> c; // 집의 개수와 공유기의 개수 입력
	vector<int> v(n, 0); // 벡터 초기화 및 선언

	for (int idx = 0; idx < n; idx++) {
		cin >> v[idx]; // 벡터에 집 좌표 입력
	}
	sort(v.begin(), v.end()); // 벡터 오름차순 정렬
	int left = 0, right = v[n - 1]; // left와 right에 최대 최소값 넣기
	while (left <= right) { // binary search 
		int cnt = 1; // 공유기 개수 세기, 처음에 무조건 설치
		int pre_idx = 0; // 이전 인덱스 값 저장
		int mid = (left + right) / 2; // 중간값 
		for (idx = 1; idx < n; ++idx) { // pre_idx가 존재하므로 1부터 시작
			if (v[idx] - v[pre_idx] >= mid) { // 인덱스의 좌표 - 이전인덱스의 좌표가 mid값보다 크거나 같으면
				pre_idx = idx; // 이전 인덱스는 현재 인덱스로
				cnt++; // 공유기 설치
			}
		}
		if (cnt >= c) { // 공유기 개수가 가지고 있는 개수보다 크거나 같으면
			left = mid + 1; // 간격 넓히기
		}
		else right = mid - 1; // 작으면 간격 줄이기 
	}
	cout << right; // right에 있는 값 출력 


	return 0; 
}