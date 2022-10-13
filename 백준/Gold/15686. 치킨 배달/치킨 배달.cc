#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#define X first
#define Y second
using namespace std;
int n, m;// nxn 배열, 남겨야 할 치킨집 수 m
int map[52][52];
int used[52];
int cntShop = 0;
int ans = 99999999;
vector<pair<int, int>> house, chicken, v;
// 입력 
void Input() {
	cin >> n >> m;
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) {
			cin >> map[x][y];
			if (map[x][y] == 1) house.push_back(make_pair(x, y)); // 만약 집이면 집에 해당하는 좌표를 저장한다.
			if (map[x][y] == 2) chicken.push_back(make_pair(x, y)); // 만약 치킨집이면 치킨집에 해당하는 좌표를 저장한다. 
		}
	}
	cntShop = chicken.size(); // 전체 치킨집의 개수를 구한다. 
}

// 거리 계산
int Dist() {
	int sum = 0; // 도시의 치킨거리를 구할 sum 
	for (int i = 0; i < house.size(); i++) {
		int x = house[i].X; // 집의 x 좌표
		int y = house[i].Y; // 집의 y 좌표
		int d = 9999999; // 치킨집과 각 집과의 최소거리 (치킨거리) 구함 
		for (int j = 0; j < v.size(); j++) { 
			int xx = v[j].X; // m개의 치킨집, 즉 고른 치킨집의 x 좌표
			int yy = v[j].Y; //고른 치킨집의 y 좌표
			int dist = abs(x-xx) + abs(y - yy); // 거리 구하기
			d = min(d, dist); // 치킨 거리는 각 집에서 치킨집의 거리의 최소값 
		}
		sum += d; // 각 치킨 거리의 합은 도시의 치킨 거리 
	}
	return sum; //도시의 치킨 거리 return 
}

void SelectChicken(int idx, int cnt) {
	if (cnt == m) { // cnt가 m과 같아지면 
		ans = min(ans, Dist()); // 도시의 치킨 거리를 구하고 최소거리를 찾는다. 
		return;
	}
	for (int i = idx; i < cntShop; i++) { // dfs 돌릴 것, now 부터 cntShop 까지 , 치킨집의 개수만큼을 돌린다 
		if (used[i] == 1) continue; // 만약 이미 방문했다면 무시
		used[i] = 1; // 방문 표시
		v.push_back(chicken[i]); // 치킨벡터[now]를 v에 넣는다. 즉 치킨집을 고른다. 
		SelectChicken(i, cnt + 1); // 해당 인덱스와 cnt+1 값을 보낸다.
		used[i] = 0; // 돌아올 땐 사용한 것 기록 지우기
		v.pop_back(); // v도 지우기 
	}

}


int main() {
	Input(); //입력받기
	SelectChicken(0, 0);
	cout << ans << "\n";

}