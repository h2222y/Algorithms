#include <iostream>
#include <queue>
#include <utility>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define X first
#define Y second

int map[27][27]; // ������ �� ǥ��
int vis[27][27]; // �� ���� ���� ǥ�� 
string str[27]; // �Է� �� �ٷ� �ޱ� ���� string 
int dx[4] = { 0,0,-1,1 }; // ���� �迭 
int dy[4] = { -1,1,0,0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n; // ������ ���� �Է¹��� nxn
	for (int x = 0; x < n; x++) {
		cin >> str[x];
		for (int y = 0; y < n; y++) {
			map[x][y] = str[x][y] - '0'; //������ �� ǥ�� 
		}
	}
	int t = 1; //������ ��ȣ ���̱�
	vector<int> ans; // ������������ ���� �� ����ϱ� ���� ����
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			if (map[x][y] == 0 || vis[x][y] !=0)continue; // ������ ���ų� �̹� �湮�� ���� ����
			queue<pair<int, int>> Q; //bfs
			Q.push({ x,y });
			vis[x][y] = t;
			int cnt = 1; // ���� �� ����
			while (!Q.empty()) {
				auto cur = Q.front();
				Q.pop();
				for (int i = 0; i < 4; i++) {
					int nx = cur.X + dx[i];
					int ny = cur.Y + dy[i];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue; // ���� ������� üũ
					if (vis[nx][ny] != 0) continue; // �̹� �湮�� ���� ����
					if (map[nx][ny] != 1) continue; // ������ �ƴ� ���� ���� 
					Q.push({ nx,ny });
					vis[nx][ny] = t;
					cnt++;
				}
			}
			t++;
			ans.push_back(cnt); // ���� �� ����� ���� ���Ϳ� �� �ֱ�
		}
	}
	sort(ans.begin(), ans.end()); // �������� ����
	cout << t-1 << "\n"; //�������� t�� �����߱� ������ -1����
	for (int i : ans)
		cout << i << "\n"; // ������������ �� ���
	return 0; 
}