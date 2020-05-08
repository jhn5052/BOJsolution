#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int map[21][21];
int visit[21][21];
int ans = 987654321;
int N;
int x, y, d1, d2;

void Line_fill(){
    memset(visit, 0, sizeof(visit));
    for(int i = 0; i <= d1; i++){
        visit[x+i][y-i] = 5;
        visit[x+d2+i][y+d2-i] = 5;
    }
    for(int i = 0; i <= d2; i++){
        visit[x+i][y+i] = 5;
        visit[x+d1+i][y-d1+i] = 5;
    }
    for(int i = 1; i <= N; i++){
        bool flag = false;
        int a;
        for(int j = 1; j <= N; j++){
            if(flag == false && visit[i][j] == 5){
                flag = true;
                a = j;
                continue;
            }
            else if(flag == true && visit[i][j] == 5){
                for(int t = a; t <= j; t++){
                    visit[i][t] = 5;
                }
            }
        }
    }
}

void Solve(int rs, int re, int cs, int ce, int n){
    for(int i = rs; i <= re; i++){
        for(int j = cs; j <= ce; j++){
            if(visit[i][j] != 0 || visit[i][j] == 5){
                continue;
            }
            else{
                visit[i][j] = n;
            }
        }
    }
}

void getSum(){
    int a = 0, b = 0, c = 0, d = 0, e = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(visit[i][j] == 1){
                a += map[i][j];
            }
            else if(visit[i][j] == 2){
                b += map[i][j];
            }
            else if(visit[i][j] == 3){
                c += map[i][j];
            }
            else if(visit[i][j] == 4){
                d += map[i][j];
            }
            else{
                e += map[i][j];
            }
        }
    }
    int result = max(a, max(b, max(c, max(d, e)))) - min(a, min(b, min(c, min(d, e))));
    ans = min(ans, result);
}

int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> map[i][j];
        }
    }
    //기준값 뽑기
    for(int i = 1; i <= N; i++){ //x
        for(int j = 1; j <= N; j++){ // y
            for(int k = 1; k <= N; k++){ // d1
                for(int h = 1; h <= N; h++){ // d2
                    if(i < i+k+h && i+k+h <= N && j-k >= 1 && j-k < j && j < j+h && j+h <= N){
                        x = i;
                        y = j;
                        d1 = k;
                        d2 = h;
                        Line_fill();
                        Solve(1, x+d1-1, 1, y, 1); //1번선거구
                        Solve(1, x+d2, y+1, N, 2); //2번 선거구
                        Solve(x+d1, N, 1, y-d1+d2-1, 3);//3번선거구
                        Solve(x+d2+1, N, y-d1+d2, N, 4);//4번 선거구
                        getSum();
                    }
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
