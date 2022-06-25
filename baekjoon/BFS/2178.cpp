#include <iostream>
#include <queue>
#include <utility>
using namespace std;

#define X first
#define Y second

int board[101][101]; // �̷�
int n, m;//��,��
int dx[4] = { 1,-1,0,0 }; // �� ����迭
int dy[4] = { 0,0,-1,1 }; // �� ����迭
int vis[101][101] = { 0 }; // �湮 üũ

int main(void) {
	cin >> n >> m; //�� �� �Է¹ޱ�
	for (int i = 0; i < n; i++) {
		string str; //���ڿ��� �Է¹޾Ƽ�
		cin >> str;
		for (int j = 0; j < m; j++) {
			board[i][j] = str[j] - '0'; //���ڷ� ��ȯ�ؼ� �迭�� �־���
		}
	}
	queue<pair<int, int>> Q;
	vis[0][0] = 1; //�� ù ĭ�� 1�� �ΰ�
	Q.push({ 0,0 }); // Q�� ù ĭ�� �־��ش�
	while (!Q.empty()) { // ť�� �Ⱥ������ ���ȸ� �ݺ�
		pair<int, int> cur = Q.front(); //ť���� ���� ó������ ��ġ �����س���
		Q.pop(); //ť���� front ���� ��
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir]; //��ġ���� �����¿� üũ
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; //���� ����� ����
			if (vis[nx][ny] != 0 || board[nx][ny]!=1 ) continue; // �湮�� ���� �ְų� board�� ���� 1�� �ƴϸ� �� �� ����
			vis[nx][ny] = vis[cur.X][cur.Y]+1; //vis�� ���� ���� ���簪���� 1���Ѱ����� ������Ʈ ���ش�.
			Q.push({ nx,ny }); //ť���� ���� ��ǥ�� �־���
		}
	}
	cout << vis[n-1][m-1]; //n,m�� ũ��ϱ� n-1, m-1��° ����� ���� ����ϸ� �ȴ�.
	return 0;
}