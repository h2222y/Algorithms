#include <iostream>
#include <queue>
using namespace std;
int subin, sister;
int dist[200005];

int main() {
	cin >> subin >> sister; // 수빈이와 동생의 위치를 입력받는다
	deque<int> DQ; //deque 사용
	fill(dist, dist + 200000, -1); // 범위는 2배를 고려해서 잡았다/
	DQ.push_back(subin); // dq에 수빈이의 좌표를 넣는다
	dist[subin] = 0; // 수빈이의 좌표를 0으로 두고 거리를 측정한다. 
	while(!DQ.empty()) { // dq가 모두 빌때까지
		int cur = DQ.front(); // dq의 앞의 값을 가져온다
		DQ.pop_front(); // 값 빼기
		if (2 * cur < 200000 && dist[2 * cur] == -1) { //2배이면서, 아직 방문하지 않은 경우
			dist[2 * cur] = dist[cur]; // 0초가 걸리기 때문에 그대로 값을 대입한다.
			DQ.push_front(2 * cur); // 앞의 값을 빼준다 
		}
		for (auto nxt : { cur + 1,cur - 1}) { //+1,-1로 이동할때
			if (nxt < 0 || nxt >= 200000)continue; // 범위에서 벗어나는 경우
			if (dist[nxt] != -1)continue; // 이미 방문한 경우
			else dist[nxt] = dist[cur] + 1; // 1초가 소요된다
			DQ.push_back(nxt); //뒤에 넣어준다.
		}
	}
	cout << dist[sister]; // 동생의 좌표의 dist값 출력하기
}