#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct spin{
    int r, c, s;
}Spin;

int N, M, K;
int A[51][51];
int A_tmp[51][51];
int ans = 987654321;
vector<Spin> v;
vector<int> num;

void Update(){
  int tmp = 0;
  for(int i = 1; i <= N; i++){
    tmp = 0;
    for(int j = 1; j <= M; j++){
      tmp += A_tmp[i][j];
    }
    ans = min(ans, tmp);
  }
  return;
}

void Solve(int idx){//회전해야하는 Spin의 인덱스
  int vr = v[idx].r;
  int vc = v[idx].c;
  int vs = v[idx].s;
  
  int by = vr - vs;
  int bx = vc - vs;

  int ey = vr + vs;
  int ex = vc + vs;

  
  //같아질때 나가야됨
  while(!(by == vr && bx == vc)){
    int tmp = A_tmp[by][bx];
    //1. 맨 왼쪽줄 움직이기
    for(int i = by; i <= ey-1; i++){
      A_tmp[i][bx] = A_tmp[i+1][bx];
    }

    //2. 맨 아랫줄 움직이기
    for(int i = bx; i <= ex-1; i++){
      A_tmp[ey][i] = A_tmp[ey][i+1];
    }

    //3. 맨 오른쪽 줄 움직이기
    for(int i = ey; i >= by+1; i--){
      A_tmp[i][ex] = A_tmp[i-1][ex];
    }

    //4. 맨 윗줄 움직이기
    for(int i = ex; i >= bx+1; i--){
      A_tmp[by][i] = A_tmp[by][i-1]; 
    }
    A_tmp[by][bx+1] = tmp;
    by++;
    bx++;
    ey--;
    ex--;
  }
}

int main(){
  cin >> N >> M >> K;
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= M; j++){
      cin >> A[i][j];
    }
  }
  for(int i = 0; i < K; i++){
    Spin tmp;
    cin >> tmp.r >> tmp.c >> tmp.s;
    v.push_back(tmp);
    num.push_back(i);
  }

  //순열로 회전 해보고 최솟값 뽑아내기
  do{
    //원래 배열 복사
    for(int i = 1; i <= N; i++){
      for(int j = 1; j <= M; j++){
        A_tmp[i][j] = A[i][j];
      }
    }
    //순열에 맞게 회전
    for(int i = 0; i < K; i++){
      Solve(num[i]);
    }
    //다 돌리고 나서 최솟값 갱신하기
    Update();
  }while(next_permutation(num.begin(), num.end()));
  
  cout << ans << '\n';
  return 0;
}

