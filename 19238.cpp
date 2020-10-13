#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef struct rider{
    int y, x;
    int dest_y, dest_x;
}Rider;

typedef struct info{
    int y, x;
    int index; //손님 인덱스 번호
    int dist; //거리
}Info;

typedef struct taxi{
    int y, x;
    int move;
    int left_oil;
}Taxi;

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int map[21][21] = { 0 };
bool visited[21][21] = { false };
vector<Rider> v;
int N, M, oil;
int sy, sx; //taxi 위치

bool cmp(Info a, Info b){
    //거리가 짧은애
    if(a.dist == b.dist){
        if (a.y == b.y)
        {
            return a.x < b.x;
        }
        return a.y < b.y;
    }
    return a.dist < b.dist;
}

//현재 갈 수 있는 거리 중 제일 우선순위 높은 곳으로 가기
int FindRider(){
    memset(visited, false, sizeof(visited));
    queue<Taxi> q;
    q.push({sy, sx, 0, oil});
    visited[sy][sx] = true;
    vector<Info> possi; //현재 기름으로 갈수 있는 곳
    while(!q.empty()){
        int curY = q.front().y;
        int curX = q.front().x;
        int mv = q.front().move;
        int leftOil = q.front().left_oil;
        q.pop();

        //현재 위치의 인덱스가 1이상일때 -> 손님 만난 경우
        if(map[curY][curX] >= 1){
            possi.push_back({curY, curX, map[curY][curX], mv});
        }
        //연료 바닥
        else if(leftOil == 0){
            continue;
        }
        for(int i = 0; i < 4; i++){
            int nextY = curY + dir[i][0];
            int nextX = curX + dir[i][1];
            if(nextY >= 0 && nextX >= 0 && nextY < N && nextX < N){
                if (map[nextY][nextX] != -1 && !visited[nextY][nextX]){
                    visited[nextY][nextX] = true;
                    q.push({nextY, nextX, mv+1, leftOil-1});
                }
            }
        }
    }
    //갈 수 있는 곳이 없는 경우
    if(possi.size() == 0){
        return -1;
    }
    //갈 수 있을 때 벡터 소팅해서 최적의 손님을 찾고 연료 증가시키기
    sort(possi.begin(), possi.end(), cmp);
    int mvY = possi[0].y;
    int mvX = possi[0].x;
    map[mvY][mvX] = 0;//선택된 손님은 제외
    oil -= possi[0].dist; //현재 오일에서 이동한만큼 사용된 연료 빼기
    return possi[0].index;
}

//손님의 출발지와 목적지가 있는 인덱스번호
bool BFS(int idx){
    memset(visited, false, sizeof(visited));
    queue<taxi> q;
    int startY = v[idx].y;
    int startX = v[idx].x;
    visited[startY][startX] = true;
    q.push({startY, startX, 0, oil});

    while(!q.empty()){
        int curY = q.front().y;
        int curX = q.front().x;
        int mv = q.front().move;
        int leftOil = q.front().left_oil;
        q.pop();
        
        //목적지 도착
        if(curY == v[idx].dest_y && curX == v[idx].dest_x){
            oil -= mv;
            oil += (mv*2);
            sy = curY;
            sx = curX;
            return true;
        }
        //목적지가 아닐때
        //연료가 없으면 더 못감
        if(leftOil == 0){
            return false;
        }
        for(int i = 0; i < 4; i++){
            int nextY = curY + dir[i][0];
            int nextX = curX + dir[i][1];
            if (nextY >= 0 && nextX >= 0 && nextY < N && nextX < N)
            {
                if (map[nextY][nextX] != -1 && !visited[nextY][nextX])
                {
                    visited[nextY][nextX] = true;
                    q.push({nextY, nextX, mv + 1, leftOil - 1});
                }
            }
        }
    }
    return false;
}

int main(){
    cin >> N >> M >> oil;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
            if(map[i][j] == 1){
                map[i][j] = -1;
            }
        }
    }
    cin >> sy >> sx; //taxi
    sy -= 1;
    sx -= 1;

    //index번호 1부터 시작
    int tx, ty, ex, ey;
    v.push_back({0, 0});
    for(int i = 1; i <= M; i++){
        cin >> ty >> tx >> ey >> ex;
        ty -= 1;
        tx -= 1;
        ey -= 1;
        ex -= 1;
        map[ty][tx] = i;
        v.push_back({ty, tx, ey, ex});
    }

    bool flag = false;
    for(int i = 0; i < M; i++){
        //현재 남은 오일로 갈 수 있는 위치 찾기(여러개중에 행과 열을 따져봐야함)
        int idx = FindRider();
        if(idx == -1){
            flag = true;
            break;
        }
        //목적지로 이동
        int ans = BFS(idx);
        if(!ans){
            flag = true;
            break;
        }
    }
    if(flag){
        cout << -1 << '\n';
    }
    else{
        cout << oil << '\n';
    }
    return 0;
}