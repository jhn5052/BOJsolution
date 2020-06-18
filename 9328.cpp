//9328열쇠
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <bitset>
using namespace std;

typedef struct info {
	int r, c;
	int key;
}info;

int H, W, T;
vector<vector<char>>map;
bool visited[104][104] = { false };
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int cnt = 0;


void BFS(int r, int c, string k) {
	queue<info> q;
	visited[r][c] = true;
	int s = 0x0;

	//default key
	if (k != "0") {
		for (int i = 0; i < k.size(); i++) {
			int tmp = int(k[i] - 'a') + 1;
			s |= (1 << tmp);
		}
	}
	//cout << bitset<27>(s) << '\n';
	q.push({ r, c,  s});


	while (!q.empty()) {
		int y = q.front().r;
		int x = q.front().c;
		int k = q.front().key;
		q.pop();

		//print
		/*
		cout  << y << " " << x << '\n';
		cout << "map :" << char(map[y][x]) << '\n';
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) {
				if (visited[i][j])	cout << "#" << ' ';
				else	cout << "." << ' ';
			}
			cout << '\n';
		}
		*/
		for (int i = 0; i < 4; i++) {
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];

			//거르는 조건
			if (ny < 0 || nx < 0 || ny > H+1 || nx > W+1)	continue;
			if (visited[ny][nx] || map[ny][nx] == '*')	continue;

			//이동할 수 있는 경우
			//1. 빈칸
			if (map[ny][nx] == '.') {
				q.push({ ny, nx, k});
				visited[ny][nx] = true;
			}
			//2. 열쇠
			else if (map[ny][nx] >= 'a' && map[ny][nx] <= 'z') {
				int tmp = map[ny][nx] - 'a' + 1;
				if (!(k & (1 << tmp))){
					memset(visited, false, sizeof(visited));
					k |= (1 << tmp);

					//큐 비워주기
					while (!q.empty()) {
						q.pop();
					}

					visited[ny][nx] = true;
					q.push({ ny, nx, k });
				}

				else {
					visited[ny][nx] = true;
					q.push({ ny, nx, k });
				}
				
			}

			//3. 문 - 열쇠가 있을 때
			else if (map[ny][nx] >= 'A' && map[ny][nx] <= 'Z') {
				int tmp = map[ny][nx] - 'A' + 1;
				if ((k & (1 << tmp)) > 0) {
					visited[ny][nx] = true;
					q.push({ ny, nx, k });
				}
			}

			//4.문서일때
			else if (map[ny][nx] == '$') {
				cnt += 1;
				visited[ny][nx] = true;
				map[ny][nx] = '.';
				q.push({ ny, nx, k });
			}
		}
	}
	return;
}

int main() {
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		cin >> H >> W;
		//init
		memset(visited, false, sizeof(visited));
		map = vector<vector<char> >(H + 2, vector<char>(W + 2, '.'));
		cnt = 0;
		//map
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) {
				cin >> map[i][j];
			}
		}

		//input key
		string str;
		cin >> str;

		//가장자리
		BFS(0, 0, str);

		cout << cnt << '\n';
	}

	return 0;
}
