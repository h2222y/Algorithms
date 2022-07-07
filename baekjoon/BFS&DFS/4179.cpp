#include <iostream>
#include <queue>
#include <utility>
#include <string>
using namespace std;
#define X first
#define Y second

string map[1001];
int vis1[1001][1001]; // ���� ���� �ð�
int vis2[1001][1001]; // �������� �̵� �ð� 

int dx[4] = { 0,0,-1,1 }; // ���� �迭
int dy[4] = { -1,1,0,0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int r, c;
	cin >> r >> c; // �迭�� ��,�� �Է¹���
	for (int i = 0; i < r; i++) {
		fill(vis1[i], vis1[i] + c, -1); // ���� ���� �ð� �迭 -1�� �ʱ�ȭ
		fill(vis2[i], vis2[i] + c, -1); // �������� �̵� �ð� �迭 -1�� �ʱ�ȭ 
	}
	for (int x = 0; x < r; x++) {
		cin >> map[x]; //string���� �Է� ���� �� �ֱ�
	}
	queue<pair<int, int>> Q1; // �� bfs queue
	queue<pair<int, int>> Q2; // ������ bfs queue
	// # ��, . ������ �� �ִ� ����, J �������� �̷ο����� �ʱ���ġ(������ �� �ִ� ����)
	// F ���� �� ����
	// �����̿� ���� �� �и��� �� ĭ�� ���� �Ǵ� �������� �̵��Ѵ�
	// �����̴� ���� ���� �ִ� ������ ������� ���Ѵ�.
	// �������� �ΰ�(�������� �̵�, ���� �̵�)
	for (int x = 0; x < r; x++) {
		for (int y = 0; y < c; y++) {
			if (map[x][y] == 'F') { // ���� ������ �ֱ�
				Q1.push({ x,y });
				vis1[x][y] = 0;
			}
			if (map[x][y] == 'J') {
				Q2.push({ x,y }); // �������� ������ �ֱ�
				vis2[x][y] = 0;
			}
		}
	}
	// �� bfs
	while (!Q1.empty()) {
		pair<int, int> cur = Q1.front();
		Q1.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (vis1[nx][ny] >= 0 || map[nx][ny] == '#') continue;
			vis1[nx][ny] = vis1[cur.X][cur.Y] + 1;
			Q1.push({ nx,ny });
		}
	}

	// ������ bfs
	while (!Q2.empty()) {
		pair<int, int> cur = Q2.front();
		Q2.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i]; 
			int ny = cur.Y + dy[i];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) { // ó�� ������ ����ٴ� ���� Ż�⿡ �����ߴٴ� �ǹ��̴�
				cout << vis2[cur.X][cur.Y] + 1; //���� ��ġ���� +1�� ���ش�
				return 0; //Ż�� ������ �ٷ� ����  
			}
			if (vis2[nx][ny] >= 0 || map[nx][ny] == '#') continue;
			if (vis1[nx][ny] != -1 && vis1[nx][ny] <= vis2[cur.X][cur.Y] + 1) continue; // ���� �湮�� ���̳� ���� �湮�� �ð��� �����̰� �湮�� �ð����� �ռ��ų� ������ �ȵȴ� 
			vis2[nx][ny] = vis2[cur.X][cur.Y] + 1;
			Q2.push({ nx,ny });
		}
	}
	cout << "IMPOSSIBLE";
	return 0;
}