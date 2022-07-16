#include <iostream>
#include <queue>
#include <utility>
#include <string>
using namespace std;
#define X first
#define Y second
// ���ϻ��� ������, �ʷ��� ���̸� ���� ������ ���Ѵ�
// // ���ϻ����� ����� ���� ���� �ƴ� ����� ���� �� ������ ���� ������
// NxN�� R,G,B �� �ϳ��� ��ĥ�� �׸�
// �׸��� �� ���� �������� �������� ������ ���� ������ �̷���� �ִ�
// ���� ������ �����¿�� ������ �ִ� ��쿡 �� ���ڴ� ���� ������ ���Ѵ�

string paper[102];
int vis[102][102];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int subin;
string str;

void bfs(int x,int y) {
	queue<pair<int, int>> Q;
	Q.push({ x,y });
	vis[x][y] = 1;
	while (!Q.empty()) { 
		pair<int, int> cur = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx < 0 || nx >= subin || ny < 0 || ny >= subin) continue;
			if (vis[nx][ny] == 1 || paper[x][y] != paper[nx][ny]) continue;
			vis[nx][ny] = 1;
			Q.push({ nx,ny });
		}
	}

}

int area() {
	int cnt = 0; //ī��Ʈ �ʱ�ȭ
	for (int i = 0; i < subin; i++) {
		for (int j = 0; j < subin; j++) {
			if (vis[i][j] == 0) { // �湮���� �ʾҴٸ�
				bfs(i, j); //bfs ������
				cnt++; //bfs�� �������� �ش� ������ �����ϴ� ��� ���� Ȯ�� �����Ƿ� ī��Ʈ 1����
			}
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> subin; //n<=100
	for (int i = 0; i < subin;i++) {
		cin >> str; // string���� �Է¹��� 
		paper[i] = str;
	}

	int not_p = area(); //������ �ƴ� ���

	for (int i = 0; i < subin; i++) { // ������ ����� ���ϱ� ���� �湮�迭 �ʱ�ȭ
		fill(vis[i], vis[i] + subin, 0);
	}

	for (int x = 0; x < subin; x++) {
		for (int y = 0; y < subin; y++) {
			if (paper[x][y] == 'R') { //������ �ʷ��� �������� ���ϹǷ� ������ �ʷ����� �ٲ��ֱ�
				paper[x][y] = 'G';
			}
		}
	}

	int p = area(); // ���� Ȯ�� 
	cout << not_p << " " << p;
	return 0;
	
}