#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int dx[4] = { 0,0,-1,1 }; // k�� �Ѿ��� �� �����¿�� �̵�
int dy[4] = { -1,1,0,0 };
int horse_dx[8] = { -1,1,-2,2,-2,2,1,-1 }; // k�� ���� �ʾ��� ��, ��ó�� �̵� 
int horse_dy[8] = { -2,-2,-1,-1,1,1,2,2 };
int board[202][202]; // �̵��� �� �ִ� �迭�� �Է¹���
int dist[32][202][202]; // k���� �������� k���� Ŭ�� ��� ���
queue<tuple<int, int, int>> Q;
int w, h; // ���� ���� �Է�
int sister; // k �Է�

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> sister;
	cin >> w >> h;
	for (int x = 0; x < h; x++) {
		for (int y = 0; y < w; y++){
			cin >> board[x][y];
		}
	} // �迭 �Է� ����
	Q.push({ 0,0,0 }); // 0,0,0�� ����
	dist[0][0][0] = 1;

	while (!Q.empty()) {
		int vk, vx, vy;
		tie(vk, vx, vy) = Q.front();
		Q.pop();
		if(vk<sister){ // k���� ������
		for (int i = 0; i < 8; i++) {
			int nx = vx + horse_dx[i];
			int ny = vy + horse_dy[i];
			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if (board[nx][ny]) continue; // board�� ��ֹ��϶�
 			if (dist[vk + 1][nx][ny]) continue; // vk+1, nx, ny�� 0�� �ƴҶ�
			dist[vk + 1][nx][ny] = dist[vk][vx][vy] + 1; // �� �� ������Ű�� �Ÿ� ǥ�� 
			Q.push({ vk+1,nx,ny });
			}
		}
		// vk�� k���� Ŀ���� ��
		for (int i = 0; i < 4; i++) {
			int nx = vx + dx[i];
			int ny = vy + dy[i];
			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if (board[nx][ny]) continue;
			if (dist[vk][nx][ny]) continue;
			dist[vk][nx][ny] = dist[vk][vx][vy] + 1;
			Q.push({ vk,nx,ny });
		}
	}
	int ans = 0x7f7f7f7f; // �ּ� �Ÿ��� ���ϱ� ���� 
	for (int i = 0; i < sister + 1; i++)
		if (dist[i][h - 1][w - 1]) ans = min(ans, dist[i][h - 1][w - 1]);
	if (ans != 0x7f7f7f7f) cout << ans - 1;
	else cout << -1;
	return 0;
}