#include <iostream>
#include <queue>
#include <utility>
using namespace std;

const int MX =102;
int board[MX][MX]; 
int dist[MX][MX];
int vis[MX][MX];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
queue <pair<int, int>> Q;
int subin;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> subin;
	for (int x = 0; x < subin; x++) {
		for (int y = 0; y < subin; y++) {
			cin >> board[x][y]; //board�� �� �Է¹ޱ�, 0�̸� �ٴ�, 1�̸� ��
		}
	}
	int cnt = 0; //ī��Ʈ ����
	for (int x = 0; x < subin; x++) {
		for (int y = 0; y < subin; y++) {
			if (board[x][y] == 0 || vis[x][y]) continue; // ���� �ƴϰų� �̹� �湮�Ѱ��̸� ����
			cnt++; //ī��Ʈ ������ ��� ������ board�� ǥ���Ѵ�.
			Q.push({ x,y }); //bfs�� ���� ���� ��ȣ�� �ο�
			vis[x][y] = 1;
			board[x][y] = cnt;
			while (!Q.empty())
			{
				auto cur = Q.front();
				Q.pop();
				for (int i = 0; i < 4; i++) {
					int nx = cur.first + dx[i];
					int ny = cur.second + dy[i];
					if (nx < 0 || nx >= subin || ny < 0 || ny >= subin) continue;
					if (vis[nx][ny] || board[nx][ny] == 0) continue;
					Q.push({ nx,ny });
					board[nx][ny] = cnt;
					vis[nx][ny] = 1;
				}
			} 
		}
	}
	for (int i = 0; i < subin; i++)
		fill(dist[i], dist[i] + subin, -1); //dist�迭�� -1�� �ʱ�ȭ 
	int ans = 999999; // ���� ª�� �ٸ��� ���� ��

	for (int x = 0; x < subin; x++) {
		for (int y = 0; y < subin; y++) {
			if (board[x][y] == 0) continue; // �ٴٸ� ����
			Q.push({ x,y });
			dist[x][y] = 0;
			bool escape = false; // �ٸ��� ��� ������ �� �ݺ��� Ż���� ���� ���� 
			while (!Q.empty() && !escape) {
				auto cur = Q.front();
				Q.pop();
				for (int i = 0; i < 4; i++) {
					int nx = cur.first + dx[i];
					int ny = cur.second + dy[i];
					if (nx < 0 || nx >= subin || ny < 0 || ny >= subin)continue; // ������ ��� ��� 
					if (dist[nx][ny] >= 0 || board[nx][ny] == board[x][y]) continue; // �̹� �湮�߰ų�, ���� ���� ���
					if (board[nx][ny] != 0 && board[nx][ny] != board[x][y]) { // �ٴٰ� �ƴϰ�, ���� ���� �ƴ� ���
						ans = min(ans, dist[cur.first][cur.second]); // �ٸ��� �ּҰ��� �����ϰ�
						while (!Q.empty())Q.pop(); // ť�� ���� ���� ��� �������ش�. 
						escape = true; // Ż�� ������ true�� ���� while���� for�� Ż��
						break;
					}
					dist[nx][ny] = dist[cur.first][cur.second] + 1; 
					Q.push({ nx,ny });
				}
			}
			for (int i = 0; i < subin; i++)
				fill(dist[i], dist[i] + subin, -1); // �ϳ��� ���� ��� �������� dist �迭�� �ٽ� �ʱ�ȭ 
		}
	} 
	cout << ans; // ���� ���
}