#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int r, c;
char map[51][51];
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int ans = 0;

typedef struct info {
   int y, x, cnt;
}info;


bool isRange(int y, int x) {
   if (y < 0 || x < 0 || y >= r || x >= c) {
      return false;
   }
   return true;
}


void BFS(int r, int c) {
   bool visited[51][51];
   memset(visited, false, sizeof(visited));
   queue <info> q;
   visited[r][c] = true;
   q.push({ r, c, 0 });
   bool flag = false;

   while (!q.empty()) {
      int y = q.front().y;
      int x = q.front().x;
      int cnt = q.front().cnt;
      q.pop();
      flag = false;
      for (int i = 0; i < 4; i++) {
         int ny = y + dir[i][0];
         int nx = x + dir[i][1];
         if (!visited[ny][nx] && isRange(ny, nx) && map[ny][nx] == 'L') {
            q.push({ ny, nx, cnt+1 });
            visited[ny][nx] = true;
            flag = true;
         }
      }
      if (flag == false) {
         ans = max(ans, cnt);
      }
   }
}

int main() {
   cin >> r >> c;
   for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
         cin >> map[i][j];
      }
   }
   for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
         if (map[i][j] != 'W') {
            BFS(i, j);
         }
      }
   }
   cout << ans << '\n';
   return 0;
}
