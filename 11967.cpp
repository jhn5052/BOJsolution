#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
bool room[102][102] = { false };
bool visited[102][102] = { false };
int ans = 0;
int dir[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
vector<pair<int, int> > light[102][102];


void Solve(int r, int c) {
   while(1){
      //새로운 방 불 켰을때 다시 돔
      bool flag = false;
      queue<pair<int, int> > q;
      memset(visited, false, sizeof(visited));
      q.push({ 1, 1 });
      visited[r][c] = true;
      room[r][c] = true;

      while (!q.empty()) {
         int y = q.front().first;
         int x = q.front().second;
         q.pop();

         //스위치 on
         for (int i = light[y][x].size() - 1; i >= 0; i--) {
            int Sa = light[y][x][i].first;
            int Sb = light[y][x][i].second;
            room[Sa][Sb] = true;
            light[y][x].pop_back();//불 스위치 없앰
            flag = true;
         }

         //4방향 탐색 -> 불이 켜지고 방문하지 않은 곳만 탐색
         for (int i = 0; i < 4; i++) {
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];
            if (ny <= 0 || nx <= 0 || ny > N || nx > N)   continue;
            //방문하지 않고, 불이 켜진 경우
            if (!visited[ny][nx] && room[ny][nx]) {
               visited[ny][nx] = true;
               q.push({ ny, nx });
            }

         }
      }
      if (!flag) {
         break;
      }
   }
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   
   cin >> N >> M;
   int a, b, c, d;
   for (int i = 0; i < M; i++) {
      cin >> a >> b >> c >> d;
      light[a][b].push_back({ c,d });
   }

   Solve(1, 1);
   for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
         if (room[i][j])   ans++;
      }
   }
   cout << ans << '\n';
   return 0;
}
