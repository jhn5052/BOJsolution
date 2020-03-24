#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int N;
int map[21][21];
queue<int> q;
int ans = 0;

void play(int a){
  if(a == 0){
    for(int j = 0; j < N; j++){
      for(int i = 0; i < N; i++){
        if(map[i][j]){
          q.push(map[i][j]);
          map[i][j] = 0;
        }
      }

      int k = 0;
      while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(map[k][j] == 0){
          map[k][j] = cur;
        }
        else if(map[k][j] == cur){
          map[k][j] *= 2;
          k += 1;
        }
        else{
          k += 1;
          map[k][j] = cur;
        }
      }
    }
  }

  else if(a == 1){
    for(int j = 0; j < N; j++){
      for(int i = N-1; i >= 0; i--){
        if(map[i][j]){
          q.push(map[i][j]);
          map[i][j] = 0;
        }
      }
      int k = N-1;
      while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(map[k][j] == 0){
          map[k][j] = cur;
        }
        else if(map[k][j] == cur){
          map[k][j] *= 2;
          k -= 1;
        }
        else{
          k -= 1;
          map[k][j] = cur;
        }
      }
    }
  }

  else if(a == 2){
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        if(map[i][j]){
          q.push(map[i][j]);
          map[i][j] = 0;
        }
      }

      int k = 0;
      while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(map[i][k] == 0){
          map[i][k] = cur;
        }
        else if(map[i][k] == cur){
          map[i][k] *= 2;
          k += 1;
        }
        else{
          k += 1;
          map[i][k] = cur;
        }
      }
    }
  }

  else{
    for(int i = 0; i < N; i++){
      for(int j = N-1; j >= 0; j--){
        if(map[i][j]){
          q.push(map[i][j]);
          map[i][j] = 0;
        }
      }

      int k = N-1;
      while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(map[i][k] == 0){
          map[i][k] = cur;
        }
        else if(map[i][k] == cur){
          map[i][k] *= 2;
          k--;
        }
        else{
          k--;
          map[i][k] = cur;
        }
      }
    }
  }
}


void DFS(int cnt){
  if(cnt == 5){
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        ans = max(ans, map[i][j]);
      }
    }
    return;
  }

  int tmp[21][21];
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      tmp[i][j] = map[i][j];
    }
  }
  for(int i = 0; i < 4; i++){
    //0-상, 1-하, 2-좌, 3-우
    play(i);
    DFS(cnt+1);
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        map[i][j] = tmp[i][j];
      }
    }
  }
}

int main(){
  cin >> N;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> map[i][j];
    }
  }
  DFS(0);
  cout << ans << '\n';
  return 0;
}
