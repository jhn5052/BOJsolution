#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX 987654321

typedef struct info{
  int y, x, d, cnt;
}info;
int W, H;
int Sr, Sc, Er, Ec;
char map[101][101];
int visit[101][101];
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; 
//N, W, E, S
queue<info> q;

void BFS(){
  while(!q.empty()){
    int y = q.front().y;
    int x = q.front().x;
    int d = q.front().d;
    int cnt = q.front().cnt;
    int nd = (d+2 > 3) ? (d+2%4) : d+2;
    q.pop();
    for(int i = 0; i < 4; i++){
      //NWES
      int ny = y + dir[i][0];
      int nx = x + dir[i][1];
      if(ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
      if(i == nd || map[ny][nx] == '*') continue;
      if(d == i && visit[ny][nx] >= cnt){
        q.push({ny, nx, d, cnt});
        visit[ny][nx] = cnt;
      }
      else if(d != i && visit[ny][nx] >= cnt + 1){
        q.push({ny, nx, i, cnt+1});
        visit[ny][nx] = cnt+1;
      }
    }
  }
}

int main(){
  cin >> W >> H;
  bool flag = false;
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      visit[i][j] = MAX;
    }
  }
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      cin >> map[i][j];
      if(flag == true && map[i][j] == 'C'){
        Er = i;
        Ec = j;
      }
      if(flag == false &&map[i][j] == 'C'){
        flag = true;
        Sr = i;
        Sc = j;
        for(int k = 0; k < 4; k++){
          q.push({i, j, k, 0});//동서남북
       }
      }
    }
  }
  BFS();
  cout << visit[Er][Ec] << '\n';
  return 0;
}
