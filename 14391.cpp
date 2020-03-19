#include<iostream>
#include<cstdio>
using namespace std;

int N, M;
int map[4][4];
bool visit[4][4] = { false };
int result = 0;

int Cal(){
  int ans = 0;
  for(int r = 0; r < N; r++){
    int tmp = 0;
    for(int c = 0; c < M; c++){
      if(visit[r][c]){
        tmp = (tmp * 10) + map[r][c];
      }
      else{
        ans += tmp;
        tmp = 0;
      }
    }
    ans += tmp;
  }

  for(int c = 0; c < M; c++){
    int tmp = 0;
    for(int r = 0; r < N; r++){
      if(!visit[r][c]){
        tmp = (tmp * 10) + map[r][c];
      }
      else{
        ans += tmp;
        tmp = 0;
      }
    }
    ans += tmp;
  }

  return ans;
}


void DFS(int y, int x){
  if(y == N){
    int tmp = Cal();
    result = result > tmp ? result : tmp;
    return;
  }
  if(x == M){
    DFS(y+1, 0);
    return;
  }
  visit[y][x] = true;
  DFS(y, x+1);
  visit[y][x] = false;
  DFS(y, x+1);
}


int main(){
  scanf("%d %d", &N, &M);
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      scanf("%1d", &map[i][j]);
    }
  }
  if(N == 1 && M == 1){
    printf("%d\n", map[0][0]);
    return 0;
  }

  for(int A = 0; A < (1<<N*M); A++){
    int ans = 0;
    for(int i = 0; i < N; i++){

    }
  }

  DFS(0, 0);

  printf("%d\n", result);
  return 0;
}