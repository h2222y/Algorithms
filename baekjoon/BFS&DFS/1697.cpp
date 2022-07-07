#include <iostream>
#include <queue>
using namespace std;

int vis[100002]; // 수빈이가 이동하는 배열

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k; //수빈이의 좌표와 동생의 좌표 입력
	queue<int> Q;
	Q.push(n); // 수빈이의 처음 좌표를 큐에 넣는다
	fill(vis, vis + 100001, -1); // 이동 배열을 -1로 초기화
	vis[n] = 0; // 수빈이의 첫 이동좌표에 0을 넣어준다. 
	while (vis[k] == -1) { // -1일동안
		int cur = Q.front();
		Q.pop();
		for (int nxt : {cur - 1, cur + 1, 2 * cur}) { //이동은 cur-1,cur+1,cur*2 가능
			if (nxt < 0 || nxt>100000)continue; // nxt의 값이 범위를 벗어날때
			if (vis[nxt] != -1) continue; // 이미 방문했을때
			vis[nxt] = vis[cur] + 1; // 현재좌표 +1을 넣어준다
			Q.push(nxt);
		}
	}
	cout << vis[k]; //동생의 좌표에 있는 이동 좌표를 출력해준다.
	return 0;
}