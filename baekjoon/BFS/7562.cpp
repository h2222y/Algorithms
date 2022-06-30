#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define X first
#define Y second

int dx[8] = { -2,-1,-2,-1,2,1,2,1 };
int dy[8] = { -1,-2,1,2,-1,-2,1,2 };
int map[302][302];
int dist[302][302];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T; // �׽�Ʈ ���̽��� ���� �Է�
	for (int tc = 0; tc < T; tc++) {
		int l; 
		cin >> l; //lxl�� ü����
		for (int x = 0; x < l; x++) { //�� �׽�Ʈ���̽����� dist�� map���� �ʱ�ȭ
			fill(dist[x], dist[x] + l, 0);
			fill(map[x], map[x] + l, 0);
		}
		int nowx, nowy; // ���� ����Ʈ�� ��ǥ
		cin >> nowx >> nowy;
		int movx, movy; // ����Ʈ�� ������
		cin >> movx >> movy;
		map[movx][movy] = 2; // �������� 2�� ǥ��
		queue<pair<int, int>> Q; // bfs�� ���� queue
		Q.push({ nowx,nowy }); // ���� ��ǥ�� bfs�� �ֱ�
		dist[nowx][nowy] = 1; // ���� ��ǥ�� �湮������ ǥ�� �������� 0
		int mx = 0;
		while (!Q.empty()) { //bfs
			auto cur = Q.front(); 
			Q.pop();
			for (int i = 0; i < 8; i++) { // ����Ʈ�� �� ���� �̵��� �� �ִ� �Ÿ���
				int nx = cur.X + dx[i];
				int ny = cur.Y + dy[i];
				if (nx < 0 || nx >= l || ny < 0 || ny >= l)continue; // ������ ������� üũ
				if (dist[nx][ny] > 0) continue; // �̹� Ȯ���� ���� ����
				dist[nx][ny] = dist[cur.X][cur.Y] + 1; // ������ǥ���� ���� ��ǥ�� �̵��� �� +1�� ���ش�.
				Q.push({ nx,ny }); // ť�� �ֱ�
				if (map[nx][ny] == 2) { //���������� �����ϸ�
					mx = max(mx, dist[nx][ny]-1); // �ּ� �� ���� �����ϴ��� ������ش�
				} //ù ĭ ���ܸ� ���� -1
			}
		}
		cout << mx << "\n"; // �� ���
	}
	return 0; 
}