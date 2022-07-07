#include <iostream>
#include <queue>
#include <utility>
using namespace std;
//�׸�
 
#define X first // pair�� first �� ��� ���
#define Y second //pair�� second �� ��� ��� 
int n, m; // n ����ũ��(��)<=500, m ����ũ��(��)<=500
int board[501][501]; // ��ȭ��
bool vis[501][501] = { 0 }; // �湮 ���θ� üũ
int dx[4] = { 1,-1,0,0 }; //x ����迭 -�� 
int dy[4] = { 0,0,-1,1 }; // y ����迭 -��

int main(void) {
	cin >> n >> m; //��, �� �Է¹���
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			cin >> board[x][y]; // board�� �׸� �׸���
		}
	}
	int mx = 0; //�׸��� �ִ� ũ�� ��
	int num = 0; //�׸��� ����
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0 || vis[i][j]) continue; //board�� 0�̰ų� �̹� �湮�� ���̸� ����
			num++; // �׸��� ���� ī��Ʈ
			queue<pair<int, int>> Q; // ť���� �湮�� ��带 ���� ����
			vis[i][j] = 1; //i,j�� �����ϴ� ���� �湮 ǥ��
			int area = 0;
			Q.push({ i,j }); // �湮�� ��带 ť�� ����
			while (!Q.empty()) {
				area++; // �� ������ ��庰 �׸��� ũ�⸦ ���ϱ� ���� area++
				// area�� �ִ밪�� ���ϸ� ���� ū �׸��� ũ�⸦ �� �� �ִ�.
				pair<int, int>cur = Q.front(); // cur�� ť�� front�� ����
				Q.pop(); // Q���� �� ������
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir]; //�ش� ��ġ���� �����¿� �� Ȯ��
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // ���� ������� Ȯ��
					if (vis[nx][ny] == 1 || board[nx][ny] == 0) continue; // �湮�߰ų� 0�̸� ����
					vis[nx][ny] = 1; //������ ��� �湮 ǥ�ø� ���ְ�
					Q.push({ nx,ny }); //ť�� �ش� ���� �־��ش�. 
				}
			}
			mx = max(mx, area); //area�� �� ���� �׸��� ũ���̹Ƿ� ���� ū �׸��� �����ش�. 
		}
	}
	cout << num << '\n' << mx; //�׸��� ���� ũ�� ���

	return 0;
}