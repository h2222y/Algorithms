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


	fill(vis, vis + 1000001, -1); //vis 배열 -1로 초기화 

	queue<int> Q;
	Q.push(s);
	vis[s] = 0; // 강호가 현재 있는 층부터 시작 

	while(!Q.empty()){
	int cur = Q.front(); 
	Q.pop();
	for (int nxt : {cur + u, cur - d}) { // up만큼 올라가고 d만큼 내려갈때 
		if (nxt < 1 || nxt > f) continue; // 범위 벗어나는지 확인
		if (vis[nxt] != -1) continue; // 방문하지 않았던 곳만 방문하기 위함
		vis[nxt] = vis[cur] + 1;  // 현재좌표 +1으로 몇 번째 클릭인지 체크
		Q.push(nxt);
	}
	}
	if (vis[g] == -1) // vis[g]에 방문하는데 실패했다면
		cout << "use the stairs"; // 계단이용 출력 
	else cout << vis[g]; // 성공했다면 해당 값 출력
	return 0; 
}