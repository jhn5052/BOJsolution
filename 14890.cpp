#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int N, L, result = 0;
int map[101][101];
bool visit[101];

int Row(int idx){
  int cnt = 1;
  for(int j = 0; j < N-1; j++){
    int sub = map[idx][j+1] - map[idx][j];
    if(sub == 0){
      cnt += 1;
    }
    else if(sub == 1 && cnt >= L){
      cnt = 1;
    }
    else if(sub == -1 && cnt >= 0){
      cnt = -L + 1; //내려가는 경사로 
    }
    else{
      return 0;
    }
  }
  if(cnt >= 0){
    result += 1;
  }
  return 0;
}

int Col(int idx){
  int cnt = 1;
  for(int j = 0; j < N-1; j++){
    int sub = map[j+1][idx] - map[j][idx];
    if(sub == 0){
      cnt += 1;
    }
    else if(sub == 1 && cnt >= L){
      cnt = 1;
    }
    else if(sub == -1 && cnt >= 0){
      cnt = -L + 1; //내려가는 경사로 
    }
    else{
      return 0;
    }
  }
  if(cnt >= 0){
    result += 1;
  }
  return 0;
}


int main(){
  cin >> N >> L;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> map[i][j];
    }
  }
  for(int i = 0; i < N; i++){
    Row(i);
    Col(i);
  }
  cout << result << '\n';
  return 0;
}