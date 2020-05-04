#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


typedef struct info{
  int y, x, cctv;
}info;

int N, M;
int ans = 987654321;
int map[9][9];
vector<info> v;
int rot[6] = {0, 4, 2, 4, 4, 1}; // rotation rate

void Go(int dir, int idx){
  int d = dir % 4;
  int cur_y = v[idx].y;
  int cur_x = v[idx].x;

  switch(d){
    case 0:
      //right
      for(int i = cur_x+1; i < M; i++){
        if(map[cur_y][i] == 6){
          break;
        }
        map[cur_y][i] = 9;
      }
      break;
    case 1:
      //up
      for(int i = cur_y-1; i >= 0; i--){
        if(map[i][cur_x] == 6){
          break;
        }
        map[i][cur_x] = 9;
      }
      break;
    case 2:
      //left
      for(int i = cur_x-1; i >= 0; i--){
        if(map[cur_y][i] == 6){
          break;
        }
        map[cur_y][i] = 9;
      }
      break;
    case 3:
      //down
      for(int i = cur_y+1; i < N; i++){
        if(map[i][cur_x] == 6){
          break;
        }
        map[i][cur_x] = 9;
      }
      break;
  }
}


void DFS(int depth, int end){
  if(depth == end){
    int tmp = 0;
    for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
        if(map[i][j] == 0){
          tmp++;
        }
      }
    }
    ans = min(ans, tmp);
    return;
  }
  int t_map[9][9];
  int c_num = v[depth].cctv;
  for(int i = 0; i < rot[c_num]; i++){
    for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
        t_map[i][j] = map[i][j];
      }
    }
    switch(c_num){
      case 1: //1번 카메라
        Go(i, depth);
        break;
      case 2: //2번 카메라
        Go(i, depth);
        Go(2 + i, depth);
        break;
      case 3: //3번 카메라
        Go(1 + i, depth);
        Go(2 + i, depth);
        break;
      case 4: //4번 카메라
        Go(i, depth);
        Go(1 + i, depth);
        Go(2 + i, depth);
        break;
      case 5: //5번 카메라
        Go(i, depth);
        Go(1 + i, depth);
        Go(2 + i, depth);
        Go(3 + i, depth);
        break;
    }
    DFS(depth+1, end);
    for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
        map[i][j] = t_map[i][j];
      }
    }
  }
}

int main() {
  cin >> N >> M;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      cin >> map[i][j];
      if(map[i][j] >= 1 && map[i][j] <= 5){
        v.push_back({i, j, map[i][j]});
      }
    }
  }
  DFS(0, v.size());
  cout << ans << '\n';
  return 0;
}
