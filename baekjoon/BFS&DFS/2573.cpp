#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define X first
#define Y second

int ice[302][302];
int vis[302][302];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int subin, m;

int status() {
	int x = -1, y = -1;
	int cnt = 0; // ���� �� ������ ���� 
	for (int i = 0; i < subin; i++) {
		for (int j = 0; j < m; j++) {
			if (ice[i][j] == 0)continue; //�ٴٸ� ���� 
			x = i; // ������ �����ϸ� x,y ���� ����
			y = j;
			cnt++; // ���� �� ������ ���� ����
		}
	}
	if (cnt == 0) return 0; // ������ �������� �ʴ´ٸ� 0 ��ȯ
	int cnt2 = 0; // ������ �� �������� �� �������� Ȯ���ϱ� ���� cnt����
	queue<pair<int, int>> Q;
	vis[x][y] = 1;
	Q.push({ x,y });
	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();
		cnt2++; // �̾��� ������ ���� ������ ��
		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx < 0 || nx >= subin || ny < 0 || ny >= m) continue;
			if (vis[nx][ny] == 1 || ice[nx][ny] <= 0) continue;
			vis[nx][ny] = 1;
			Q.push({ nx,ny });
		}
	}
	if (cnt == cnt2) return 1; //�̾��� ���� ������ ��ü ���� ������ ���ٸ�, ������ ���� �� ���̶�� �ǹ�
	return 2; // ���� �� ��찡 �ƴ϶�� ������ �и��� �� 
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> subin >> m;
	for (int x = 0; x < subin; x++) {
		for (int y = 0; y < m; y++) {
			cin >> ice[x][y]; //���� ���� �Է¹ޱ�
		}
	}
	int year = 0; // �� �� �ɷȴ����� ����
	while (1) {
		for (int x = 0; x < subin; x++) { 
			for (int y = 0; y < m; y++) {
				if (ice[x][y] == 0) continue; // �ٴٸ� ���� 
				for (int dir = 0; dir < 4; dir++) {
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					if (nx < 0 || nx >= subin || ny < 0 || ny >= m) continue;
					if (ice[nx][ny] != 0) continue; //�ٴٰ� �ƴϸ� ���� 
					vis[x][y]++; // �ٴٰ� �ƴ� ���� �湮 �迭�� ������Ŵ 
				}
			}
		}
		for (int x = 0; x < subin; x++) {
			for (int y = 0; y < m; y++) {
				ice[x][y] = max(0, ice[x][y] - vis[x][y]); // �ش� ������ ���̿��� �湮�� ��ŭ�� ���ָ�
				// �ϳ⿡ �پ�� ���̸� ����� �� ����
			}
		}
		year++; // ���̸� �ٿ����� 1���� ������ 
		for (int x = 0; x < subin; x++) {
			fill(vis[x], vis[x] + m, 0); //vis �迭�� �ٽ� �ʱ�ȭ
		}
		int check = status(); //���� Ȯ�� �Լ�, ������ �� ���� �̻����� �и��Ǿ����� Ȯ�� 

		for (int x = 0; x < subin; x++) {
			fill(vis[x], vis[x] + m, 0);
		}
		if (check == 0) {
			cout << 0;
			return 0;
		}
		else if (check == 1) continue;
		else break; //������ �и��Ǿ��� ��� �ݺ��� ���� 
	}
	cout << year; // �� �� �ҿ�Ǿ����� ���
	return 0;
}