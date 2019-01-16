#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int dir_y[8] = { 1,2,1,2,-1,-2,-2,-1 };
int dir_x[8] = { -2,-1,2,1,-2,-1,1,2 };

int main() {
	int T;//testcase
	int x, y;//시작하는 곳
	int L;//체스판 길이
	int n_x, n_y;
	int a, b;
	int cnt;
	cin >> T;
	for (int testcase = 0; testcase < T; testcase++) {
		int cur[301][301] = { 0 }; //체스판 상태
		queue<pair<int, pair<int, int> > > q;
		cin >> L;
		cin >> x >> y;//나이트가 현재 있는 칸
		cin >> a >> b;//나이트가 이동하려는 칸
		q.push(make_pair(0, make_pair(y, x)));//카운트, 좌표y, 좌표 x
		cur[y][x]++;
		while (!q.empty()) {
			int ty = q.front().second.first;
			int tx = q.front().second.second;
			cnt = q.front().first;
			q.pop();
			if (tx == a && ty == b) {//이동하고자 하는 점
				cout << cnt << '\n';
				break;
			}
			for (int i = 0; i < 8; i++) {
				n_x = tx + dir_x[i];
				n_y = ty + dir_y[i];
				if (n_y < 0 || n_y >= L || n_x < 0 || n_x >= L) {
					continue;
				}
				if (cur[n_y][n_x]) {
					continue;
				}
				cur[n_y][n_x]++;
				q.push(make_pair(cnt + 1, make_pair(n_y, n_x)));
			}
		}
	}
	return 0;
}
