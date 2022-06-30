#include <iostream>
#include <queue>
#include <utility>
#include <string>
using namespace std;
#define X first
#define Y second

int map[1003][1003];
int visfire[1003][1003];
int visSang[1003][1003];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
string str[1003];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T; // ���� �� �Է�
	for (int tc = 0; tc < T; tc++)
	{
		bool escape = false; // Ż�� �����ߴ��� ���� Ȯ��
		int w, h;
		cin >> w >> h; //���̿� ���� �Է�
		for (int i = 0; i < h; i++) { //���̺� �Ұ� ������� �湮 ���� �ʱ�ȭ (���ɸ��� �ʱ�ȭ����)
			fill(visfire[i], visfire[i] + w, 0);
			fill(visSang[i], visSang[i] + w, 0);

		}
		queue<pair<int, int>> fireQ; //�� ť
		queue<pair<int, int>> SangQ; //����� ť
		for (int i = 0; i < h; i++) {
			cin >> str[i];
		} //���ڿ��� �Է¹���

		for (int x = 0; x < h; x++) {
			for (int y = 0; y < w; y++) {
				if (str[x][y] == '*') { //�� ������ �ֱ�
					fireQ.push({ x,y });
					visfire[x][y] = 1;
				}
				else if (str[x][y] == '@') { // ����� ������ �ֱ�
					SangQ.push({ x,y });
					visSang[x][y] = 1;
				}
				else if (str[x][y] == '#') { //���϶� -1 �ֱ�
					map[x][y] = -1;
				}
				else map[x][y] = 0; //�ٸ� ��� 0 �ֱ�
			}
		}
		while (!fireQ.empty()) { // �� bfs
			auto cur = fireQ.front();
			fireQ.pop();
			for (int i = 0; i < 4; i++) {
				int nx = cur.X + dx[i];
				int ny = cur.Y + dy[i];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue; //���� ����� �Ұ���
				if (map[nx][ny]==-1) continue; // ���� ��� ��� ����
				if (visfire[nx][ny]!=0) continue; // visfire�� 0�� ��쿡�� �̵� ����
				visfire[nx][ny] = visfire[cur.X][cur.Y] + 1;
				fireQ.push({ nx,ny });
			}
		}

		while (!SangQ.empty() && !escape) { //����� bfs Q�� ���� �ʾ������� ������� ���� ����
			auto cur = SangQ.front();
			SangQ.pop();
			for (int i = 0; i < 4; i++) {
				int nx = cur.X + dx[i];
				int ny = cur.Y + dy[i];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w) { //������ ����� �������
					cout << visSang[cur.X][cur.Y] << "\n"; //����Ҷ� �ð� ���
					escape = true; // bfs Ż��
					break;
				}
				if (map[nx][ny] == -1)continue; // ���ΰ�� �������
				if (visSang[nx][ny] != 0) continue; // visSang�� 0�� ��츸 ����
				if (visfire[nx][ny] != 0 && visfire[nx][ny] <= visSang[cur.X][cur.Y]+1) continue; //���� ���� �����Ѱ�쳪 ���� �����ϸ� �Ұ��� 
				visSang[nx][ny] = visSang[cur.X][cur.Y] + 1;
				SangQ.push({ nx,ny });
			}
		}
		if (!escape) cout << "IMPOSSIBLE\n"; //������� ���ϸ� impossible ���
	}

		return 0;
}