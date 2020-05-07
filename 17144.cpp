#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int R, C, T;
int map[51][51];
int visit[51][51];
queue<pair<int, int> > q;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int air[2]; //공기청정기 y위치 - x는 매번 0
int ans = 0;

void Spread(){
    memset(visit, 0, sizeof(visit));
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        int cnt = 0; //퍼지는 방향 개수
        int mnt = map[y][x] / 5; //확산 되는 양
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];
            if(ny < 0 || nx < 0 || ny >= R || nx >= C){
                continue;
            }
            else if(map[ny][nx] == -1){
                continue;
            }
            else{//확산 가능
                cnt++;
                visit[ny][nx] += mnt;
            }
        }
        map[y][x] = map[y][x] - (mnt * cnt);
    }
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(visit[i][j] > 0){
                map[i][j] += visit[i][j];
            }
        }
    }
}

void Up_air(){
    int y = air[0];
    //left
    for(int i = y-1; i > 0; i--){
        map[i][0] = map[i-1][0];
    }
    //up
    for(int i = 0; i < C-1; i++){
        map[0][i] = map[0][i+1];
    }
    //right
    for(int i = 0; i < y; i++){
        map[i][C-1] = map[i+1][C-1];
    }
    //down
    for(int i = C-1; i > 1; i--){
        map[y][i] = map[y][i-1];
    }
    map[y][1] = 0;
}

void Down_air(){
    int y = air[1];
    //left
    for(int i = y+1; i < R-1; i++){
        map[i][0] = map[i+1][0];
    }
    //down
    for(int i = 0; i < C-1; i++){
        map[R-1][i] = map[R-1][i+1];
    }
    //right
    for(int i = R-1; i > y; i--){
        map[i][C-1] = map[i-1][C-1];
    }
    //up
    for(int i = C-1; i > 1; i--){
        map[y][i] = map[y][i-1];
    }
    map[y][1] = 0;
}

int main(){
    //input
    cin >> R >> C >> T;
    bool flag = false;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> map[i][j];
            if(flag == false && map[i][j] == -1){
                flag = true;
                air[0] = i; // first y;
            }
            else if(map[i][j] == -1 && flag == true){
                air[1] = i; //second y
            }
        }
    }

    while(T--){
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if(map[i][j] > 0){
                    q.push(make_pair(i, j));
                }
            }
        }
        Spread();
        //2. 공기청정기 순환
        Up_air();
        Down_air();
    }

    //미세먼지 총 합
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(map[i][j] > 0)
                ans += map[i][j];
        }
    }
    cout << ans << '\n';
    return 0;
}
