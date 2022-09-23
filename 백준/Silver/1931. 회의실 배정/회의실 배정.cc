#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define X first
#define Y second
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<pair<int, int>> table;
	int n, cnt=1; // 회의 1개 시작

	cin >> n;
	for (int i = 0; i < n; i++) {
		int start, end; 
		cin >> start >> end; // 시작시각과 종료시각 입력받기
		table.push_back(make_pair(end, start)); // 종료시각 순서대로 오름차순 정렬
	}
	sort(table.begin(), table.end()); // 정렬
	int time = table[0].X; // 종료시각이 가장 빠른 종료시각을 가져온다
	for (int i = 1; i < n; i++) {
		if (time <= table[i].Y) { // 종료시각이 시작시각보다 빠르다면
			cnt++; // 회의 가능 
			time = table[i].X; // 다음 종료시각으로 갱신
		}
	}
	cout << cnt;
	return 0;
	
}
