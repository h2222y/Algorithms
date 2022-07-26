#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define X first
#define Y second

int vis[1000001];
int main() {
	// 건물 총 F층, 스타트링크는 G층
	// 강호가 현재 있는 층 S층
	// 엘레베이터 up버튼 down버튼 두개 있음
	int f, g, s, u, d;
	cin >> f >> s >> g >> u >> d;
	// 강호가 s층에서 g로 가기 위해 눌러야하는 버튼의 수의 최솟값 출력
	// 이동할 수 없을 때는 use the stairs 출력


	fill(vis, vis + 1000001, -1);
	queue<int> Q;
	Q.push(s);
	vis[s] = 0;

	while(!Q.empty()){
	int cur = Q.front();
	Q.pop();
	for (int nxt : {cur + u, cur - d}) {
		if (nxt < 1 || nxt > f) continue;
		if (vis[nxt] != -1) continue;
		vis[nxt] = vis[cur] + 1;
		Q.push(nxt);
	}
	}
	if (vis[g] == -1)
		cout << "use the stairs";
	else cout << vis[g];
	return 0; 
}