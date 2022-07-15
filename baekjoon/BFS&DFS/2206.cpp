#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

char board[1000][1000];
int dist[1000][1000][2];
// dist[x][y][0] : ���� �ϳ��� �μ��� �ʰ� (x,y)���� ���µ� �ɸ��� ���
// dist[x][y][1] : ���� �ϳ��� �μ��� (x,y)���� ���µ� �ɸ��� ���, (x,y)�� ���̶� �μ��� ��� ����
int subin, m;

int bfs() {
	for (int i = 0; i < subin; ++i)
		for (int j = 0; j < m; ++j)
			dist[i][j][0] = dist[i][j][1] = -1; // ���� �μ��� �ʴ� ���� �μ��� ����� dist�迭�� ��� -1 ����
	dist[0][0][0] = dist[0][0][1] = 1; // �� ���� ��ǥ���� 1 ����
	queue<tuple<int, int, int>> q; // �������� ���� queue
	q.push({ 0,0,0 }); // 0,0,0�� ť�� ����(���� �μ��� �ʴ� ����� 0,0 ��ǥ)
	while (!q.empty()) {
		int x, y, broken;
		tie(x, y, broken) = q.front();
		if (x == subin - 1 && y == m - 1) return dist[x][y][broken]; // ���� ��ǥ�� �� return 
		q.pop(); 
		for (int dir = 0; dir < 4; ++dir) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || nx >= subin || ny < 0 || ny >= m) continue; // ������ ����� ���
			if (board[nx][ny] == '0' && dist[nx][ny][broken] == -1) { // �̵��� �� �ְ� ���� �湮���� �ʾ��� ��(broken==1)
				dist[nx][ny][broken] = dist[x][y][broken] + 1; // �Ÿ� +1
				q.push({ nx, ny, broken }); // ������ ť�� �ٽ� �ֱ�
			}
			// (nx, ny)�� �μ��� ���
			if (!broken && board[nx][ny] == '1' && dist[nx][ny][1] == -1) { // broken�� 0�϶��� ���ٰ���, �� �μ��� ���� �������� ���� ����
				// �μ��� ���� ���� �� board[nx][ny]�� 1�̰�, broken �迭���� �̵��� ���� ���� �� 
				dist[nx][ny][1] = dist[x][y][broken] + 1; // dist[x][y][0]�� 1 �߰�
				q.push({ nx, ny, 1 }); // ť�� �� �ֱ� broken�� 1�� ��������ָ鼭 �� ���ǿ� �ٽ� ���� �� ����
			}
		}
	}
	return -1; // ���� �ش���� ������ -1�� return �Ѵ�. 
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> subin >> m;
	for (int i = 0; i < subin; ++i)
		for (int j = 0; j < m; ++j)
			cin >> board[i][j];
	cout << bfs();
	return 0;
}