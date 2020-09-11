#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define MAX 17

int N, M, D;
int map[MAX][MAX];
int tmp[MAX][MAX];
int ans = 0;

void Check(int idx){
    for(int d = 1; d <= min(D, N); d++){
        for(int i = max(0, idx-d+1); i <= min(M-1, idx+d-1); i++){
            int k = N-abs(d - abs(idx-i));
            if(tmp[k][i] == 1 || tmp[k][i] == -1){
                tmp[k][i] = -1;
                return;
            }
        }
    }
}

int Game(){
    int attack = 0;
    int total = 0;
    //복사
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            tmp[i][j] = map[i][j];
        }
    }

    while (total < N)
    {
        //턴한번 시도, 적 하나 공격
        for(int i = 0; i < M; i++){
            if(map[N][i] == 2){
                Check(i);
            }
        }

        //턴이 끝난 후 공격 당한 애들 처리
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(tmp[i][j] == -1){
                    tmp[i][j] = 0;
                    attack++;
                }
            }
        }

        total++;
        //땡기기
        for(int i = N-1; i >= 1; i--){
            for(int j = 0; j < M; j++){
                tmp[i][j] = tmp[i-1][j];
            }
        }
        for(int j = 0; j < M; j++){
            tmp[0][j] = 0;
        }
    }
    return attack;
}

//궁수 위치 구하기 -> 백트레킹
void Solve(int idx, int cnt){
    //궁수 모두 자리 구했을 때
    if(cnt == 3){
        //맵 돌면서 적과 거리 구해서 죽일 수 있는지 확인
        ans = max(ans, Game());
        return;
    }

    //궁수 자리 아직 모두 구하지 않았을 때
    else{
        for(int i = idx; i < M; i++){
            if(map[N][i] == 0){
                map[N][i] = 2;
                Solve(i, cnt+1);
                map[N][i] = 0;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //input
    cin >> N >> M >> D;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
        }
    }

    //N+1번행에 성 존재 -> 궁수 3명 배치
    for(int i = 0; i < M; i++){
        map[N][i] = 0;
    }

    Solve(0, 0);  
    cout << ans << '\n'; 
    return 0;
}