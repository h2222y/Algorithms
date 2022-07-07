#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;
#define X first
#define Y second

int board[103][103]; // �׸� �׸� ��
int dist[103][103]; // �湮 ���� ����
vector <int> ans; // ���̸� ������������ ����ϱ� ���� ����
int cnt = 0; // �׸��� ���� ������ ������ ����

int dx[4] = { 0,0,-1,1 }; //���� �迭
int dy[4] = { -1,1,0,0 };

int main() {
	int m, n, k; //mxn ��ȭ��, k���� ���簢��
	cin >> m >> n >> k;
	// ���簢���� ������ �κ��� �и��� ������ ����
	// ������ �κ��� ���̸� ���

	for (int i = 0; i < k; i++) { // k���� �Է¹ޱ�
		int startx, starty, endx, endy;
		cin >> startx >> starty >> endx >> endy;
		for (int x = m-1-starty; x > m-1-endy; x--) {
			for (int y = startx; y < endx; y++) {
				board[x][y] = 1; // �׸� �׸���
			}
		}
	}

	for (int x = 0; x < m; x++) {
		for (int y = 0; y < n; y++) {
			if (board[x][y] == 1 || dist[x][y] == 1) continue; //�׸��� �׷��� ���̰ų�
			// �̹� �湮�� ���̸� ����
			queue<pair<int, int>> Q;
			dist[x][y] = 1; // �湮ǥ��
			Q.push({ x,y }); //ť�� ���
			int width = 1; //���� ����
			cnt++; // �׸��� ���� ������ �������� 
			while (!Q.empty()) { //bfs
				auto cur = Q.front();
				Q.pop();
				for (int i = 0; i < 4; i++) {
					int nx = cur.X + dx[i];
					int ny = cur.Y + dy[i];
					if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue; //���� ������� üũ
					if (board[nx][ny] != 0) continue; // �׸��� �ִ� ���̸� ����
					if (dist[nx][ny] == 1) continue; // �̹� �湮�Ѱ��̸� ����
					Q.push({ nx,ny });
					dist[nx][ny] = 1;
					width++; // ���� ���� 
				}
			}
			ans.push_back(width); // ���Ϳ� ���� �ֱ�
		}
	}
	sort(ans.begin(), ans.end()); //���� �������� ���� 
	cout << cnt << "\n"; //���� ���
	for (int i : ans)
		cout << i << " "; // ���� ���


	return 0;
}