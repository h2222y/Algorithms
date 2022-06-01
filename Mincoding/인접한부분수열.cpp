#include <Iostream>
#include <string>
using namespace std;
int n; //������ ����
string str; // ���� �Է¹ޱ�

int isSame(int sublen, int sPos) {
	for (int i = sPos; i < sPos + sublen; i++) { // ���� ��ġ���� ������ġ + �κм����� ����
		if (i + sublen >= n) return 0; //���� ��ġ + �κм����� ���̰� n�ʰ��ϸ� �ȵȴ�.
		if (str[i] != str[i + sublen]) return 0; //���� ��ġ ���� ������ �κм��� �������� ������ 0������
	}
	return 1; // ���� ��ġ ���� ������ �κм��� ����� 1����
}

int main() {
	int flag = 0; // ������ �����ϰ� ���� �κм����� �����ϴ��� Ȯ��
	cin >> n; // ������ ���� �Է�
	cin >> str; //��ü ���� �Է�
	for (int sublen = 1; sublen <= n; sublen++) { //1~n���� 1ĭ, 2ĭ ... nĭ���� �κм��� ���ϱ�
		for (int sPos = 0; sPos < n; sPos++) { // 0���� n-1���� ���� ��ġ �����ֱ�
			if (isSame(sublen, sPos))flag = 1; // ������ �κм��� ����� flag�� 1��
		}
	}
	if (flag == 1) cout << "NO";// ������ �κм��� �����ϸ� NO ���
	else cout << "YES"; //������ �κм��� �������� ������ YES ���
	return 0;
}