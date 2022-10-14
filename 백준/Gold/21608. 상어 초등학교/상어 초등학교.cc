#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
struct Student {
	int mynum;
	int lover[4];
}; // 학생의 번호 정보와 좋아하는 학생의 정보를 저장 
struct Position {
	int x;
	int y;
	int Nearly_Empty;
	int Nearly_Lover;
};
// 현재 학생의 행,열 정보와 인접한 빈칸의 개수
// 인접한 좋아하는 사람의 정보를 저장한다.
vector<Student> stu; // Student를 자료형으로 가지는 벡터
Student Stu_arr[402]; // Student를 자료형으로 가지는 학생 정보 배열
int map[25][25]; // 교실 배열
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void Input() {
	cin >> n;// 교실 크기
	for (int i = 0; i < n * n; i++) { // 학생수는 n*2명
		int num, lov1, lov2, lov3, lov4;
		cin >> num >> lov1 >> lov2 >> lov3 >> lov4;
		stu.push_back({ num,{lov1,lov2,lov3,lov4} });
		// 각 학생의 번호와, 순서, 좋아하는 4명 저장 
		Stu_arr[num].mynum = num;
		Stu_arr[num].lover[0] = lov1;
		Stu_arr[num].lover[1] = lov2;
		Stu_arr[num].lover[2] = lov3;
		Stu_arr[num].lover[3] = lov4;
		// 이후 만족도를 찾을 때 편의성을 위해 배열에도 저장
		
	}
}
bool Comp(Position A, Position B)
{
	if (A.Nearly_Lover >= B.Nearly_Lover) {
		if (A.Nearly_Lover == B.Nearly_Lover) {
			if (A.Nearly_Empty >= B.Nearly_Empty) {
				if (A.Nearly_Empty == B.Nearly_Empty) {
					if (A.x <= B.x) {
						if (A.x == B.x) {
							if (A.y < B.y) {
								return true;
							}
							return false;
						}
						return true;
					}
					return false;
				}
				return true;
			}
			return false;
		}
		return true;
	}
	return false;

}

void SetPosition() {
	for (int i = 0; i < stu.size(); i++) {
		vector<Position> pos; // Position을 자료형으로 가지는 벡터
		int now_student = stu[i].mynum; // 현재 학생의 번호 
		for (int x = 1; x <= n; x++) {
			for (int y = 1; y <= n; y++) {
				if (map[x][y] != 0) continue; // 비어있는 교실인지 확인한다.
				int nearly_friend = 0; // 현재 칸에서 친구 확인
				int nearly_empty = 0; // 현재 칸에서 비어있는 칸 확인 
				for (int k = 0; k < 4; k++) { //이동 
					int nx = x + dx[k];
					int ny = y + dy[k];
					if (nx<1 || nx>n || ny<1 || ny>n)continue;
					if (map[nx][ny] == 0) nearly_empty++; //비어있는 칸 발견
					else { // 비어있지 않다면 
						for (int j = 0; j < 4; j++) {
							int now_friend_num = stu[i].lover[j]; //현재 학생의 좋아하는 친구의 번호
							if (map[nx][ny] == now_friend_num) {
								nearly_friend++; //좋아하는 친구 수 저장 
								break;
							}
						}
					}
				}
				pos.push_back({ x,y,nearly_empty,nearly_friend }); //pos에 모든 학생의 행,열,근처빈칸,근처좋아하는친구 정보 저장
			}
		}
		sort(pos.begin(), pos.end(), Comp); // 조건에 맞는 정렬
		int pos_x = pos[0].x; // 정렬된 pos의 가장 앞의 값에 최적의 자리가 입력된다. 
		int pos_y = pos[0].y; // 정렬된 pos의 가장 앞의 값
		map[pos_x][pos_y] = now_student; // 현재 학생의 번호를 위치에 입력해준다.
	}
}
int Calculate(int satis) {
	if (satis == 0) return 0;
	if (satis == 1) return 1;
	if (satis == 2) return 10;
	if (satis == 3) return 100;
	if (satis == 4) return 1000;
}
int Satisfi() {
	int sum = 0;
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) {
			int now_student = map[x][y];
			int lover = 0;
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx<1 || nx>n || ny<1 || ny>n) continue;
				for(int r=0;r<4;r++){
					int lover_num = Stu_arr[now_student].lover[r];
					if (map[nx][ny] == lover_num) {
						lover++;
						break;
					}
				}
			}
			sum += Calculate(lover);
		}
	}
	return sum;
}

int main() {
	Input();
	SetPosition();
	cout << Satisfi();
	return 0;
}