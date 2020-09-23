#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
#define MAX 22

int N, d1, d2, K;
int order[MAX] = { 0 };
int DP[MAX][MAX][MAX];
int mv_cnt = 0;

int Solve(int idx, int a, int b){
    //index 넘어가면 재귀 끝내기
    if(idx > K){
        return 0;
    }
    //해당 DP가 값이 -1이 아닌지 확인
    int &res = DP[idx][a][b];
    if(res != -1){
        return res;
    }

    //해당 DP가 -1인경우 -> 값 구하기
    int door = order[idx];
    int right = abs(door-b) + Solve(idx + 1, a, door);
    int left = abs(door-a) + Solve(idx + 1, door, b);
    res = min(right, left);

    return res;
}

int main(){
    //input
    cin >> N;
    cin >> d1 >> d2;
    cin >> K;
    for(int i = 1; i <= K; i++){
        cin >> order[i];
    }
    
    //DP 메모이제이션
    memset(DP, -1, sizeof(DP));
    mv_cnt = Solve(1, d1, d2);
    cout << mv_cnt << '\n';
    return 0;
}