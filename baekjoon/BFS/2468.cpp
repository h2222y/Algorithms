#include <iostream>
#include <utility>
#include <queue>
using namespace std;
#define X first
#define Y second

int board[103][103]; //�ǹ��� ���� ǥ���ϱ�
int vis[103][103]; // ���� ���� ǥ���ϱ� 
int dx[4] = { 0,0,-1,1 }; //���� �迭
int dy[4] = { -1,1,0,0 };
int main() {
	int n;
	cin >> n; // �迭 ũ�� �Է�
	int maxheight = 0; // �ǹ��� �ִ밪 ���ϱ� 
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			cin >> board[x][y]; // �ǹ��� ���� �Է¹ޱ�
			if (board[x][y] > maxheight) {
				maxheight = board[x][y]; // �ִ밪 ���ϱ�
			}
		}
	}
	int mx = 0; // ������ �ִ� ����
	for (int i = 0; i <= maxheight; i++) { //0���� �ִ� ���̱��� �ϳ��� ������ �� ���غ���
		int cnt = 0; // ������ �� ��
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < n; y++) {
				if (board[x][y] <= i) vis[x][y] = -1; //�ǹ��� ��������� -1 ǥ���ϱ�(i=0�϶����� i=�ִ���̱���) 
			}
		}

		for (int x = 0; x < n; x++) {
			for (int y = 0; y < n; y++) {
				if (vis[x][y]!=0) continue; // 0�� �ƴ϶�� queue�� ���� ���� ����
				queue<pair<int, int>> Q;
				Q.push({ x,y });
				vis[x][y] = 1; //queue�� ��Ƽ� �湮���� üũ
				while (!Q.empty()) {
					auto cur = Q.front();
					Q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = cur.X + dx[k];
						int ny = cur.Y + dy[k];
						if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue; //���� ������� üũ
						if (board[nx][ny] <= i || vis[nx][ny] == 1)continue; // �̹� ����ְų� �湮������ ����
						Q.push({ nx,ny });
						vis[nx][ny] = 1;
					}
				}
				cnt++; //������ ���� ����
			}
		}
		mx = max(mx, cnt); //������ ���� �ִ밪 ã��
		for (int x = 0; x < n; x++) {
			fill(vis[x], vis[x] + n, 0); // ���� i���� ���� vis�迭 �ʱ�ȭ 
		}
	}

	cout << mx;


	return 0;
}