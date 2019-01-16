//세로 R칸, 가로 C칸, 각 칸에는 대문자 알파벳이 하나씩 적혀있음
//한번 지난 대문자 칸은 두번 지날 수 없음 -> 지난 알파벳은 표시해두어야함
#include<iostream>
#include<algorithm>
using namespace std;
int alph[26] = { 0 }; //이미 지난 대문자는 1로 저장
char input[21][21];
int dir_y[4] = { 1,-1,0,0 };
int dir_x[4] = { 0,0,1,-1 };
int new_x, new_y;
int R, C;

int Check(int x, int y) {
	int result = 0;
	for (int i = 0; i < 4; i++) {
		new_x = x + dir_x[i];
		new_y = y + dir_y[i];
		if (new_x >= 0 && new_x < R && new_y >= 0 && new_y < C) {
			int a = input[new_x][new_y];
			if (alph[a - 65] == 0) {
				alph[a - 65] = 1;
				int b = Check(new_x, new_y);
				result = max(result, b);
				alph[a - 65] = 0;
			}
		}
	}
	return result + 1;
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> input[i];
	}
	alph[input[0][0] - 65] = 1;
	cout << Check(0,0) << '\n';
	return 0;
}