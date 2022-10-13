#include <iostream>
#include <cmath>
using namespace std;
int teams[22][22];
int n;
int intel = 0;
bool check[22];
int ans = 1000000000;

void dfs(int cnt,int now) { //카운트와 현재 속할 값 
	if (cnt == n / 2) { // n의 절반이 되면 팀을 이룰 수 있음 
		int start = 0;
		int link = 0;  
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
			{
				if (check[i] == true && check[j] == true) start += teams[i][j]; // true면 스타트 팀
				if (check[i] == false && check[j] == false) link += teams[i][j]; // false면 링크 팀
			} 
		}
		int temp = abs(start - link); // 스타트와 링크팀 능력치 차이 구하기 
		if (ans > temp) ans = temp;// 만약 능력치 차이가 더 작은 것이 있다면 정답 갱신
	}
	for (int to = now; to < n; to++) { // 다음으로 가기 위해 
		check[to] = true; // 현재 to 는 true로 변환 
		dfs(cnt + 1, to + 1); // 카운트 증가시키고 to 증가 
		check[to] = false; // 돌아올 경우 false로 바꿔서 링크 팀으로도 넣어준다. 
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) {
			cin >> teams[x][y]; // 인접배열 입력 
		}
	}
	dfs(0,1); // 카운트 0, 팀 1부터 탐색 시작 
	cout << ans; // 정답 출력 
	return 0;
}