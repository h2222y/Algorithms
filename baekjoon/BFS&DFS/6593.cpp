#include <iostream>
#include <queue>
#include <utility>
#include <tuple>
using namespace std;


char board[33][33][33]; // �ǹ��� ���� �Է¹ޱ�
int vis[33][33][33]; // �ִ� �Ÿ� ���ϱ�
int dx[6] = { -1,1,0,0,0,0 }; // ����迭 ��,��,��,��,��,�Ʒ�
int dy[6] = { 0,0,-1,1,0,0 };
int dz[6] = { 0,0,0,0,-1,1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (1) {
		bool escape = false; // Ż�� ����, ���и� ����
		int l, r, c;
		cin >> l >> r >> c; // ����, ��, �� �Է¹ޱ�
		queue<tuple<int, int, int>> Q; // bfs
		if (l == 0 && r == 0 && c == 0) return 0; // 0,0,0 �Է½� ���� 
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					cin >> board[i][j][k];
					if (board[i][j][k] == 'S') { // �������� ���
						Q.push({ i,j,k }); // ť�� ���
						vis[i][j][k] = 0; // vis 0���� 
					} 
					else if (board[i][j][k] == '.') { // �� �� �ִ� ���ϰ�� 
						vis[i][j][k] = -1; // -1���� 
					}
				}
			}
		}
		while (!Q.empty() && !escape) {
			tuple<int, int, int> cur = Q.front();
			Q.pop();
			int curX, curY, curZ;
			tie(curZ, curX, curY) = cur;
			for (int i = 0; i < 6; i++) {
				int nx = curX + dx[i];
				int ny = curY + dy[i];
				int nz = curZ + dz[i];
				if (nx < 0 || nx >= r || ny < 0 || ny >= c || nz < 0 || nz >= l)continue; // ���� üũ
				if (board[nz][nx][ny] == '#' || vis[nz][nx][ny] > 0) continue; // ���̸� �� �� ���� 0, -1�� �� �� �ִ� �� 
				vis[nz][nx][ny] = vis[curZ][curX][curY] + 1; // ��� ǥ��
				if (board[nz][nx][ny] == 'E') { // Ż�ⱸ �߰��ϸ� Ż�� ���� 
					cout << "Escaped in " << vis[nz][nx][ny] << " minute(s).\n"; // �ش� vis�� ���
					escape = true; // Ż�� ������ �ݺ� ���� 
					break;
				}
				Q.push({ nz,nx,ny });

			}
		}

		if (!escape) cout << "Trapped!\n"; // Ż�� ���н� Trapped! ���

		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) { // ���� �Է��� ���� vis �迭 �ʱ�ȭ
				fill(vis[i][j], vis[i][j] + c, 0);
			}
		}

	}

	return 0;
}