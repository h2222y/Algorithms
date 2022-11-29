#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <cmath>
using namespace std;
#define X first
#define Y second

int n;
bool visited[100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T; // 테케 수 입력
	bool check = true;
	while (T--) {
		fill(visited, visited + 100, 0);
		pair<int, int> home;
		pair<int, int> store[100];
		pair<int, int> goal;
		cin >> n; // 편의점의 수 
		cin >> home.X >> home.Y; // 집 좌표 입력
		for (int i = 0; i < n; i++) {
			cin >> store[i].X >> store[i].Y; // 편의점 좌표 입력
		}
		cin >> goal.X >> goal.Y; // 도착지 좌표 입력
		queue<pair<int, int>> Q;
		Q.push({ home.X,home.Y }); // 큐에 시작 좌표 담기
		while (!Q.empty()) {
			pair<int, int> cur = Q.front(); 
			Q.pop();
			for (int i = 0; i < n; i++) {
				if (visited[i] == true) continue; // 이미 방문했다면 무시 
				int d = (abs(cur.X - store[i].X) + abs(cur.Y - store[i].Y)); //현재좌표와 편의점간의 거리
				// 각 좌표의 거리는 |x2-x1|+|y2-y1|
				// 맥주 20개 * 50미터 1000
				if (d <= 1000) { // 현재 좌표의 편의점간의 거리가 전체 맥주 갯수보다 작다면
					visited[i] = true; 
					Q.push({ store[i].X,store[i].Y }); //편의점 좌표 넣기 
				}
			}
			if (abs(cur.X - goal.X) + abs(cur.Y - goal.Y) <= 1000) { // 최종 좌표와 현재 좌표가 맥주 갯수보다 작다면
				cout << "happy\n";
				check = true;
				break;
			}
			check = false;
		}
		if (check == true)continue;
		if (check == false) cout << "sad\n";
	}
	return 0;
}