#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define X first
#define Y second
//����� ����

// �����̴� ���߱�ó���� �����ϸ� ������ ��ƸԾ� ��ȣ
// �� ������ �Ѹ����� ��� ������ �ٸ� ���߷� �̵� ���� �� �� �� ��

// ���ߵ��� �� ������ �����ִ��� �����ϸ� �� �� ������ �����̰� �ʿ����� �� �� �ִ�
// ���� �ɾ����ִ¶� 1, ���� ���� �� 0 

int dx[4] = { 0,0,-1,1 }; // ����迭
int dy[4] = { 1,-1,0,0 };
queue<pair<int, int>> Q; // ���� ��ġ ���� ť

int map[51][51];// ���� �׸� map
int vis[51][51]; // �湮 ���� üũ

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T; // ���� �� �Է�
	for (int tc = 1; tc <= T; tc++) {
		int m, n;
		cin >> m >> n; // ��, �� <=50
		int k;
		cin >> k; // ���߰� �ɾ��� �ִ� ��ġ�� ���� <=2500
		

		for (int i = 0; i < k; i++) {
			int x, y; // ������ ��ġ
			cin >> x >> y; //��ġ �Է¹ޱ�
			map[x][y] = 1; //�ش� ��ġ�� 1 ǥ��
		}

		int cnt = 0; // �������� ���� ��ġ�� ������ �� �� 

		for (int x = 0; x < m; x++) { // ��, ���� ���鼭
			for (int y = 0; y < n; y++) {
				if (map[x][y] == 1 && vis[x][y] != 1) { // ���߰� �ɾ����ְ�, �湮���� ���� ���̸� 
					vis[x][y] = 1;// �湮 üũ
					Q.push({ x,y }); // ť�� �ش� x,y�� ���
					while (!Q.empty()) { // bfs
						pair<int, int> cur = Q.front();
						Q.pop();
						for (int i = 0; i < 4; i++) {
							int nx = cur.X + dx[i];
							int ny = cur.Y + dy[i];
							if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
							if (vis[nx][ny] == 1 || map[nx][ny] == 0) continue;
							vis[nx][ny] = 1;
							Q.push({ nx,ny });
						}
					}
					cnt++;
				}
			}
		}

		cout << cnt << endl;
		for (int i = 0; i < m; i++) {
			fill(map[i], map[i] + n, 0);
			fill(vis[i], vis[i] + n, 0);
		} // ���� ���ɸ� ���� �ʱ�ȭ
	}

	return 0;
}