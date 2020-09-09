#include <iostream>
#include <queue>
#include <limits.h>
#include <algorithm>
using namespace std;

typedef struct info{
    int r, c, dir;
}Info;

int M, N;
int map[102][102];
int visited[102][102][5];
int Dir[5][2] = {{0, 0}, {4, 3}, {3, 4}, {1, 2}, {2,1}}; //turnLeft, turnRight
int Go[5][2] = {{0,0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // 0, 동, 서, 남, 북
int startR, startC, startDir;
int destR, destC, destDir;

bool isRange(int y, int x){
    if(y > 0 && x > 0 && y <= M && x <= N){
        return true;
    }
    return false;
}

int Solve(){
    queue<Info> q;
    visited[startR][startC][startDir] = 0;
    q.push({startR, startC, startDir});
    while(!q.empty()){
        int cur_y = q.front().r;
        int cur_x = q.front().c;
        int d = q.front().dir;
        q.pop();
        if(cur_y == destR && cur_x == destC && d == destDir){
            return visited[cur_y][cur_x][d];
        }
        //turn left, turn right(왼쪽, 오른쪽) 한번씩 돌기 -> visited[][][] += 1
        int turnLeft = Dir[d][0];
        int turnRight = Dir[d][1];
        if(visited[cur_y][cur_x][turnLeft] > visited[cur_y][cur_x][d] + 1){
            visited[cur_y][cur_x][turnLeft] = visited[cur_y][cur_x][d] + 1;
            q.push({cur_y, cur_x, turnLeft});
        }
        if (visited[cur_y][cur_x][turnRight] > visited[cur_y][cur_x][d] + 1)
        {
            visited[cur_y][cur_x][turnRight] = visited[cur_y][cur_x][d] + 1;
            q.push({cur_y, cur_x, turnRight});
        }

        //Go K (1~ map[r][c]==1 전까지 직진)
        int next_y = cur_y;
        int next_x = cur_x;
        for(int i = 0; i < 3; i++){
            next_y += Go[d][0];
            next_x += Go[d][1];

            //map이 1이라서 더 못가거나 못하거나 범위를
            if(map[next_y][next_x] == 1 || !isRange(next_y, next_x)){
                break;
            }
            if(visited[next_y][next_x][d] > visited[cur_y][cur_x][d] + 1){
                visited[next_y][next_x][d] = visited[cur_y][cur_x][d] + 1;
                q.push({next_y, next_x, d});
            }
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> M >> N;
    for(int i = 1; i <= M; i++){
        for(int j = 1; j <= N; j++){
            cin >> map[i][j];
            for(int k = 1; k < 5; k++){
                visited[i][j][k] = INT_MAX;
            }
        }   
    }
    cin >> startR >> startC >> startDir;
    cin >> destR >> destC >> destDir;
    int ans = Solve();
    cout << ans << '\n';
    return 0;
}